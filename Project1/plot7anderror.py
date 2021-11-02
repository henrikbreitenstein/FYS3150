import numpy as np
import matplotlib.pyplot as plt
reps=7
#For the relative error
def exactu(x):
    return 1-(1-np.exp(-10))*x -np.exp(-10*x)
maxabs=np.zeros(reps)
maxrel=np.zeros(reps)
nl=np.zeros(reps)
#opens file and loads the coloumns to x and y
for i in range(1, reps):
    n = 10**i
    x, y = np.loadtxt(f'Textfiles/out.txt', unpack=True)
    x2, v = np.loadtxt(f'Textfiles/sol7n{n}.txt', unpack=True)
    #Finds absolute and relative error
    yex=exactu(x2)
    abserr=np.log10(np.abs(yex-v))
    relerr=np.log10(np.abs((yex-v)/yex))
    #Finds the maximum relative error
    print("maxrel", np.amax(relerr[1:n]))
    maxrel[i]=np.max(relerr[1:n])
    maxabs[i]=np.max(abserr[1:n])
    nl[i]=np.log10(n)
    print("n", nl[i])
    #plots it with title and names on axes
    fig = plt.figure(figsize=(8,8))
    ax = plt.axes(xlabel='x', title=f'Exact Solution vs Approx n = {n}')
    plt.ylabel('u',rotation=0)
    ax.plot(x,y, label='Exact')
    ax.plot(x2, v, label='Approx')
    plt.legend()
    plt.savefig(f'plotexap{n}.jpg')
    plt.show()
    fig2=plt.figure(figsize=(8,8))
    ax=plt.axes(xlabel="x", ylabel="Absoulute Error", title=f"Absolute error for n={n}")
    ax.plot(x2, abserr)
    plt.legend()
    plt.savefig(f"abserrn{n}")
    plt.show()
    fig3=plt.figure(figsize=(8,8))
    ax=plt.axes(xlabel="x", ylabel="Relative Error", title=f"Relative error for n={n}")
    ax.plot(x2, relerr)
    plt.legend()
    plt.savefig(f"relerr{n}")
    plt.show()
print("n", np.size(nl), nl)
print("error", np.size(maxrel), maxrel)
fig3=plt.figure(figsize=(8,8))
ax=plt.axes(xlabel="logarithmic description of n", ylabel="max relative error for this n", title=f"Relative error")
ax.plot(nl, maxrel)
plt.legend()
plt.savefig("abserr.png")
plt.show()
fig4=plt.figure(figsize=(8,8))
ax=plt.axes(xlabel="logarithmic description of n", ylabel="max absolute error for this n", title=f"Absolute error")
ax.plot(nl, maxabs)
plt.legend()
plt.savefig("relerr.png")
plt.show()

import numpy as np
import matplotlib.pyplot as plt
reps=5
#For the relative error
def exactu(x):
    return 1-(1-np.exp(-10))*x -np.exp(-10*x)
maxrel=np.zeros(reps)
#opens file and loads the coloumns to x and y
for i in range(1, reps):
    n = 10**i
    x, y = np.loadtxt(f'out.txt', unpack=True)
    x2, v = np.loadtxt(f'sol7n{n}.txt', unpack=True)
    #Finds absolute and relative error
    yex=exactu(x2)
    abserr=np.log10(yex-v)
    relerr=np.log10((yex-v)/yex)
    maxrel=np.max(relerr)
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
    plt.show()
    fig3=plt.figure(figsize=(8,8))
    ax=plt.axes(xlabel="x", ylabel="Relative Error", title=f"Relative error for n={n}")
    ax.plot(x2, relerr)
    plt.legend()
    plt.show()

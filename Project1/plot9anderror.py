import numpy as np
import matplotlib.pyplot as plt
#For the relative error
def exactu(x):
    return 1-(1-np.exp(-10))*x -np.exp(-10*x)

#opens file and loads the coloumns to x and y
for i in range(1, 2):
    n = 10**i
    x, y = np.loadtxt(f'Textfiles/out.txt', unpack=True)
    x2, v = np.loadtxt(f'Textfiles/sol9n{n}.txt', unpack=True)
    #Finds absolute and relative error
    yex=exactu(x2)
    abserr=np.log10(yex-v)
    relerr=np.log10((yex-v)/yex)
    #plots it with title and names on axes
    fig = plt.figure(figsize=(8,8))
    ax = plt.axes(xlabel='x', title=f'Exact Solution vs Approx n = {n}')
    plt.ylabel('u',rotation=0)
    ax.plot(x,y, label='Exact')
    ax.plot(x2, v, label='Approx')
    print("y", y)
    print("v", v)
    plt.legend()
    plt.savefig(f'Images/plotexap{n}.jpg')
    plt.show()
    #Plotting absoulute error
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

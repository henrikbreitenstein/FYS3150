import numpy as np
import matplotlib.pyplot as plt

#opens file and loads the coloumns to x and y
for i in range(1, 5):
    n = 10**i
    x, y = np.loadtxt(f'out.txt', unpack=True)
    x2, v = np.loadtxt(f'sol7n{n}.txt', unpack=True)

    #plots it with title and names on axes
    fig = plt.figure(figsize=(8,8))
    ax = plt.axes(xlabel='x', title=f'Exact Solution vs Approx n = {n}')
    plt.ylabel('u',rotation=0)
    ax.plot(x,y, label='Exact')
    ax.plot(x2, v, label='Approx')
    plt.legend()
    plt.savefig(f'problem7NEW{n}.jpg')
    plt.show()

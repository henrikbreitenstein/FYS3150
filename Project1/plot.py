import numpy as np
import matplotlib.pyplot as plt

#opens file and loads the coloumns to x and y
x, y = np.loadtxt('out.txt', unpack=True)
x2, v = np.loadtxt('solution.txt', unpack=True)

#plots it with title and names on axes
fig = plt.figure(figsize=(8,8))
ax = plt.axes(xlabel='x', title='Exact Solution')
plt.ylabel('u',rotation=0)
ax.plot(x,y, label='Exact')
ax.plot(x2, v, label='Approx')
plt.legend()
plt.show()

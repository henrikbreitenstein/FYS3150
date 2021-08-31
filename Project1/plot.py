import numpy as np
import matplotlib.pyplot as plt

#opens file and loads the coloumns to x and y
f = open('out.txt')
x, y = np.loadtxt(f, unpack=True)

#plots it with title and names on axes
fig = plt.figure(figsize=(8,8))
ax = plt.axes(xlabel='x', title='Exact Solution')
plt.ylabel('u',rotation=0)
ax.plot(x,y)
plt.show()

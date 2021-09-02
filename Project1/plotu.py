import numpy as np
import matplotlib.pyplot as plt

x, v = np.loadtxt('solution.txt', unpack=True)
plt.plot(x, v)
plt.show()

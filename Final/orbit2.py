import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os



eta = np.linspace(-10,10,100)
p = 1.0
M = 2.0
t = 0.5 * np.sqrt(p**3/M) * eta * (1.0 + eta**2/3.0)

x = p * eta
y = 0.5 * p * (1.0 - eta**2)
r = 0.5*p*(1+eta**2)

fig = plt.figure(figsize=[10, 10])
ax = fig.add_subplot(projection='3d')
ax = fig.add_subplot()
# ax.scatter(t,x,y)
ax.scatter(x,y)
ax.set_xlabel('x')
ax.set_ylabel('y')
# ax.set_zlabel('t')
plt.show()

for i in range(len(x)):
    print(t[i], x[i], y[i],r[i])

import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os

def a(x):
    return (1+ x**2)**0.5


aarseth = np.array(pylab.loadtxt("sphere.data"))
inc= np.array(pylab.loadtxt("aarseth/my_20k"),skiprows=1)
x = inc [0][1]
y = inc[0][2]
z = inc[0][3]
u = inc [0][4]
v = inc[0][5]
w = inc[0][6]
x_a = np.array([aarseth[i,0] for i in range(20000)])
y_a = np.array([aarseth[i,1] for i in range(20000)])
z_a = np.array([aarseth[i,2] for i in range(20000)])
dt = 0.5

for i in range(10):
    u = u + 0.5 * dt * ax[i];
    v = v + 0.5 * dt * ay[i];
    w = w + 0.5 * dt * az[i];

for i in range(10):
    x = x + dt * u
    y = y + dt * v
    z = z + dt * w
for i in range(10):
    u = u + 0.5 * dt * ax[i]
    v = v + 0.5 * dt * ay[i]
    w = w + 0.5 * dt * az[i]


print(x_a[69],y_a[69],z_a[69])
for i in range(1,40):
    fig, ax = plt.subplots()

    n_init = 1+ (i-1)*20000;
    n_end  = i*20000;
    l = len(aarseth)
    x_a = np.array([aarseth[i,0] for i in range(n_init+70,n_end,20000)])
    y_a = np.array([aarseth[i,1] for i in range(n_init+70,n_end,20000)])
    z_a = np.array([aarseth[i,2] for i in range(n_init+70,n_end,20000)])
    #ax.scatter3D(x_a, y_a,c="r",label="aarseth")
    ax.scatter(x_a,y_a)
    plt.grid()

    a = 0
    ax.set_xlim([-10,10])
    ax.set_ylim([-10,10])

    ax.set_xlabel('x')
    ax.set_ylabel('y')
    plt.savefig("star/star_{}.png".format(i),dpi=100)
# files = ns.natsorted(os.listdir(directory))

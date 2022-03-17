import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os





mice = np.array(pylab.loadtxt("out.dat"))
# t = []
# # R_min = np.array([])
# t = [i for n, i in enumerate(mice[:,0]) if i not in mice[:n,0]]
# print(t)
for i in range(round(len(mice)/596)):

    fig, ax = plt.subplots()

    n_init = i*596;
    n_mid = round((i+0.5)*596)
    n_end  = (i+1)*596
    l = len(mice)

    x_a = np.array([mice[i,0] for i in range(n_init, n_mid)])
    y_a = np.array([mice[i,1] for i in range(n_init,n_mid)])
    z_a = np.array([mice[i,2] for i in range(n_init,n_mid)])
    x_b = np.array([mice[i,0] for i in range(n_mid,n_end)])
    y_b = np.array([mice[i,1] for i in range(n_mid,n_end)])
    z_b = np.array([mice[i,2] for i in range(n_mid,n_end)])
    # ax.scatter3D(x_a, y_a,c="r",label="mice")
    fig = plt.figure(figsize =[10, 10])
    # ax = fig.add_subplot(projection='3d')
    # ax.scatter(x_a[0],y_a[0],z_a[0], fc='r', s = 50)
    # ax.scatter(x_a[1:],y_a[1:],z_a[1:] ,fc='b', s = 10)
    # ax.scatter(x_b[0],y_b[0],z_b[0], fc='r', s = 50)
    # ax.scatter(x_b[1:],y_b[1:],z_b[1:],fc='b', s = 10)
    ax = fig.add_subplot()
    ax.scatter(x_a[0],y_a[0], fc='r', s = 25)
    ax.scatter(x_a[:],y_a[:] ,fc='r', s = 3)
    ax.scatter(x_b[0],y_b[0], fc='b', s = 25)
    ax.scatter(x_b[:],y_b[:],fc='b', s = 3)
    # ax.view_init(elev=20, azim=8
    # ax.axis('off')

    ax.set_xlim([-10,10])
    ax.set_ylim([-25,25])
    # ax.set_zlim([-40,40])
    ax.legend()
    print("Rmin: {}".format(np.sqrt((x_a[0]-x_b[0])**2 +(y_a[0]-y_b[0])**2+(z_a[0]-z_b[0])**2)))
    # plt.title("Mice Collision with |v| ={} km/s ".format(round(0.06*248)))
    # plt.title("Mice Collison Side View")
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.grid()
    if (i%2 == 0):
        plt.savefig("results/r{}.png".format(i),dpi=100)


# x_a = np.array([mice[i,0] for i in range(len(mice)) if (i%596==0)])
# y_a = np.array([mice[i,1] for i in range(len(mice)) if (i%596==0)])
# x_b = np.array([mice[i,0] for i in range(len(mice)) if (i%596==298)])
# y_b = np.array([mice[i,1] for i in range(len(mice)) if (i%596==298)])
# # plt.xlim([100,-100])
# l = len(x_a)
# # print(x_a)
# # print(y_a)
# plt.scatter(x_a[0:round(l/2)],y_a[0:round(l/2)],c="r")
# plt.scatter(x_a[round(l/2):l-1],y_a[round(l/2):l-1], c="b")
# plt.scatter(x_b[0:round(l/2)],y_b[0:round(l/2)],c ="r")
# plt.scatter(x_b[round(l/2):l-1],y_b[round(l/2):l-1], c="b")
# plt.show()

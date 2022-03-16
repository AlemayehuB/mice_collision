import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os





mice = np.array(pylab.loadtxt("rot_gal.dat", skiprows=1))
mice2 = np.array(pylab.loadtxt("rot_galb.dat", skiprows=1))

l = len(mice)

print(l)
x_a = np.array([mice[i,1] for i in range(l)])
y_a = np.array([mice[i,2] for i in range(l)])
z_a = np.array([mice[i,3] for i in range(l)])

x_b = np.array([mice2[i,1] for i in range(l)])
y_b = np.array([mice2[i,2] for i in range(l)])
z_b = np.array([mice2[i,3] for i in range(l)])
#ax.scatter3D(x_a, y_a,c="r",label="mice")
fig = plt.figure(figsize =[10, 10])
# ax = fig.add_subplot(projection='3d')
# ax.scatter(x_a,y_a,z_a, fc='r')
# ax.scatter(x_b,y_b,z_b,fc='b')
fig, (ax1, ax2) = plt.subplots(1, 2)
ax1.scatter(x_a,y_a, fc='r')
ax2.scatter(x_b,y_b,fc='b')
# ax.view_init(elev=20, azim=85)
# ax.axis('off')

# ax.set_xlim([40,-40])
# ax.set_ylim([-40,40])
# ax.set_zlim([-40,40])
# ax.legend()
# print("Rmin: {}".format(np.sqrt((x_a[0]-x_b[0])**2 +(y_a[0]-y_b[0])**2+(z_a[0]-z_b[0])**2)))
# plt.title("Mice Collision with |v| ={} km/s ".format(round(0.06*248)))
# plt.title("Mice Collison Side View")
# ax.set_xlabel('x')
# ax.set_ylabel('y')
plt.show()
# plt.savefig("reg_{}.png".format(i),dpi=100)

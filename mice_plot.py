import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os



# mass = 10**11 #solar mass
# L_mult = 1.5 #kpc, Plummer Radius
# V_mult = np.sqrt(64/(3*np.pi)*mass/L_mult)
#
# Rad =1.0
# en = np.linspace(0,-2,num = 1000)
# r = np.linspace(0,8,num=1000)
# vo = np.linspace(0,2,num=100)
# rho = mass_den(r,Rad)
#directory ="./collapse"

mice = np.array(pylab.loadtxt("out.dat"))
t = []
t = [i for n, i in enumerate(mice[:,0]) if i not in mice[:n,0]]
print(t)
for i in range(round(len(mice)/596)):

    fig, ax = plt.subplots()

    n_init = i*596;
    n_mid = round((i+0.5)*596)
    n_end  = (i+1)*596
    l = len(mice)
    # x_a = np.array([mice[i,1] for i in range(n_init, n_mid) if i%2==0])
    # x_a1 = np.array([mice[i,1] for i in range(n_init,n_mid) if i%2!=0])
    # y_a = np.array([mice[i,2] for i in range(n_init,n_mid)   if i%2==0])
    # y_a1 = np.array([mice[i,2] for i in range(n_init,n_mid) if i%2!=0])
    # z_a = np.array([mice[i,3] for i in range(n_init,n_mid)   if i%2==0])
    # z_a1 = np.array([mice[i,3] for i in range(n_init,n_mid) if i%2!=0])
    x_a = np.array([mice[i,1] for i in range(n_init, n_mid)])
    y_a = np.array([mice[i,2] for i in range(n_init,n_mid)])
    z_a = np.array([mice[i,3] for i in range(n_init,n_mid)])
    x_b = np.array([mice[i,1] for i in range(n_mid,n_end)])
    y_b = np.array([mice[i,2] for i in range(n_mid,n_end)])
    z_b = np.array([mice[i,3] for i in range(n_mid,n_end)])
    #ax.scatter3D(x_a, y_a,c="r",label="mice")
    fig = plt.figure(figsize =[10, 10])
    # ax = fig.add_subplot(projection='3d')
    # ax.scatter(x_a,y_a, z_a, c="r",label="Gal A")
    # ax.scatter(x_b,y_b, z_b, c="b",label="Gal B")
    ax = fig.add_subplot()
    ax.scatter(x_a[0],y_a[0], fc='b', s = 30)
    ax.scatter(x_a[1:],y_a[1:], fc='b', s = 3)
    ax.scatter(x_b[0],y_b[0], fc='r', s = 30)
    ax.scatter(x_b[1:],y_b[1:], fc='r', s = 3)
    ax.set_xlim([-40,40])
    ax.set_ylim([-45,45])
    ax.legend()

    ax.set_xlim([-40,40])
    ax.set_ylim([-45,45])
    plt.title("Mice Collision @ t ={} ".format(t[i]))
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    plt.savefig("reg_{}.png".format(i),dpi=100)

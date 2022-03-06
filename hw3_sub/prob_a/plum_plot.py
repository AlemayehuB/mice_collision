import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os



mass = 10**11 #solar mass
L_mult = 1.5 #kpc, Plummer Radius
V_mult = np.sqrt(64/(3*np.pi)*mass/L_mult)


#
# Rad =1.0
# en = np.linspace(0,-2,num = 1000)
# r = np.linspace(0,8,num=1000)
# vo = np.linspace(0,2,num=100)
# rho = mass_den(r,Rad)
#directory ="./collapse"
directory ="./Results"
energy = np.array(pylab.loadtxt("log.txt", skiprows =1))
t = np.array([energy[i,0] for i in range(len(energy))])
print(t)
files = ns.natsorted(os.listdir(directory))
aarseth = np.array(pylab.loadtxt("sphere.data"))
for i in range(1,40):
    if len(files) == i:
        break
    fig, ax = plt.subplots()

    n_init = 1+ (i-1)*20000;
    n_end  = i*20000;
    l = len(aarseth)
    x_a = np.array([aarseth[i,0] for i in range(n_init,n_end)])
    y_a = np.array([aarseth[i,1] for i in range(n_init,n_end)])
    z_a = np.array([aarseth[i,2] for i in range(n_init,n_end)])
    #ax.scatter3D(x_a, y_a,c="r",label="aarseth")
    ax.scatter(x_a,y_a,c="r",label="aarseth")

    f = os.path.join(directory, files[i])
    my_data = np.array(pylab.loadtxt(f))
    x_pl = np.array([my_data[i,1] for i in range(len(my_data))])
    y_pl = np.array([my_data[i,2] for i in range(len(my_data))])
    z_pl = np.array([my_data[i,3] for i in range(len(my_data))])
    plt.grid()
    ax.scatter(x_pl,y_pl,c="b",label="leapfrog")
    ax.legend()

    ax.set_xlim([-20,20])
    ax.set_ylim([-20,20])
    plt.title("Plummer Sphere @ t ={} ".format(t[i]))
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    plt.savefig("reg_{}.png".format(i),dpi=100)

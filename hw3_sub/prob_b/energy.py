import matplotlib.pyplot as plt
import numpy as np
import natsort as ns
import math
import pylab
import os
'''
log.txt calcualtes the KE, PE, TE, and L for each time step
'''


en = np.array(pylab.loadtxt("log.txt", skiprows =1))
aarseth = np.array(pylab.loadtxt("spheredata.data"))

#G =1, M=1, R=1
t = np.array([en[i,0] for i in range(len(en))])
ke= np.array([en[i,1] for i in range(len(en))])
pe= np.array([en[i,2] for i in range(len(en))])
te= np.array([en[i,3] for i in range(len(en))])


plt.scatter(t,ke,label="KE")
plt.scatter(t,pe,label="PE")
plt.scatter(t,te,label="Total")
plt.scatter(t,np.ones(len(t))*(np.pi*3/64.0),label ="Analytic")
plt.title("Energy Conservation")
plt.xlabel("Time")
plt.ylabel("Energy")
plt.legend()
plt.show()

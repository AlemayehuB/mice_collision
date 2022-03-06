import matplotlib.pyplot as plt
import numpy as np
import pylab
import os

data = pylab.loadtxt("non-lin.dat") # Non-Linear Pendulum Data
data = pylab.loadtxt("lin.dat")  # Linear Pendulum Data
#Point(1,0)
x_0 = np.array([data[i,2] for i in range(0,round(len(data))) if (data[i,1] == 0)])
v_0 = np.array([data[i,3] for i in range(0,round(len(data))) if (data[i,1] == 0)])
#Point(2,0)
x_1 = np.array([data[i,2] for i in range(0,round(len(data))) if (data[i,1] == 1)])
v_1 = np.array([data[i,3] for i in range(0,round(len(data))) if (data[i,1] == 1)])
#point(0,3)
x_2 = np.array([data[i,2] for i in range(0,round(len(data))) if (data[i,1] == 2)])
v_2 = np.array([data[i,3] for i in range(0,round(len(data))) if (data[i,1] == 2)])
#time
t = np.array([data[i,0] for i in range(0,round(len(data))) if (data[i,1] == 2)])

#3D Phase Space Plots
# ax = plt.axes(projection='3d')
# ax.plot3D(x_0,v_0,t,'black',label ="(1,0)")
# ax.plot3D(x_1,v_1,t,'red',label ="(2,0)")
# ax.plot3D(x_2,v_2,t,'blue',label ="(0,3)")
# ax.set_title("3D Non-Linear Pendulum")
#ax.set_xlabel('x')
#ax.set_ylabel('v')
# ax.set_zlabel('t');
# ax.legend()

#2D Phase Space Plots
plt.plot(x_0,v_0,label ="(1,0)")
plt.plot(x_1,v_1,label ="(2,0)")
plt.plot(x_2,v_2,label ="(0,3)")
plt.xlabel('x')
plt.ylabel('v')
plt.title("Linear Pendulum")
plt.legend()
plt.show()

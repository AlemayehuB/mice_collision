import matplotlib.pyplot as plt
import numpy as np
import pylab
import os




import matplotlib.pyplot as plt
import numpy as np
import pylab
import os

data = np.array(pylab.loadtxt("planet.dat"))
steps = len(data)
fig, ax1 = pylab.subplots()
#Mercury
x0 = np.array([(data[i,2]**2 + data[i,3]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 0)])
v0 = np.array([(data[i,4]**2 + data[i,5]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 0)])
p0 = x0*v0
#Venus
x1 = np.array([(data[i,2]**2 + data[i,3]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 1)])
v1 = np.array([(data[i,4]**2 + data[i,5]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 1)])
p1 = x1*v1
#Earth
x2 = np.array([(data[i,2]**2 + data[i,3]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 2)])
v2 = np.array([(data[i,4]**2 + data[i,5]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 2)])
p2 = x2*v2
#Mars
x3 = np.array([(data[i,2]**2 + data[i,3]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 3)])
v3 = np.array([(data[i,4]**2 + data[i,5]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 3)])
p3 = x3 *v3

#Jupiter
x4 = np.array([(data[i,2]**2 + data[i,3]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 4)])
v4 = np.array([(data[i,4]**2 + data[i,5]**2)**0.5 for i in range(0,round(steps)) if (data[i,1] == 4)])
p4 = x4 *v4

t = np.array([data[i,0] for i in range(0,round(steps)) if (data[i,1] == 2)])


plt.scatter(t,p0, c='k', label ="Mercury")
plt.scatter(t,p1, c='g', label ="Venus")
plt.scatter(t,p2, c='b', label ="Earth")
plt.scatter(t,p3, c='r', label ="Mars")
plt.scatter(t,p4, label ="Jupiter")


ax1.set_xlabel("Time")
ax1.set_ylabel("Angular Momentum(AU^2*(Solar Mass)/Yr)")
ax1.set_title("Angular Momentum")
# ax2.set_xlim([-3,2])
# ax2.set_ylim([-2.5,2.5])
ax1.legend()
# ax2.legend()
plt.show()

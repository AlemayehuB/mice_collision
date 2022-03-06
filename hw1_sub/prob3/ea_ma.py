import matplotlib.pyplot as plt
import numpy as np
import pylab
import os


data = np.array(pylab.loadtxt("planet.dat"))

steps = len(data)
x_2 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 2)])
y_2 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 2)])
vx_2 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 2)])
vy_2 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 2)])

x_3 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 3)])
y_3 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 3)])
vx_3 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 3)])
vy_3 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 3)])


ax1 = plt.subplot(121)
ax1.scatter(x_2,y_2 , c='b', label ="Earth")
#ax1.scatter(x_2[:int(0.2*len(x_2))],y_2[:int(0.2*len(x_2))] , c='b', label ="Earth")
ea_xan = 1.0027*np.sin(np.linspace(0,2*np.pi, 100)) + 0.0167
ea_yan = 1.0025*np.cos(np.linspace(0,2*np.pi, 100))
ax1.plot(ea_xan, ea_yan, 'k',label = "Analytic: Earth" )

ax2 = plt.subplot(122)
#ax2.scatter(x_3[:int(0.2*len(x_2))],y_3[:int(0.2*len(x_2))] , c='r', label ="Mars")
ax2.scatter(x_3,y_3 , c='r', label ="Mars")
ma_xan = 1.5241*np.sin( np.linspace(0,2*np.pi, 100)) + 0.1424
ma_yan = 1.5173*np.cos(np.linspace(0,2*np.pi, 100))
ax2.plot(ma_xan, ma_yan,'k', label = "Analytic: Mars" )
#
ax1.legend()
ax2.legend()
plt.show()

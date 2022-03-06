import matplotlib.pyplot as plt
import numpy as np
import pylab
import os

data = pylab.loadtxt("planet.dat")
steps = round(len(data))-1
print(steps/15)
fig, axes = pylab.subplots()

x_0 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 0)])
y_0 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 0)])
vx_0 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 0)])
vy_0 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 0)])
#axes.scatter(x_0,y_0,label ="Mercury")
axes.scatter(x_0[:int(steps/10)],y_0[:int(steps/10)],label ="Mercury")

x_1 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 1)])
y_1 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 1)])
vx_1 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 1)])
vy_1 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 1)])
#axes.plot(x_1, y_1,label ="Venus")
axes.scatter(x_1[:int(steps/10)], y_1[:int(steps/10)],label ="Venus")
#
x_2 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 2)])
y_2 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 2)])
vx_2 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 2)])
vy_2 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 2)])
#axes.plot(x_2, y_2, label ="Earth")
axes.scatter(x_2[:int(steps/10)], y_2[:int(steps/10)],label ="Earth")
#
x_3 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 3)])
y_3 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 3)])
vx_3 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 3)])
vy_3 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 3)])
#axes.plot(x_3, y_3,label ="Mars")
axes.scatter(x_3[:int(steps/10)], y_3[:int(steps/10)],label ="Mars")
#
x_4 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 4)])
y_4 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 4)])
vx_4 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 4)])
vy_4 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 4)])
axes.plot(x_4, y_4, label ="Jupiter")

x_5 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 5)])
y_5 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 5)])
vx_5 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 5)])
vy_5 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 5)])
axes.plot(x_5, y_5, label ="Saturn")

x_6 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 7)])
y_6 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 7)])
vx_6 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 7)])
vy_6 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 7)])
axes.plot(x_6, y_6, label ="Neptune")

x_7 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 6)])
y_7 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 6)])
vx_7 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 6)])
vy_7 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 6)])
axes.plot(x_7, y_7,label ="Uranus")

x_8 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 8)])
y_8 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 8)])
vx_8 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 8)])
vy_8 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 8)])
axes.plot(x_8, y_8, label ="Pluto")

Sun = pylab.Circle((0,0), radius = 0.05, fc='y', label ='Sun')
axes.add_patch(Sun)
# axes.set_xlim([-65,45])
# axes.set_ylim([-45,45])
axes.legend()
axes.set_title("Outer Planet Orbits")
axes.set_xlabel("X-Position(AU)")
axes.set_ylabel("Y-Position(AU)")
fig.set_size_inches(10.5, 10.5, forward=True)
plt.show()

# mer_y = data[:,2,9]
# mer_x = data[:,1,9]
# ven_y = data[:,2,9]
# ven_x = data[:,1,9]
# for i in range(0,round(steps)/8),16):
#     fig, axes = pylab.subplots()
#     axes.set_xlim([-3,3])
#     axes.set_ylim([-3,3])
#     axes.set_aspect('equal')
#     #Mercury = pylab.Circle((data[i,1],data[i,2]), radius = 0.04, fc='rosybrown',label ='Mercury')
#     Earth = pylab.Circle((data[i+1,1],data[i+1,2]), radius = 0.15, fc='b',label ='Earth')
#     Halley = pylab.Circle((data[i,1],data[i,2]), radius = 0.3, fc='r',label ='Halley')
#     # Mars = pylab.Circle((data[i+3,1],data[i+3,2]), radius = 0.125, fc='r',label ='Mars')
#     # Venus = pylab.Circle((data[i+1,1],data[i+1,2]), radius = 0.15, fc='m',label ='Venus')
#     # Jupiter = pylab.Circle((data[i+4,1],data[i+4,2]), radius = 1, fc='orange',label ='Jupiter')
#     # Saturn = pylab.Circle((data[i+5,1],data[i+5,2]), radius = 0.8, fc='g',label ='Saturn')
#     # Uranus = pylab.Circle((data[i+6,1],data[i+6,2]), radius = 0.7, fc='brown',label ='Uranus')
#     # Neptune = pylab.Circle((data[i+7,1],data[i+7,2]), radius = 0.67, fc='c',label ='Neptune')
#     # Pluto = pylab.Circle((data[i+8,1],data[i+8,2]), radius = 0.04, fc='k',label ='Pluto')
#     Sun = pylab.Circle((0,0), radius = 0.6, fc='y', label ='Sun')
#     #circle2 = pylab.Circle((data2[i-1,2],data2[i-1,3]), radius = 0.5, fc='r',label = '(0,3)')
#
#
#     axes.add_patch(Earth)
#     axes.add_patch(Halley)
#     #axes.add_patch(Mars)
#     axes.add_patch(Sun)
#     # axes.add_patch(Venus)
#     # axes.add_patch(Jupiter)
#     # axes.add_patch(Saturn)
#     # axes.add_patch(Uranus)
#     # axes.add_patch(Neptune)
#     # axes.add_patch(Pluto)
#     # axes.add_patch(Mercury)
#
#
#     pylab.title("Earth and Halley's Comet, t =%.2f " % data[i,0])
#     pylab.xlabel("Position (m)")
#     pylab.grid(True)
#     axes.set_xlim([-20,5])
#     axes.set_ylim([-5,7])
#     pylab.legend()
#     # fig.set_size_inches(18.5, 10.5, forward=True)
#     fig.savefig("EO_2/op_{}.png".format(i),dpi=100)

import matplotlib.pyplot as plt
import numpy as np
import pylab
import os


data = np.array(pylab.loadtxt("hal.dat"))

steps = len(data)
x_0 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 0)])
y_0 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 0)])
vx_0 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 0)])
vy_0 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 0)])
t = np.array([data[i,0] for i in range(0,round(steps)) if (data[i,1] == 0)])

ea_xan = 1.0027*np.sin(np.linspace(0,2*np.pi, 100)) + 0.0167
ea_yan = 1.0025*np.cos(np.linspace(0,2*np.pi, 100))

x_1 = np.array([data[i,2] for i in range(0,round(steps)) if (data[i,1] == 1)])
y_1 = np.array([data[i,3] for i in range(0,round(steps)) if (data[i,1] == 1)])
vx_1 = np.array([data[i,4] for i in range(0,round(steps)) if (data[i,1] == 1)])
vy_1 = np.array([data[i,5] for i in range(0,round(steps)) if (data[i,1] == 1)])

isExist = os.path.exists("HO")
if not isExist:
#Create a new directory because it does not exist
  os.makedirs("HO")
  print("The new directory is created!")

for i in range(1,round(len(x_0)),4):
    fig, axes = pylab.subplots()
    axes.set_xlim([-3,3])
    axes.set_ylim([-3,3])
    axes.set_aspect('equal')

    Earth = pylab.Circle(((x_1[i]),y_1[i]), radius = 0.15, fc='b',label ='Earth')
    Halley = pylab.Circle(((x_0[i]),y_0[i]), radius = 0.25, fc='k',label ='Halley')
    Sun = pylab.Circle((0,0), radius = 0.35, fc='y', label ='Sun')
    #axes.plot(ea_xan, ea_yan, 'k',label = "Analytic: Earth" )

    axes.add_patch(Earth)
    axes.add_patch(Halley)
    axes.add_patch(Sun)


    pylab.title("Earth & Halley @ t =%.2f " % t[i])
    pylab.xlabel("Position (AU)")
    pylab.grid(True)
    axes.set_xlim([-3,40])
    axes.set_ylim([-8,8])
    pylab.legend(loc="lower center",)
    # fig.set_size_inches(18.5, 10.5, forward=True)
    fig.savefig("HO/op_{}.png".format(i),dpi=100)

    axes.legend()

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
t = np.array([data[i,0] for i in range(0,round(steps)) if (data[i,1] == 2)])

ea_xan = 1.0027*np.sin(np.linspace(0,2*np.pi, 100)) + 0.0167
ea_yan = 1.0025*np.cos(np.linspace(0,2*np.pi, 100))

isExist = os.path.exists("EO")
if not isExist:
#Create a new directory because it does not exist
  os.makedirs("EO")
  print("The new directory is created!")

for i in range(round(len(x_2))):
    fig, axes = pylab.subplots()
    axes.set_xlim([-3,3])
    axes.set_ylim([-3,3])
    axes.set_aspect('equal')

    Earth = pylab.Circle(((x_2[i]),y_2[i]), radius = 0.05, fc='b',label ='Earth')
    Sun = pylab.Circle((0,0), radius = 0.25, fc='y', label ='Sun')
    axes.plot(ea_xan, ea_yan, 'k',label = "Analytic: Earth" )

    axes.add_patch(Earth)

    axes.add_patch(Sun)


    pylab.title("Earth @ t =%.2f " % t[i])
    pylab.xlabel("Position (m)")
    pylab.grid(True)
    axes.set_xlim([-1.5,1.5])
    axes.set_ylim([-1.5,1.5])
    pylab.legend(loc="upper center",)
    # fig.set_size_inches(18.5, 10.5, forward=True)
    fig.savefig("EO/op_{}.png".format(i),dpi=100)

    axes.legend()

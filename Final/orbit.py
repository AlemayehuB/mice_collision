def deriv(X, t):
    x, v = X.reshape(2, -1)
    acc  = -mu * x * ((x**2).sum())**-1.5
    return np.hstack((v, acc))

def get_D(theta, e):
    if e == 1.0:
        D    = np.tan(0.5*theta)
    else:
        D    = np.nan
    return D

def get_E(theta, e):
    if e < 1.0:
        term = np.sqrt((1.-e)/(1.+e)) * np.tan(0.5*theta)
        E    = 2.*np.arctan(term)
    else:
        E    = np.nan
    return E

def get_E_alt(theta, e):
    if e < 1.0:
        term = (e + np.cos(theta)) / (1. + e*np.cos(theta))
        E    = np.arccos(term)
    else:
        E    = np.nan
    return E

def get_F(theta, e):
    if e > 1.0:
        term = np.sqrt((e-1.)/(e+1.)) * np.tan(0.5*theta)
        F    = 2.*np.arctanh(term)
    else:
        F    = np.nan
    return F

def get_F_alt(theta, e):
    if e > 1.0:
        term = (e + np.cos(theta)) / (1. + e*np.cos(theta))
        F    = np.arccosh(term)
    else:
        F    = np.nan
    return F

def get_M_from_E(E, e):
    if e < 1.0:
        M = E - e*np.sin(E)
    else:
        M = np.nan
    return M

def get_M_from_F(F, e):
    if e > 1.0:
        M = e*np.sinh(F) - F
    else:
        M = np.nan
    return M

def get_M_from_D(D, e):
    if e == 1.0:
        M = D + D**3/3.
    else:
        M = np.nan
    return M

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint as ODEint

# http://www.bogan.ca/orbits/kepler/orbteqtn.html

quarterpi, halfpi, pi, twopi = [f*np.pi for f in [0.25, 0.5, 1, 2]]
rads, degs = pi/180, 180/pi

mu = 1.0

th0, th1 = 0.0, halfpi
print("th0, th1 (degs): ", degs*th0, degs*th1)

eccs = [1.5, 1.0, 0.5, 0.0]

for e in eccs:

    print( "e: ", e)

    rp =  1.0  # periapsis

    if e < 1.0:
        print("     is ellipse!")

        ra = rp * (1+e)/(1-e)
        print("rp, ra: ", rp, ra)

        a0 = 0.5*(rp + ra)
        v0 = np.sqrt(mu * (2./rp - 1./a0))
        print("a0, v0: ", a0, v0)

        E0,  E1  = [get_E(th, e) for th in [th0, th1]]
        M0,  M1  = [get_M_from_E(E, e)  for E  in [E0,  E1 ]]
        print( "E0, E1 (degs): ", degs*E0, degs*E1)
        print("M0, M1 (degs): ", degs*M0, degs*M1)

        print("E0, E1: ", E0, E1)
        print("M0, M1: ", M0, M1)

        dt = np.sqrt(a0**3/mu) * (M1-M0)

        print("dt (sec): ", dt)

    elif e > 1.0:
        print("     is hyperbola!")

        ra = rp * (1+e)/(1-e)
        print("rp, ra: ", rp, ra)

        a0 = 0.5*(rp + ra)
        v0 = np.sqrt(mu * (2./rp - 1./a0))
        print("a0, v0: ", a0, v0)

        F0,  F1  = [get_F(th, e) for th in [th0, th1]]
        M0,  M1  = [get_M_from_F(F, e)  for F  in [F0,  F1 ]]
        print("F0, F1 (degs): ", degs*F0, degs*F1)
        print("M0, M1 (degs): ", degs*M0, degs*M1)

        print("F0, F1: ", F0, F1)
        print("M0, M1: ", M0, M1)

        dt = np.sqrt((-a0)**3/mu) * (M1-M0)

        print("dt (sec): ", dt)

    elif e == 1.0:
        print("     is parabola!")

        print("rp: ", rp)

        v0 = np.sqrt(mu * (2./rp))
        print("v0: ", v0)

        D0,  D1  = [get_D(th, e) for th in [th0, th1]]
        M0,  M1  = [get_M_from_D(D, e)  for D  in [D0,  D1 ]]
        print("D0, D1 (degs): ", degs*D0, degs*D1)
        print("M0, M1 (degs): ", degs*M0, degs*M1)

        print("D0, D1: ", D0, D1)
        print("M0, M1: ", M0, M1)

        q = rp

        dt = np.sqrt(2.*q**3/mu) * (M1-M0)

        print("dt (sec): ", dt)

    time = np.array([0, dt])
    X0   = np.array([rp, 0, 0, v0])

    answer, info = ODEint(deriv, X0, time, atol=1E-13, rtol=1E-13, full_output=True)

    x, y, vx, vy = answer.T
    theta = np.arctan2(y, x)

    print(degs*theta[0], degs*theta[-1], " should be ", degs*th0, degs*th1)

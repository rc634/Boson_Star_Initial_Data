import numpy as np
import matplotlib.pyplot as plt
import csv


p_array = []
p = open("p.csv")
p = csv.reader(p, delimiter=',')
for thing in p:
	p_array += [float(thing[0])]
p_array = np.array(p_array)

psi_array = []
psi = open("psi.csv")
psi = csv.reader(psi, delimiter=',')
for thing in psi:
	psi_array += [float(thing[0])]
psi_array = np.array(psi_array)

omega_array = []
omega = open("omega.csv")
omega = csv.reader(omega, delimiter=',')
for thing in omega:
	omega_array += [float(thing[0])]
omega_array = np.array(omega_array)

r_array = []
r = open("r.csv")
r = csv.reader(r, delimiter=',')
for thing in r:
	r_array += [float(thing[0])]
r_array = np.array(r_array)

i = 0
mass = 0.
for x in r_array:
	mass += x*x*p_array[i]*omega_array[i]*(psi_array[i]**3)
	i += 1

m_of_r = 0.
i = 0
for x in r_array:
	m_of_r += x*x*p_array[i]*omega_array[i]*(psi_array[i]**3)
	i += 1
	if (m_of_r/mass > 0.99):
		print("99 radius = ", x)
		break


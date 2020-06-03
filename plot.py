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

plt.plot(r_array,p_array/p_array[0], color = [119./255.,0,1])
plt.plot(r_array,psi_array, 'r')
plt.plot(r_array,omega_array, 'g')

plt.xlim(0,r_array[-1])
plt.ylim(-0.5,2.5)

plt.show()
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import csv,sys

################################################################################

filename = sys.argv[1]

infile = csv.reader(open(filename, 'rb'), delimiter=',', quotechar='#')

x0 = [[],[],[]]
x1 = [[],[],[]]

nlines = 0
for row in infile:

    x0[0].append(float(row[0]))
    x0[1].append(float(row[1]))
    x0[2].append(float(row[2]))

    x1[0].append(float(row[3]))
    x1[1].append(float(row[4]))
    x1[2].append(float(row[5]))

    nlines += 1

fig = plt.figure(figsize=(12,8))
ax = fig.add_subplot(111, projection='3d')
n = 100


for i in xrange(nlines):
    x = [x0[0][i],x1[0][i]]
    y = [x0[1][i],x1[1][i]]
    z = [x0[2][i],x1[2][i]]
    ax.plot(x, y, z, c='blue', marker='o')

ax.set_xlabel('x-axis')
ax.set_ylabel('y-axis')
ax.set_zlabel('z-axis')

plt.show()
################################################################################


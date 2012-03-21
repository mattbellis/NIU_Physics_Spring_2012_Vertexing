import numpy as np
import matplotlib.pylab as plt

#x = np.random.rand(10000)
#x = np.random.normal(2.0,0.5,10000)

values = []

################################################################################
# Figure out max val of function
################################################################################
i=0
max_val = -999
while i < 10000:

    xval = 10*np.random.rand()

    yval = np.exp(-xval)
    
    if yval>max_val:
        max_val = yval

    i += 1

print max_val

################################################################################
# Generate numbers
################################################################################

i = 0
while i < 100000:

    xval = 10*np.random.rand()

    yval = np.exp(-xval)

    if (max_val*np.random.rand() < yval):
        values.append(xval)
        #print "%f %f" % (xval,yval)

        i+=1




plt.hist(values,bins=50)
plt.show()



import numpy as np
import scipy as sp

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

import pct_utilities as pct

################################################################################
def main():

    print "In main"
    nprotons = 100

    MASS_proton = 938.272

    # Is this really the momentum?
    proton_energy = 500.0  # MeV?
    prob_of_scatter = 0.05

    time_step = 0.10 # ns
    nsteps = 100


    plots = []

    fig = plt.figure(figsize=(12,8))
    ax = fig.add_subplot(111, projection='3d')

    # Move proton
    x,y,z = 0.0,0.0,0.0
    for n in xrange(nprotons):
        total_energy = np.sqrt(MASS_proton*MASS_proton + proton_energy*proton_energy)
        initial_velocity = (proton_energy/total_energy)*29.97 # Gives us velocity in cm/ns
        vel = np.array([initial_velocity,0.0,0.0])
        pos = np.array([0.0,0.0,0.0]) # position of proton
        scattered = False

        step_positions = [[],[],[]]
        for i in range(0,nsteps):

            pos += vel*time_step

            step_positions[0].append(float(pos[0]))
            step_positions[1].append(float(pos[1]))
            step_positions[2].append(float(pos[2]))

            #print pos

            # See if we scatter once.
            if not scattered:
                if np.random.rand()<prob_of_scatter:
                    vel[1] += 0.1*np.random.rand()
                    scattered = True

        print pos[1]
            
        
        x = list(step_positions[0])
        y = list(step_positions[1])
        z = list(step_positions[2])

        if n==0:
            ax.plot(list(x),list(y),list(z), c='blue')
        else:
            ax.plot(list(x),list(y),list(z), c='green')

    ax.set_xlabel('x-axis')
    ax.set_ylabel('y-axis')
    ax.set_zlabel('z-axis')

    plt.show()

    
################################################################################





################################################################################
if __name__=="__main__":
    main()


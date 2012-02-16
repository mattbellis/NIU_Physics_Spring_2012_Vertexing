import numpy as np
import scipy as sp

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

import pct_utilities as pct

################################################################################
def main():

    nprotons = 10000

    MASS_proton = 938.272

    # Is this really the momentum?
    proton_energy = 500.0  # MeV?
    prob_of_scatter = 0.05

    # Location of detector
    detector_x_position = 100.0

    time_step = 0.10 # ns
    nsteps = 100

    size_of_phantom = 10 # cm

    plots = []

    fig = plt.figure(figsize=(12,8))
    #ax = fig.add_subplot(111, projection='3d')
    ax = fig.add_subplot(111)

    pixel_positions = []

    # Move proton
    x,y,z = 0.0,0.0,0.0
    for n in xrange(nprotons):

        total_energy = np.sqrt(MASS_proton*MASS_proton + proton_energy*proton_energy)

        initial_velocity = (proton_energy/total_energy)*29.97 # Gives us velocity in cm/ns

        vel = np.array([initial_velocity,0.0,0.0]) # velocity of the proton
        pos = np.array([0.0,0.0,0.0]) # position of proton

        scattered = False

        step_positions = [[],[],[]]
        # Keep stepping through the simulation until the proton
        # reaches the detector.
        while pos[0]<detector_x_position:

            pos += vel*time_step

            step_positions[0].append(pos[0])
            step_positions[1].append(pos[1])
            step_positions[2].append(pos[2])

            #print pos

            # See if we hard scatter once.
            if not scattered and pos[0]<size_of_phantom:

                # Need to change this so probability of interacting
                # (scattering) is proportional to how much material
                # it has traversed in the phantom.

                if np.random.rand()<prob_of_scatter:
                    #vel[1] += 0.1*np.random.rand()
                    vel = pct.scatter_hard_Gaussian(vel)
                    scattered = True

        #print pos[1]
            
        
        x = step_positions[0]
        y = step_positions[1]
        z = step_positions[2]

        #color = (0.0+n*0.009,0.9-0.005*n,0.3+0.005*n)
        color = 'red'
        #ax.plot(list(x),list(y),list(z), c=color)
        if np.abs(y[-1])>0.1: # Cut out tracks that have small scattering angle.
            ax.plot(x,y,c=color)
            pixel_positions.append(pos[1])

    ax.set_xlabel('x-axis')
    ax.set_ylabel('y-axis')
    #ax.set_zlabel('z-axis')

    fig1 = plt.figure(figsize=(6,6))
    ax1 = fig1.add_subplot(111)

    ax1.hist(pixel_positions,bins=25)


    plt.show()

    
################################################################################





################################################################################
if __name__=="__main__":
    main()


import numpy as np
import scipy as sp

import matplotlib.pyplot as plt

import pct_utilities as pct

################################################################################
def main():

    ############################################################################
    # Initialization
    ############################################################################
    nprotons = 1000
    MASS_proton = 938.272
    # Is this really the momentum?
    proton_initial_energy = 500.0  # MeV?
    prob_of_scatter_in_phantom = 0.05

    # Location of detector
    detector_x_position = 100.0

    time_step = 0.10 # ns

    size_of_phantom = 5 # cm

    pixel_positions = []

    total_energy = np.sqrt(MASS_proton*MASS_proton + proton_initial_energy*proton_initial_energy)
    initial_velocity = (proton_initial_energy/total_energy)*29.97 # Gives us velocity in cm/ns

    # A bit of plotting declarations.
    fig = plt.figure(figsize=(12,8))
    ax = fig.add_subplot(111)

    ############################################################################

    x,y,z = 0.0,0.0,0.0
    n=0
    while n<nprotons:

        vel = np.array([initial_velocity,0.0,0.0]) # velocity of the proton
        pos = np.array([0.0,0.0,0.0]) # position of proton
        scattered = False
        prob_of_scatter=prob_of_scatter_in_phantom 
        step_positions = [[],[],[]]

        # Propagate the proton to the detector.
        while pos[0]<detector_x_position:

            # Make sure we're still inside the phantom.
            if pos[0]>size_of_phantom: 
                prob_of_scatter=-999 # Won't scatter anymore because we are
                                     # outside of the phantom.
                scattered = True

            pos,vel,scattered = pct.take_a_step_in_the_phantom(pos,vel, \
                    time_step,prob_of_scatter,scattered)

            # Grab the step positions for plotting later.
            for j in xrange(3):
                step_positions[j].append(pos[j])

        ########################################################################
        # Finished stepping one proton
        ########################################################################
        
        ########################################################################
        # Plot the scattering info for that one track.
        ########################################################################
        
        x = step_positions[0]
        y = step_positions[1]
        z = step_positions[2]

        #color = 'red'
        increment = 1.0/nprotons
        color = (0.0+n*increment,0.0+n*increment,0.0+n*increment)
        if np.abs(y[-1])>0.1: # Cut out tracks that have small scattering angle.
            ax.plot(x,y,c=color)
            pixel_positions.append(pos[1])
            if n%100==0:
                print n

            n += 1


    ############################################################################
    # Plot the information.
    ############################################################################
    ax.set_xlabel('x-axis')
    ax.set_ylabel('y-axis')

    fig1 = plt.figure(figsize=(6,6))
    ax1 = fig1.add_subplot(111)

    print len(pixel_positions)
    print np.std(pixel_positions)
    ax1.hist(pixel_positions,bins=25)


    plt.show()

    
################################################################################





################################################################################
if __name__=="__main__":
    main()


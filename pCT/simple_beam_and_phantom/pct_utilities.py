import numpy as np

################################################################################
def take_a_step_in_the_phantom(pos,vel,time_step,prob_of_scatter,scattered=False):

    # First move
    pos += vel*time_step

    if not scattered:

        # Check to see if we've scattered, and if so, 
        # update the new velocity.
        #
        # Need to change this so probability of interacting
        # (scattering) is proportional to how much material
        # it has traversed in the phantom.
        # 
        if np.random.rand()<prob_of_scatter:
            vel = scatter_hard_Gaussian(vel)
            scattered = True

    return pos,vel,scattered

################################################################################
def scatter_hard_Gaussian(vel):

    # Not yet worrying about energy loss

    # Scatter the particle around a Gaussian distribution.
    # Can make it more of a ``hard" scatter by changing the sigma of the
    # normal distribution.
    sigma = 0.4
    angle = np.random.normal(0,sigma)

    # Scatter up or down?
    if np.random.rand()<0.5:
        angle *= -1

    # Only scatter in the x-y plane.
    vel[0] += np.cos(angle)
    vel[1] += np.sin(angle)

    return vel

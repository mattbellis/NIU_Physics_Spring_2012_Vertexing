import numpy as np

################################################################################
def scatter_hard_Gaussian(vel):

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

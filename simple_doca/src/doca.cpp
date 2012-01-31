///////////////////////////////////////////////////////////////////////////////
// doca.h
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-12
// Description: Test case for distance of closest approach of two Lines
///////////////////////////////////////////////////////////////////////////////

#include "doca.h"
#include "line.h"
#include "vect.h"
// returns the distance of two lines
//   see doc/simple_doca.pdf for mathematical details on calculations
double doca(Line j, Line k)
{
    // create a vector pointing from the endpoints of j to k
    Vect w(j.p(),k.p());
    
    // calculate various dot products
    double a = (j.u()).dot(j.u());
    double b = (j.u()).dot(k.u());
    double c = (k.u()).dot(k.u());
    double d = (j.u()).dot(w);
    double e = (k.u()).dot(w);
    
    // find the points on each line that correspond to the doca
    //   for line, j(s)= p_j + s * u_j and k(t)= p_k + t * u_k
    //   see doc/simple_doca.pdf for explanation of these variables
    double s = ((b * e) - (c * d)) / ((a * c) - (b * b));
    double t = ((a * e) - (b * d)) / ((a * c) - (b * b));
    
    // get the vector pointing from the endpoints to points at s and t 
    Vect u_prime = (j.u()).multiply_scalar(s);
    Vect v_prime = (k.u()).multiply_scalar(t);
    
    // return the magnitude of the minimum line connecting j and k  |w + (s*u'-t*v')|
    return Vect(w.add(u_prime.subtract(v_prime))).norm();
}

//=============================================================================
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Implementation of functions in class Vect. See vect.h for 
//                class and function descriptions.
//=============================================================================

#include "vect.h"

Vect::Vect(Point p, Point q) {
  x1_ = q.x1()-p.x1();
  x2_ = q.x2()-p.x2();
  x3_ = q.x3()-p.x3();
};

double Vect::dot(Vect v) const { return (x1_ * v.x1() + x2_ * v.x2() + x3_ * v.x3()); };

Vect Vect::cross(Vect v) const {
  return Vect(x2_ * v.x3() - x3_ * v.x2(),
              x3_ * v.x1() - x1_ * v.x3(),
              x1_ * v.x2() - x2_ * v.x1());
}

Vect Vect::add(Vect v) const {
  return Vect(x1_ + v.x1(), x2_ + v.x2(), x3_ + v.x3());
}
    
Vect Vect::multiply_scalar( double a ) {
  return Vect(x1_ * a, x2_ * a, x3_ * a);
}

Vect Vect::subtract(Vect v) const {
  return Vect(x1_ + v.x1(), x2_ + v.x2(), x3_ + v.x3());
}
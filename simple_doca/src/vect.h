//=============================================================================
// vect.h
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Class description of a 3 space vector.
//=============================================================================

# ifndef _NIUV_LIB_VERT_H_
# define _NIUV_LIB_VERT_H_ 

#include "point.h"
#include <math.h>

///////////////////////////////////////////////////////////////////////////////
// Class Vect
//   Provides storage and operations for vectors in 3-space
class Vect
{
 public:
  Vect();
  Vect(double x1, double x2, double x3);
  // initializes a vector pointing from Point p to q haveing a magnitude the
  //   distance between p and q
  Vect(Point p, Point q);

  double x1() const;
  double x2() const;
  double x3() const;
    
  void set_x1(double x1);
  void set_x2(double x2);
  void set_x3(double x3);

  // returns the euclidean norm of the vector
  double norm() const;
  
  // Returns a Vect whose values are the addition of itself and vector v
  Vect add(Vect v) const;
  // Returns a Vect whose values are the difference of itself and vector v
  Vect subtract(Vect v) const;
  
  // returns the dot product of itself with vector v
  double dot(Vect v) const;
  // returns a vector which is itself multiplied by a
  Vect multiply_scalar(double a);
  // returns the cross product of itself with vector v
  Vect cross(Vect v) const;
  
private:
  // vector components
  double x1_;
  double x2_;
  double x3_;
}; // Class Vect


// see above for function descriptions
inline Vect::Vect() {
  x1_ = 0;
  x2_ = 0;
  x3_ = 0;
}; 
inline Vect::Vect(double x1, double x2, double x3) {
  x1_ = x1;
  x2_ = x2;
  x3_ = x3;
};
inline double Vect::x1() const { return x1_; }
inline double Vect::x2() const { return x2_; }
inline double Vect::x3() const { return x3_; }
inline double Vect::norm() const { return sqrt((x1_ * x1_) + (x2_ * x2_) + (x3_ * x3_)); }
inline void Vect::set_x1(double x1) { x1_ = x1; }
inline void Vect::set_x2(double x2) { x2_ = x2; }
inline void Vect::set_x3(double x3) { x3_ = x3; }

  


# endif // _NIUV_LIB_VERT_H_

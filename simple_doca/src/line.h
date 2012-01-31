//=============================================================================
// line.h
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Class description of a Line data type. Includes methods of
//                storing and operating on lines in 3-space. The Line is stored
//                as a point in 3 space and a vector pointing in the direction
//                of the line. If a Line is to be used as a line segment, one
//                endpoint will be at Point p and length will be the magnitude
//                of the directional vector.
//=============================================================================
# ifndef _NIUV_LIB_LINE_H_
# define _NIUV_LIB_LINE_H_

#include "point.h"
#include "vect.h"

///////////////////////////////////////////////////////////////////////////////
// Class Line
//   Provides storage for lines in 3-space. see file description for detail
class Line
{
 public:
  // Constructors
  //   Initializes a Line with endpoint at (0,0,0) with vector [0,0,0]
  Line();
  //   Initializes a Line with endpoint at Point p with vector pointing
  //   from p to q. The magnitude of the vector is the distance from p to q.
  Line(Point p, Point q);
  //   Initializes a Line with an endpoint at (p1,p2,p3) with vector pointing
  //   pointing from (p1,p2,p3) to (q1,q2,q3).
  Line(double p1, double p2, double p3,
       double q1, double q2, double q3);
  // Initializes a Line with endpoint at Point p and vector u
  Line(Point p, Vect u);

  // return the endpoint p
  Point p() const;
  // return the opposite endpoint q
  Point q() const;
  // return the directional vector u
  Vect u() const;
  
  // sets the endpoint p
  void set_p(Point p);
  // sets the endpoint q
  void set_q(Point q);
  // sets the directional vector u
  void set_u(Vect u);

 private:
  Point p_; // endpoint p
  Vect u_;  // directional vector u
}; // Class Line


// see above for function descriptions
inline Line::Line(Point p, Vect u) { p_ = p; u_ = u; };
inline Point Line::p() const { return p_; };
inline Vect Line::u() const { return u_; };
inline void Line::set_p(Point p) { p_ = p; };
inline void Line::set_u(Vect u) {u_ = u;};
inline void Line::set_q(Point q) { u_ = Vect(p_, q); };

# endif // _NIUV_LIB_LINE_H_

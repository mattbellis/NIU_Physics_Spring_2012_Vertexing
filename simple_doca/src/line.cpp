//=============================================================================
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Implementation of functions in class Line. See line.h for 
//                class and function descriptions.
//=============================================================================

#include "line.h"
#include "point.h"
#include "vect.h"

Line::Line() {
  p_ = Point(0,0,0);
  u_ = Vect(0,0,0);
};

// set Point p as the endpoint, use the x1,x2,x3 of Points p and q to
//   initialize the directional vector pointing from p to q. The
//   magnitude of vector u is the distance from point p to q.
Line::Line(Point p, Point q) {
  p_ = p;
  u_ = Vect(q.x1() - p.x1(), q.x2() - p.x2(), q.x3() - p.x3());
};

// similar to Line(Point p, Point q)
//   endpoint p is initialized with at (p1,p2,p3) and the directional
//   vector is initialized pointing from Point at (p1,p2,p3) to Point
//   (q1,q2,q3). The magnitude of the directional vector u is the 
//   distance from (p1,p2,p3) to (q1,q2,q3)
Line::Line(double p1, double p2, double p3,
           double q1, double q2, double q3) {
  p_ = Point(p1, p2, p3);
  u_ = Vect(q1 - p1, q2 - p2, q3 - p3);
};
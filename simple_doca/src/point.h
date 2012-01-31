//=============================================================================
// point.h
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Class description of a Point data type. Includes methods of
//                storing and operating on points in 3 space.
//=============================================================================

# ifndef _NIUV_LIB_POINT_H_
# define _NIUV_LIB_POINT_H_

///////////////////////////////////////////////////////////////////////////////
// Class Point
//  Provides storage of points in 3-space
class Point
{
 public:
  Point();
  Point(double x1, double x2, double x3);
    
  inline double x1() const { return x1_; };
  inline double x2() const { return x2_; };
  inline double x3() const { return x3_; };
    
  inline void set_x1(double x1) { x1_ = x1; };
  inline void set_x2(double x2) { x2_ = x2; };
  inline void set_x3(double x3) { x3_ = x3; };
  
private:
  double x1_;
  double x2_;
  double x3_;
};

inline Point::Point() {
  x1_ = 0;
  x2_ = 0;
  x3_ = 0;  
};
inline Point::Point(double x1, double x2, double x3)  {
    x1_ = x1;
    x2_ = x2;
    x3_ = x3;
  };
# endif // _NIUV_LIB_POINT_H_

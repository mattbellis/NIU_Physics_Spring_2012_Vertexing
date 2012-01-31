///////////////////////////////////////////////////////////////////////////////
// doca.h
// Author: Ken LaBuda <Trace.Op@gmail.com>
// Date of Creation: 2012-01-22
// Description: Calculates the distance of closest approach of two Lines
///////////////////////////////////////////////////////////////////////////////

#ifndef _NIUV_SRC_DOCA_H_
#define _NIUV_SRC_DOCA_H_

#include "line.h"

// returns the distance of closest approach of lines j and k.
//   output is undefined for parallel (and almost parallel) lines
double doca(Line j, Line k);

#endif // _NIUV_SRC_DOCA_H_

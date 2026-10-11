#ifndef PAINTSQ_H
#define PAINTSQ_H

#include "ALL.h"
#include "TOOLSQ.h"

#define XMAX 1000
#define YMAX 1000

void Paint();

struct RGB_t
{
    unsigned char Red, Green, Blue;
};

struct coeffs
{
  double a, b, c;
};

#endif

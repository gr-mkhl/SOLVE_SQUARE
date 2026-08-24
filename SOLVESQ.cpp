#include "SOLVESQ.h"

int SolveLinear(const double a, const double b, double * x);

int SolveLinear(const double a, const double b, double * x)
{
    assert(x != nullptr);
    if (CompareDoubles(a, 0) == EQUAL)
    {
        if (CompareDoubles(b, 0) == EQUAL)
            return INF_ROOTS;
        else
            return NO_ROOTS;
    }
    else
    {
        if (CompareDoubles(b, 0) == EQUAL)
            *x = 0;
        else
            *x = -b / a;
        return ONE_ROOT;
    }
}
int SolveSquare(const double a, const double b, const double c, double* x1, double* x2)
{
    assert(x1 != x2);
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    if (CompareDoubles(a, 0) == EQUAL)
    {
       *x2 = NAN;
       return SolveLinear(b, c, x1);
    }
    else
    {
      double discr = b * b - 4 * a * c;

      if (CompareDoubles(discr, 0) == LESS)
      {
        return NO_ROOTS;
      }
      else if (CompareDoubles(discr, 0) == EQUAL)
      {
        *x1 = -b / (2 * a);
        *x2 = NAN;
        return ONE_ROOT;
      }
      else
      {
        double sqrt_d = sqrt(discr);

        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        if (CompareDoubles(*x1, *x2) == LESS)
            Swap(x1, x2);
        return TWO_ROOTS;
      }
    }
}



#include "SOLVESQ.h"

int SolveLinear(const double a, const double b, double* x);

int SolveSquare(const double a, const double b, const double c,
                double* const x1, double* const x2)
{
    assert(x1);
    assert(x2);
    assert(x1 != x2);

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
        *x1 = *x2 = NAN;
        return NO_ROOTS;
      }
      else if (CompareDoubles(discr, 0) == EQUAL)
      {
        if (CompareDoubles(b, 0) == EQUAL)
            *x1 = 0;
        else
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

int SolveLinear(const double a, const double b, double* const x)
{
    assert(x);

    if (CompareDoubles(a, 0) == EQUAL)
    {
        if (CompareDoubles(b, 0) == EQUAL)
        {
             *x = NAN;
             return INF_ROOTS;
        }

        else
        {
            *x = NAN;
            return NO_ROOTS;
        }
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



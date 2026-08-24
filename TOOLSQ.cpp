#include "TOOLSQ.h"

int CompareDoubles( const double a, const double b)     //возвращает 0, если числа равны. 1, если первое число больше. -1, если первое число меньше.
{
    if ((a - b) > EPS)
        return MORE;
    else if ((a - b) < -EPS)
        return LESS;
    else
        return EQUAL;
}

void CleanBuffer()
{
    int n;

    while ((n = getchar()) != '\n' && n != EOF)
        continue;
}

int MyRandInt(int from, int to)
{
    return (rand() % (to - from)) + from;
}

void Swap(double * a, double * b)
{
  double * temp;

  temp = a;
  a = b;
  b = temp;

}


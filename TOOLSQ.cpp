#include "TOOLSQ.h"

int CompareDoubles(const double a, const double b)     //возвращает 0, если числа равны. 1, если первое число больше. -1, если первое число меньше.
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
    int n = 0;

    while ((n = getchar()) != '\n' && n != EOF)
        continue;
}

int MyRandInt(const int from, const int to)
{
    return (rand() % (to - from)) + from;
}

void Swap(const double* a, const double* b)
{
  const double * temp = NULL;

  temp = a;
  a = b;
  b = temp;
}




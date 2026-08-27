#ifndef INOUTSQ_H
#define INOUTSQ_H

#include "ALL.h"
#include "SOLVESQ.h"
#include "TOOLSQ.h"

bool GetSquareCoeffs(double* a, double* b, double* c);
void PrintRoots(const double a, const double b, const double c,
                const int numOfRoots, const double root1, const double root2);
void PrintTestInfo(const TestSquare* const tests, const int mas_len);
void PrintSqEq(const double a, const double b, const double c);
//void ScanSqEq(double* a, double* b, double* c); это дерьмо еще в разработке

#endif


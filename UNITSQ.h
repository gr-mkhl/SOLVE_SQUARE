#ifndef UNITSQ_H
#define UNITSQ_H

#include "ALL.h"
#include "SOLVESQ.h"

void GenerateSqVietTests(TestSquare* const tests, const int num);
void RunOneTest(const TestSquare test);
void RunAllTests(const TestSquare* const tests, const int num);
void ClearSqTests(TestSquare* tests, int num);

#endif

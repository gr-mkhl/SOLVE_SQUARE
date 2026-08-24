#ifndef UNITSQ_H
#define UNITSQ_H

#include "ALL.h"
#include "SOLVESQ.h"

void GenerateSqVietTests(TestSquare * tests, int num);
void RunOneTest(const TestSquare test);
void RunAllTests(TestSquare * tests, int num);
void ClearSqTests(TestSquare * tests, int num);

#endif

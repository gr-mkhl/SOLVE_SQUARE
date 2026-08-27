#ifndef UNITSQ_H
#define UNITSQ_H

#include "ALL.h"
#include "SOLVESQ.h"

void GenerateSqVietTests(TestSquare* const tests, const int mas_len);
void RunOneTest(const TestSquare test);
void RunAllTests(const TestSquare* const tests, const int mas_len);
void ClearSqTests(TestSquare* tests, const int mas_len);

#endif

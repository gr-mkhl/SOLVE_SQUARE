#ifndef FILESQ_H
#define FILESQ_H

#include "ALL.h"

int ReadSqTestsFromFile(TestSquare* const tests, const int mas_len);
int WriteSqTestsToFile(const TestSquare* const tests, const int mas_len);
//bool WriteOneTestToFile(FILE* f, const TestSquare test);

#endif

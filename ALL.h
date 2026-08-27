#ifndef ALL_H
#define ALL_H

#include "TXLib.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define RETURN_COLOR "\033[0m"

#define EPS 1E-10
#define CORRECT_INPUT 1
#define INCORRECT_INPUT 0
#define MAS_LEN 10000
#define FILE_SIZE 50
#define FROM -10000
#define TO 10000
#define INFILENAME "in.txt"
#define OUTFILENAME "out.txt"
#define EXIT 'q'


enum NUMOFROOTS {INF_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2};

enum SIGNS {LESS = -1, EQUAL = 0, MORE = 1};

struct TestSquare
{
    double a, b, c;
    double x1Ref, x2Ref;
    int id;
    int nRootsRef;
};

#endif

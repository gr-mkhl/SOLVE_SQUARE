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

#define EPS 1E-10
#define CORRECT_INPUT 1
#define INCORRECT_INPUT 0
#define MAS_LEN 30
#define FILE_SIZE 50
#define FROM -100
#define TO 100
#define INFILENAME "in.txt"
#define OUTFILENAME "out.txt"
#define EXIT 'q'
#define MENU "menu:\n"                                             \
            "0 - solve square equation\n"                          \
            "1 - generate an array of tests randomly\n"            \
            "2 - clear the array of tests\n"                       \
            "3 - save the array of tests to a file\n"              \
            "4 - load the array of tests from a file\n"            \
            "5 - run unit-testing on the array of tests\n"         \
            "q - exit the program\n"

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

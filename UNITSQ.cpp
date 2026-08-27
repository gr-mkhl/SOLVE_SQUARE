#include "UNITSQ.h"

void printINFGood(const int a);
void printNANGood(const double a);

void RunOneTest(const TestSquare test)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(test.a, test.b, test.c, &x1, &x2);

    if (nRoots != test.nRootsRef || (CompareDoubles(test.x1Ref, x1) || CompareDoubles(test.x2Ref, x2)))
    {
        printf(COLOR_RED "TEST ¹%d FAILED:\n"
        "EXPECTED:\n Number of roots = ", test.id);
        printINFGood(test.nRootsRef);
        printf("Root1 = ");
        printNANGood(test.x1Ref);
        printf("Root2 = ");
        printNANGood(test.x2Ref);
        printf("\nRECEIVED:\n Number of roots = ");
        printINFGood(nRoots);
        printf("Root1 = ");
        printNANGood(x1);
        printf("Root2 = ");
        printNANGood(x2);
        printf(RETURN_COLOR "\n");
    }
    else
    {
        printf(COLOR_GREEN "TEST ¹%d PASSED:\n"
        "EXPECTED:\n Number of roots = ", test.id);
        printINFGood(test.nRootsRef);
        printf("Root1 = ");
        printNANGood(test.x1Ref);
        printf("Root2 = ");
        printNANGood(test.x2Ref);
        printf("\nRECEIVED:\n Number of roots = ");
        printINFGood(nRoots);
        printf("Root1 = ");
        printNANGood(x1);
        printf("Root2 = ");
        printNANGood(x2);
        printf(RETURN_COLOR "\n");
    }
}

void RunAllTests(const TestSquare* const tests, const int mas_len)
{
    assert(tests);

    for (int i = 0; i < mas_len; i++)
    {
        RunOneTest(tests[i]);
    }
}



void GenerateSqVietTests(TestSquare* const tests, const int mas_len)
{
    assert(tests);

    for (int i = 0; i < mas_len; i++)
    {
      tests[i].id = (i + 1);
      tests[i].a = 1;
      tests[i].x1Ref = MyRandInt(FROM, TO);
      tests[i].x2Ref = MyRandInt(FROM, TO);
      tests[i].nRootsRef = TWO_ROOTS;
      if (tests[i].x1Ref < tests[i].x2Ref)
          Swap(&tests[i].x1Ref, &tests[i].x2Ref);
      if (CompareDoubles(tests[i].x1Ref,tests[i].x2Ref) == EQUAL)
      {
         tests[i].nRootsRef = ONE_ROOT;
         tests[i].x2Ref = NAN;
      }
      tests[i].b = -(tests[i].x1Ref + tests[i].x2Ref);
      tests[i].c = tests[i].x1Ref * tests[i].x2Ref;
    }
}

void ClearSqTests(TestSquare* const tests, const int mas_len)
{
    assert(tests);

    for (int i = 0; i < mas_len; i++)
    {
      tests[i].id = (i + 1);
      tests[i].nRootsRef = INF_ROOTS;
      tests[i].a = 0;
      tests[i].b = 0;
      tests[i].c = 0;
      tests[i].x1Ref = NAN;
      tests[i].x2Ref = NAN;
    }
}

void printNANGood(const double a)
{
    if (isnan(a))
        printf("%-10s", "NAN");
    else
        printf("%-10lg", a);

}

void printINFGood(const int a)
{
    if (CompareDoubles(a, INF_ROOTS) == EQUAL)
        printf("%-10s", "INF");
    else
        printf("%-10d", a);
}

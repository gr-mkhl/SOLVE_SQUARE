#include "UNITSQ.h"

void FprintINFGood(FILE* F, const int a);
void FprintNANGood(FILE* F, const double a);
void PrintResTest(FILE* F, const TestSquare test, const int nRoots,
                  const double x1, const double x2);


void RunOneTest(FILE* f_good, FILE* f_bad, const TestSquare test)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(test.a, test.b, test.c, &x1, &x2);

    if (nRoots != test.nRootsRef || (CompareDoubles(test.x1Ref, x1) || CompareDoubles(test.x2Ref, x2)))
    {
        if (f_bad == stdout)
            fprintf(f_bad, COLOR_RED);
        fprintf(f_bad, "TEST ¹%d FAILED:\n", test.id);
        PrintResTest(f_bad, test, nRoots, x1, x2);
        fprintf(f_bad, RETURN_COLOR);
    }
    else
    {
        if (f_good == stdout)
            fprintf(f_good, COLOR_GREEN);
        fprintf(f_good, "TEST ¹%d PASSED:\n", test.id);
        PrintResTest(f_good, test, nRoots, x1, x2);
        fprintf(f_good, RETURN_COLOR);
    }
}

void RunAllTests(bool console, const TestSquare* const tests, const int mas_len)
{
    assert(tests);

    FILE* f_good = console ? stdout : fopen(CORRECT_FILE, "w");
    assert(f_good);

    FILE* f_bad = console ? stdout : fopen(INCORRECT_FILE, "w");
    assert(f_bad);

    for (int i = 0; i < mas_len; i++)
        RunOneTest(f_good, f_bad, tests[i]);

    if (f_good != stdout && f_bad != stdout)
    {
        fclose(f_good);
        fclose(f_bad);
    }
}



void GenerateSqVietTests(TestSquare* const tests, const int mas_len)
{
    assert(tests);

    for (int i = 0; i < mas_len; i++)
    {
      tests[i].id = (i + 1);
      tests[i].a = MyRandDouble(FROM, TO);
      tests[i].x1Ref = MyRandDouble(FROM, TO);
      tests[i].x2Ref = MyRandDouble(FROM, TO);
      tests[i].nRootsRef = TWO_ROOTS;
      if (tests[i].x1Ref < tests[i].x2Ref)
          Swap(&tests[i].x1Ref, &tests[i].x2Ref);
      if (CompareDoubles(tests[i].x1Ref,tests[i].x2Ref) == EQUAL)
      {
         tests[i].nRootsRef = ONE_ROOT;
         tests[i].x2Ref = NAN;
      }
      tests[i].b = -(tests[i].x1Ref + tests[i].x2Ref) * tests[i].a;
      tests[i].c = tests[i].x1Ref * tests[i].x2Ref * tests[i].a;
    }
}

void PrintResTest(FILE* F, const TestSquare test, const int nRoots,
                  const double x1, const double x2)
{
    fprintf(F, "EXPECTED:\n Number of roots = ");
    FprintINFGood(F, test.nRootsRef);
    fprintf(F, "Root1 = ");
    FprintNANGood(F, test.x1Ref);
    fprintf(F, "Root2 = ");
    FprintNANGood(F, test.x2Ref);
    fprintf(F, "\nRECEIVED:\n Number of roots = ");
    FprintINFGood(F, nRoots);
    fprintf(F, "Root1 = ");
    FprintNANGood(F, x1);
    fprintf(F, "Root2 = ");
    FprintNANGood(F, x2);
    fprintf(F, "\n\n");
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

void FprintNANGood(FILE* F, const double a)
{
    assert(F);

    if (isnan(a))
        fprintf(F, "%-10s", "NAN");
    else
        fprintf(F, "%-10lg", a);

}

void FprintINFGood(FILE* F, const int a)
{
    assert(F);

    if (CompareDoubles(a, INF_ROOTS) == EQUAL)
        fprintf(F, "%-10s", "INF");
    else
        fprintf(F, "%-10d", a);
}

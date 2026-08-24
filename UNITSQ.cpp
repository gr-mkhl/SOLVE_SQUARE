#include "UNITSQ.h"

void RunOneTest(const TestSquare test)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(test.a, test.b, test.c, &x1, &x2);

    if (CompareDoubles(nRoots, test.nRootsRef) || ((CompareDoubles(test.x1Ref, x1) || CompareDoubles(test.x2Ref, x2)) && (CompareDoubles(test.x1Ref, x2) || CompareDoubles(test.x2Ref, x1))))
        printf("TEST ¹%d FAILED:\n"
        "EXPECTED:\n Number of roots = %-7d, Root1 = %-7lg, Root2 = %-7lg\n"
        "RECEIVED:\n Number of roots = %-7d, Root1 = %-7lg, Root2 = %-7lg\n\n",
        test.id, test.nRootsRef, test.x1Ref, test.x2Ref, nRoots, x1, x2);
    else
        printf("TEST ¹%d PASSED:\n"
        "EXPECTED:\n Number of roots = %-7d, Root1 = %-7lg, Root2 = %-7lg\n"
        "RECEIVED:\n Number of roots = %-7d, Root1 = %-7lg, Root2 = %-7lg\n\n",
        test.id, test.nRootsRef, test.x1Ref, test.x2Ref, nRoots, x1, x2);
}

void RunAllTests(TestSquare * tests, int num)
{
    assert(tests);

    for (int i = 0; i < num; i++)
        RunOneTest(tests[i]);
}



void GenerateSqVietTests(TestSquare * tests, int num)
{
    assert(tests);

    for (int i = 0; i < num; i++)
    {
      tests[i].id = (i + 1);
      tests[i].a = 1;

      tests[i].x1Ref = MyRandInt(FROM, TO);
      tests[i].x2Ref = MyRandInt(FROM, TO);
      tests[i].nRootsRef = 2;

      tests[i].b = -(tests[i].x1Ref + tests[i].x2Ref);
      tests[i].c = tests[i].x1Ref * tests[i].x2Ref;
    }
}

void ClearSqTests(TestSquare * tests, int num)
{

    for (int i = 0; i < num; i++)
    {
      tests[i].id = (i + 1);
      tests[i].nRootsRef = 0;
      tests[i].a = NAN;
      tests[i].b = NAN;
      tests[i].c = NAN;
      tests[i].x1Ref = NAN;
      tests[i].x2Ref = NAN;
    }
}

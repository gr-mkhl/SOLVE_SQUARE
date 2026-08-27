#include "INOUTSQ.h"

bool GetSquareCoeffs(double* a, double* b, double* c)
{
  assert(a);
  assert(b);
  assert(c);
  assert(a != b && b != c && c != a);

  int ch = 0;

  printf("Input coefficients(a b c) or 'q', if you want to finish\n");
  while ((ch = getchar()) != EXIT)
  {
      ungetc(ch, stdin);

      if (scanf("%lg %lg %lg", a, b, c) == 3)
      {
        PrintSqEq(*a, *b, *c);
        CleanBuffer();
        return true;
      }
      else
         printf(COLOR_RED "Incorrect input\n" RETURN_COLOR);

      printf("Input coefficients(a b c) or q, if you want to finish\n");
      CleanBuffer();
  }
  return false;

}


void PrintRoots(const double a, const double b, const double c,
                const int numOfRoots, const double root1, const double root2)
{
  switch (numOfRoots)
  {
    case INF_ROOTS:
        printf("The equation %lgx^2%+lgx%+lg=0 has Infinite roots\n", a, b, c);
        break;
    case NO_ROOTS:
        printf("The equation %lgx^2%+lgx%+lg=0 has No roots\n", a, b, c);
        break;
    case ONE_ROOT:
        printf("The equation %lgx^2%+lgx%+lg=0 has One root: x = %lg\n", a, b, c, root1);
        break;
    case TWO_ROOTS:
        printf("The equation %lgx^2%+lgx%+lg=0 has Two roots: x1 = %lg, x2 = %lg\n", a, b, c, root1, root2);
        break;
    default:
        printf("???\n");
        break;
  }
}

void PrintTestInfo(const TestSquare* const tests, const int mas_len)
{
    assert(tests);

    int test_id = 0, ch = 0;

    printf(COLOR_BLUE "input test's id, or 'q' if you want to finish:\n" RETURN_COLOR);
    while((ch = getchar()) != EXIT)
    {
        scanf("%ud", &test_id);
        assert(test_id > 0 && test_id <= mas_len);

        printf("TEST ¹%d:\na = %lg\nb = %lg\nc = %lg\n", tests[test_id].id, tests[test_id].a, tests[test_id].b, tests[test_id].c);
        switch (tests[test_id].nRootsRef)
        {
        case INF_ROOTS:
            printf("The equation has Infinite roots\n");
            break;
        case NO_ROOTS:
            printf("The equation has No roots\n");
            break;
        case ONE_ROOT:
            printf("The equation has One root:\nx = %lg\n", tests[test_id].x1Ref);
            break;
        case TWO_ROOTS:
            printf("The equation has Two roots:\nx1 = %lg, x2 = %lg\n", tests[test_id].x1Ref, tests[test_id].x2Ref);
            break;
        default:
            printf("???\n");
            break;
        }
        printf(COLOR_BLUE "input test's id, or 'q' if you want to finish:\n" RETURN_COLOR);
        CleanBuffer();
    }
}

void PrintSqEq(const double a, const double b, const double c)
{
    bool stat_a = false, stat_b = false;

    if (CompareDoubles(a, 0) == EQUAL)     //
        ;
    else if (CompareDoubles(a, 1) == EQUAL)
    {
        printf("x^2 ");
        stat_a = true;
    }
    else
    {
        printf("%lg x^2 ", a);
        stat_a = true;
    }

    if (CompareDoubles(b, 0) == EQUAL)
        ;
    else if (CompareDoubles(b, 1) == EQUAL)
    {
        if (stat_a == true)
            printf("+ x ");
        else
            printf("x ");
    }
    else
    {
        if (stat_a == true)
            printf("+ %lgx ", b);
        else
            printf("%lgx ", b);
    }

    if (stat_a == true || stat_b == true)
            printf("+ %lg ", c);
    else
            printf("%lg ", c);
    printf("= 0\n");
}





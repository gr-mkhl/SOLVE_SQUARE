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

      if (scanf("%lg %lg %lg", a, b, c) == 3 && IsBufEmpty())
        return true;
      else
         printf(COLOR_RED "Incorrect input\n" RETURN_COLOR);
      printf("Input coefficients(a b c) or 'q', if you want to finish\n");
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
        printf("The equation: ");
        PrintSqEq(a, b, c);
        printf(" has Infinite roots\n");
        break;
    case NO_ROOTS:
        printf("The equation: ");
        PrintSqEq(a, b, c);
        printf(" has No roots\n");
        break;
    case ONE_ROOT:
        printf("The equation: ");
        PrintSqEq(a, b, c);
        printf(" has One root: x = %lg\n", root1);
        break;
    case TWO_ROOTS:
        printf("The equation: ");
        PrintSqEq(a, b, c);
        printf(" has Two roots: x1 = %lg, x2 = %lg\n", root1, root2);
        break;
    default:
        assert(0);
        break;
  }
}

void PrintTestInfo(const TestSquare* const tests, const int mas_len)
{
    assert(tests);

    int test_id = 0;

    printf(COLOR_BLUE "Input test's id, or any another key if you want to finish:\n" RETURN_COLOR);
    while (scanf("%d", &test_id))
    {
        CleanBuffer();
        if (test_id <= 0 || test_id > mas_len)
        {
          printf(COLOR_RED "FUFUFU, you need input id > 0 and id < %d\n" RETURN_COLOR, mas_len);
          continue;
        }

        printf("TEST №%d:\na = %lg\nb = %lg\nc = %lg\n",
                tests[test_id - 1].id, tests[test_id - 1].a, tests[test_id - 1].b, tests[test_id - 1].c);
        switch (tests[test_id].nRootsRef)
        {
        case INF_ROOTS:
            printf("The equation: ");
            PrintSqEq(tests[test_id - 1].a, tests[test_id - 1].b, tests[test_id - 1].c);
            printf(" has Infinite roots\n");
            break;
        case NO_ROOTS:
            printf("The equation: ");
            PrintSqEq(tests[test_id - 1].a, tests[test_id - 1].b, tests[test_id - 1].c);
            printf(" has No roots\n");
            break;
        case ONE_ROOT:
            printf("The equation: ");
            PrintSqEq(tests[test_id - 1].a, tests[test_id - 1].b, tests[test_id - 1].c);
            printf(" has One root: x = %lg\n", tests[test_id - 1].x1Ref);
            break;
        case TWO_ROOTS:
            printf("The equation: ");
            PrintSqEq(tests[test_id - 1].a, tests[test_id - 1].b, tests[test_id - 1].c);
            printf(" has Two roots: x1 = %lg, x2 = %lg\n", tests[test_id - 1].x1Ref, tests[test_id - 1].x2Ref);
            break;
        default:
            assert(0);
            break;
        }
        printf(COLOR_BLUE "Input test's id, or any another key if you want to finish:" RETURN_COLOR);
    }
    CleanBuffer();
}

void PrintSqEq(const double a, const double b, const double c)
{
    bool stat_a = false, stat_b = false;

    if (CompareDoubles(a, 1) == EQUAL)
    {
        printf("x^2 ");
        stat_a = true;
    }
    else if (CompareDoubles(a, -1) == EQUAL)
    {
        printf("-x^2 ");
        stat_a = true;
    }
    else if (CompareDoubles(a, 0) != EQUAL)
    {
        printf("%lgx^2 ", a);
        stat_a = true;
    }

    if (CompareDoubles(b, 1) == EQUAL)
    {
        if (stat_a == true)
            printf("+ x ");
        else
            printf("x ");
        stat_b = true;
    }
    else if (CompareDoubles(b, -1) == EQUAL)
    {
        if (stat_a == true)
            printf("- x ");
        else
            printf("-x ");
        stat_b = true;
    }
    else if (CompareDoubles(b, 0) == LESS)
    {
        if (stat_a == true)
            printf("- %lgx ", fabs(b));
        else
            printf("%lgx ", b);
        stat_b = true;
    }
    else if (CompareDoubles(b, 0) != EQUAL)
    {
        if (stat_a == true)
            printf("+ %lgx ", b);
        else
            printf("%lgx ", b);
        stat_b = true;
    }

    if (stat_a == true || stat_b == true)
    {
        if (CompareDoubles(c, 0) == LESS)
            printf("- %lg ", fabs(c));
        else
            printf("+ %lg ", c);
    }
    else
       printf("%lg ", c);

    printf("= 0");
}

/*void ScanSqEq(double* a, double* b, double* c)  это дерьмо в разработке
{
    int i = 0, j = 0, n = 0;
    char mas[10][20] = {};

    while (i < 10 && scanf("%s", mas[i]) == 1 && (*mas[i] != '\n') && (*mas[i] != '='))
    {
        i++;
        n++;
    }
    CleanBuffer();
    printf("Всего %d строк\n", n);
    for (i = 0; i < n; i++)
    {
        printf("[%d]: ", i);
        for (j = 0; j < 10; j++)
        {
            printf("%c", mas[i][j]);
        }
        putchar('\n');
    }
}
*/






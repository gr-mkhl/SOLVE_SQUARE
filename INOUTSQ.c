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

bool GetCoeffs(EqCoeffs* const My)
{
  assert(My);

  int i = 0;

  printf("¬ведите коэффициент перед %d-ой степенью многочлена или нажмите любую буквенную клавишу, чтобы закончить\n", i);
  while (scanf("%lg", &(My->Pows[i])) == 1 && i <= POWERS) //TODO: правка левка м€у м€у переименовать + ассреты
  {
    CleanBuffer();
    i++;
    printf("¬ведите коэффициент перед %d-ой степенью многочлена или нажмите любую буквенную клавишу, чтобы закончить\n", i);
  }
  (My->MaxPow) = i - 1;
  CleanBuffer();
  if (My->MaxPow == -1)
    return false;
  return true;
}


void PrintRoots(const TestSquare* const test)
{
  switch (test->nRootsRef)
  {
    case INF_ROOTS:
        printf("The equation: ");
        PrintSqEq(test->a, test->b, test->c);
        printf(" has Infinite roots\n");
        break;

    case NO_ROOTS:
        printf("The equation: ");
        PrintSqEq(test->a, test->b, test->c);
        printf(" has No roots\n");
        break;

    case ONE_ROOT:
        printf("The equation: ");
        PrintSqEq(test->a, test->b, test->c);
        printf(" has One root: x = %lg\n", test->x1Ref);
        break;

    case TWO_ROOTS:
        printf("The equation: ");
        PrintSqEq(test->a, test->b, test->c);
        printf(" has Two roots: x1 = %lg, x2 = %lg\n", test->x1Ref, test->x2Ref);
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
        TestSquare now_test = tests[test_id - 1];
        CleanBuffer();
        if (test_id <= 0 || test_id > mas_len)
        {
          printf(COLOR_RED "FUFUFU, you need input id > 0 and id < %d\n" RETURN_COLOR, mas_len);
          continue;
        }

        printf("TEST є%d:\na = %lg\nb = %lg\nc = %lg\n",
                now_test.id, now_test.a, now_test.b, now_test.c);
        PrintRoots(&now_test);
        printf(COLOR_BLUE "Input test's id, or any another key if you want to finish:" RETURN_COLOR);
    }
    CleanBuffer();
}

void PrintSqEq(const double a, const double b, const double c)
{
    bool stat = false;

    if (CompareDoubles(a, 1) == EQUAL)
    {
        printf("x^2 ");
        stat = true;
    }
    else if (CompareDoubles(a, -1) == EQUAL)
    {
        printf("-x^2 ");
        stat = true;
    }
    else if (CompareDoubles(a, 0) != EQUAL)
    {
        printf("%lgx^2 ", a);
        stat = true;
    }

    if (CompareDoubles(b, 1) == EQUAL)
    {
        if (stat == true)
            printf("+ x ");
        else
            printf("x ");
        stat = true;
    }
    else if (CompareDoubles(b, -1) == EQUAL)
    {
        if (stat == true)
            printf("- x ");
        else
            printf("-x ");
        stat = true;
    }
    else if (CompareDoubles(b, 0) == LESS)
    {
        if (stat == true)
            printf("- %lgx ", fabs(b));
        else
            printf("%lgx ", b);
        stat = true;
    }
    else if (CompareDoubles(b, 0) != EQUAL)
    {
        if (stat == true)
            printf("+ %lgx ", b);
        else
            printf("%lgx ", b);
        stat = true;
    }

    if (stat == true)
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
    printf("¬сего %d строк\n", n);
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






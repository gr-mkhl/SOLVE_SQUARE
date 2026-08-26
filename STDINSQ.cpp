#include "STDINSQ.h"

int GetSquareCoeffs(double* a, double* b, double* c);
void PrintRoots(const double a, const double b, const double c, const int numOfRoots, const double root1, const double root2);

int MenuSolveSquare()
{
  double root1 = 0, root2 = 0;
  double a = 0, b = 0, c = 0;
  int status = INCORRECT_INPUT, n_roots = 0;

  while ((status = GetSquareCoeffs(&a, &b, &c)) == CORRECT_INPUT)
  {
    n_roots = SolveSquare(a, b, c, &root1, &root2);
    PrintRoots(a, b, c, n_roots, root1, root2);
  }
  return 0;
}

int GetSquareCoeffs(double * a, double * b, double * c)
{
  int ch = 0;

  printf("Input coefficients(a b c) or f, if you want to finish\n");
  while ((ch = getchar()) != 'f')
  {
      ungetc(ch, stdin);

      if (scanf("%lg %lg %lg", a, b, c) == 3)
      {
        CleanBuffer();
        return 1;
      }
      else
         printf("Incorrect input\n");

      printf("Input coefficients(a b c) or q, if you want to finish\n");
      CleanBuffer();
  }
  return 0;

}


void PrintRoots(const double a, const double b, const double c, const int numOfRoots, const double root1, const double root2)
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





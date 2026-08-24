#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "ALL.H"
#include "SOLVESQ.cpp"

int main()
{
  double root1 = 0, root2 = 0;
  double a = 0, b = 0, c = 0;
  int status = , n_roots = 0;

  while ((status = GetSquareCoeffs(&a, &b, &c)) == CORRECT_INPUT)
  {
    n_roots = SolveSquare(a, b, c, &root1, &root2);
    PrintRoots(n_roots, root1, root2);
  }
  return 0;
}

int GetSquareCoeffs(double * a, double * b, double * c)
{
  int ch = 0;

  printf("Input coefficients(a b c) or q, if you want to finish\n");
  while ((ch = getchar()) != 'q')
  {
      ungetc(ch, stdin);

      if (scanf("%lg %lg %lg", a, b, c) == 3 && getchar() == '\n')
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


void PrintRoots(const int n, const double root1, const double root2)
{
  switch (n)
  {
    case INF_ROOTS:
        printf("Infinite roots\n");
        break;
    case NO_ROOTS:
        printf("No roots\n");
        break;
    case ONE_ROOT:
        printf("One root: root = %lg\n", root1);
        break;
    case TWO_ROOTS:
        printf("Two roots: root1 = %lg, root2 = %lg\n", root1, root2);
        break;
    default:
        printf("???\n");
        break;
  }
}





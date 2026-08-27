#include "ALL.h"
#include "UNITSQ.h"
#include "FILESQ.h"
#include "INOUTSQ.h"

#define MENU COLOR_BLUE "menu:\n"                                  \
            "0 - solve square equation\n"                          \
            "1 - generate an array of tests randomly\n"            \
            "2 - clear the array of tests\n"                       \
            "3 - save the array of tests to a file\n"              \
            "4 - load the array of tests from a file\n"            \
            "5 - run unit-testing on the array of tests\n"         \
            "6 - print test info\n"                                \
            "q - exit the program\n" RETURN_COLOR

void menu(TestSquare* const tests);
bool MenuSolveSquare();

int main(int argc, char* argv[])
{
    TestSquare tests[MAS_LEN] = {
                                    {0, 0, 0, NAN, NAN, 1, -1},
                                    {0, 0, 1, NAN, NAN, 2, 0},
                                    {0, 1, 0, 0, NAN, 3, 1},
                                    {0, 1, 1, -1, NAN, 4, 1},
                                    {1, 0, 0, 0, NAN, 5, 1},
                                    {1, 0, 1, NAN, NAN, 6, 0},
                                    {1, 1, 0, -1, 0, 7, 2},
                                    {1, 1, 0, 0, -1, 8, 2},
                                    {1, 1, 1, NAN, NAN, 9, 0}
                                };
    if (argc < 2)
        menu(tests);
    else
        printf(COLOR_RED "NO, AHAHAHAHAHAHAHAHAHA ZZZZZZZZZZZZZZZ GOYDA, %s\n" RETURN_COLOR, argv[1]);
    return 0;
}

bool MenuSolveSquare()
{
  double root1 = 0, root2 = 0;
  double a = 0, b = 0, c = 0;
  bool status = false;
  int n_roots = 0;

  while ((status = GetSquareCoeffs(&a, &b, &c)) == true)
  {
    n_roots = SolveSquare(a, b, c, &root1, &root2);
    printf("\n\n%d\n\n", n_roots);
    PrintRoots(a, b, c, n_roots, root1, root2);
  }
  return 0;
}

void menu(TestSquare* const tests)
{
    assert(tests);

    int ch = 0;

    printf(MENU);
    while ((ch = getchar()) != EXIT)
    {
        switch(ch)
        {
            case '0':
                MenuSolveSquare();
                break;
            case '1':
                GenerateSqVietTests(tests, MAS_LEN);
                printf("The generation was successful\n");
                break;
            case '2':
                ClearSqTests(tests, MAS_LEN);
                printf("The cleaning was successful\n");
                break;
            case '3':
                WriteSqTestsToFile(tests, MAS_LEN);
                printf("Saving to file was successful\n");
                break;
            case '4':
                ReadSqTestsFromFile(tests, MAS_LEN);
                printf("Reading from file was successful\n");
                break;
            case '5':
                RunAllTests(tests, MAS_LEN);
                printf("Unit testing is completed\n");
                break;
            case '6':
                PrintTestInfo(tests, MAS_LEN);
                break;
            case EXIT:
                printf("The program has been completed.\nGoodbye.\n");
                break;
            default:
                printf(COLOR_RED "!!!Invalid input!!!\n" RETURN_COLOR);
                break;
        }
            printf(MENU);
            CleanBuffer();
    }
}

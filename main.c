#include "ALL.h"
#include "UNITSQ.h"
#include "FILESQ.h"
#include "INOUTSQ.h"
#include "PAINTSQ.h"

#define MENU COLOR_BLUE "menu:\n"                                  \
            "0 - Solve square equation\n"                          \
            "1 - Generate an array of tests randomly\n"            \
            "2 - Clear the array of tests\n"                       \
            "3 - Save the array of tests to a file\n"              \
            "4 - Load the array of tests from a file\n"            \
            "5 - Run unit-testing on the array of tests\n"         \
            "6 - Print test info\n"                                \
            "7 - Pls try to scan coeffs\n"                         \
            "8 - Draw eqquation's grafik\n"                        \
            "q - Exit the program\n" RETURN_COLOR

void menu(TestSquare* const tests);
bool MenuSolveSquare();

int main(int argc, char* argv[])
{
    Paint();

    /*
    TestSquare tests[MAS_LEN] = {
                                    {.id = 1,  .nRootsRef = INF_ROOTS, .a = 0, .b = 0, .c = 0,  .x1Ref = NAN, .x2Ref = NAN},
                                    {.id = 2,  .nRootsRef = NO_ROOTS,  .a = 0, .b = 0, .c = 1,  .x1Ref = NAN, .x2Ref = NAN},
                                    {.id = 3,  .nRootsRef = ONE_ROOT,  .a = 0, .b = 1, .c = -7, .x1Ref = 0,   .x2Ref = NAN},
                                    {.id = 4,  .nRootsRef = ONE_ROOT,  .a = 0, .b = 1, .c = 1,  .x1Ref = -1,  .x2Ref = NAN},
                                    {.id = 5,  .nRootsRef = ONE_ROOT,  .a = 4, .b = 0, .c = 0,  .x1Ref = 0,   .x2Ref = NAN},
                                    {.id = 6,  .nRootsRef = NO_ROOTS,  .a = 1, .b = 0, .c = 1,  .x1Ref = NAN, .x2Ref = NAN},
                                    {.id = 7,  .nRootsRef = TWO_ROOTS, .a = 1, .b = 1, .c = 0,  .x1Ref = 0,   .x2Ref = -1 },
                                    {.id = 8,  .nRootsRef = TWO_ROOTS, .a = 1, .b = 1, .c = 0,  .x1Ref = 0,   .x2Ref = -1 },
                                    {.id = 9,  .nRootsRef = NO_ROOTS,  .a = 1, .b = 1, .c = 1,  .x1Ref = NAN, .x2Ref = NAN},
                                    {.id = 10, .nRootsRef = TWO_ROOTS, .a = 3, .b = 1, .c = 0,  .x1Ref = 0,   .x2Ref = -1 },
                                    {.id = 11, .nRootsRef = TWO_ROOTS, .a = 1, .b = 4, .c = 0,  .x1Ref = 0,   .x2Ref = -1 },
                                    {.id = 12, .nRootsRef = ONE_ROOT,  .a = 1, .b = 1, .c = -7, .x1Ref = NAN, .x2Ref = NAN}

                                };
    if (argc < 2)
        menu(tests);
    else
        while(true)
        {
            for (int i = 0; i < 15; i++)
                printf(COLOR_RED "%s\t" RETURN_COLOR, argv[1]);
            putchar('\n');

    */
    return 0;
}

void menu(TestSquare* const tests)
{
    assert(tests);

    int ch = 0;

    printf(MENU);
    while ((ch = getchar()) != EXIT)
    {
        CleanBuffer();
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
                printf("Press 'c' if you want to see results in console\n"
                        "and press 'f' if you want to save them in files\n");
                if ((ch = getchar()) == 'c')
                    RunAllTests(true, tests, MAS_LEN);
                else if (ch == 'f')
                    RunAllTests(false, tests, MAS_LEN);
                else
                {
                    printf(COLOR_RED "!!!Invalid input!!!\n" RETURN_COLOR);
                    continue;
                }
                CleanBuffer();
                printf("Unit testing is completed\n");
                break;
            case '6':
                PrintTestInfo(tests, MAS_LEN);
                break;
            case '7':
            {
                //double a = 0, b = 0, c = 0;
                //ScanSqEq(&a, &b, &c);  */
                printf("Sorry, this feature is still in development\n");
                break;
            }
            case EXIT:
                printf("The program has been completed.\nGoodbye.\n");
                break;
            default:
                printf(COLOR_RED "!!!Invalid input!!!\n" RETURN_COLOR);
                break;
        }
            printf(MENU);
    }
}

bool MenuSolveSquare()
{
  TestSquare Eq = {};

  while (GetSquareCoeffs(&Eq.a, &Eq.b, &Eq.c) == true)
  {
    Eq.nRootsRef = SolveSquare(Eq.a, Eq.b, Eq.c, &Eq.x1Ref, &Eq.x2Ref);
    PrintRoots(&Eq);
  }
  return 0;
}

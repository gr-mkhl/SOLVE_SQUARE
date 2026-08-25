#include "ALL.h"
#include "UNITSQ.h"
#include "FILESQ.h"

void menu(TestSquare* const tests);

int main()  //исправить вывод пустых тестов
{
    TestSquare tests[MAS_LEN] = {};

    menu(tests);
    return 0;
}

void menu(TestSquare* const tests)
{
    int ch = 0;

    printf(MENU);
    while ((ch = getchar()) != EXIT)
    {
        switch(ch)
        {
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
            case EXIT:
                break;
                printf("The program has been completed.\nGoodbye.\n");
            default:
                printf("!!!Invalid input!!!\n");
                break;
        }
            printf(MENU);
            CleanBuffer();
    }
}

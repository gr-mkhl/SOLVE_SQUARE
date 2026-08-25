#include "ALL.h"
#include "UNITSQ.h"
#include "FILESQ.h"

int main()
{
    TestSquare tests[MAS_LEN] = {};
    int ch = 0;

    printf(MENU);
    while ((ch = getchar()) != EXIT)
    {
        switch(ch)
        {
            case '1':
                GenerateSqVietTests(tests, MAS_LEN);
                break;
            case '2':
                ClearSqTests(tests, MAS_LEN);
                break;
            case '3':
                WriteSqTestsToFile(tests, MAS_LEN);
                break;
            case '4':
                ReadSqTestsFromFile(tests, MAS_LEN);
                break;
            case '5':
                RunAllTests(tests, MAS_LEN);
                break;
            case EXIT:
                break;
            default:
                printf("!!!Invalid input!!!\n");
             printf(MENU);
             ClearBuffer();
        }
    }
    return 0;
}

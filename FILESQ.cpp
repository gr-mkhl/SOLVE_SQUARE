#include "FILESQ.h"

bool MakeFileName(char* const filename, const unsigned int max_str);
void WriteOneSqTestToFile(FILE* f, const TestSquare* const tests);

bool MakeFileName(char* filename, const unsigned int max_str)
{
    assert(filename);

    printf("Input file name:\n");
    bool status = scanf("%s", filename);
    assert(status);

    if (max_str < strlen(filename) + strlen(".txt") + 1 /* символ '\0' */)
        return false;
    if (strstr(filename, ".txt") == NULL)
        strcat(filename, ".txt");
    return true;
}

int ReadSqTestsFromFile(TestSquare* const tests, const int mas_len)                 //тут надо бы чето придумать с обработкой ошибок
{
    assert(tests);

    char filename[FILE_SIZE] = {};
    bool status = MakeFileName(filename, FILE_SIZE);
    assert(status);

    FILE * f = fopen(filename, "r");
    assert(f);

    int i = 0;
    while (fscanf(f, "%d %lg %lg %lg %d",&tests[i].id, &tests[i].a, &tests[i].b, &tests[i].c, &tests[i].nRootsRef) == 5 && i < mas_len)
    {
        assert(0 <= i && i < mas_len);

        switch(tests[i].nRootsRef)
        {
            case ONE_ROOT:

                fscanf(f, "%lg", &tests[i].x1Ref);
                tests[i].x2Ref = NAN;
                break;
            case TWO_ROOTS:
                fscanf(f, "%lg %lg\n", &tests[i].x1Ref, &tests[i].x2Ref);
                break;
            case INF_ROOTS:
                tests[i].x1Ref = tests[i].x2Ref = NAN;
                break;
            case NO_ROOTS:
                tests[i].x1Ref = tests[i].x2Ref = NAN;
                break;
            default:
                assert(0);
        }
        i++;
    }
    fclose(f);
    return i;
}

int WriteSqTestsToFile(const TestSquare* const tests, const int mas_len)
{
    assert(tests);

    char filename[FILE_SIZE] = {};
    bool status = false;
    status = MakeFileName(filename, FILE_SIZE);
    assert(status);

    FILE* f = fopen(filename, "w");
    assert(f);


    int i = 0;
    for (i = 0; i < mas_len; i++)
    {
        WriteOneSqTestToFile(f, &tests[i]);
    }
    fclose(f);
    return i;
}


void WriteOneSqTestToFile(FILE* f, const TestSquare* const test)
{
    assert(f);

    fprintf(f, "%d %lg %lg %lg %d ",test->id, test->a, test->b, test->c, test->nRootsRef);
    switch(test->nRootsRef)
    {
        case ONE_ROOT:
            fprintf(f, "%lg\n", test->x1Ref);
            break;
        case TWO_ROOTS:
            fprintf(f, "%lg %lg\n", test->x1Ref, test->x2Ref);
            break;
        case NO_ROOTS:
            fprintf(f, "\n");
            break;
        case INF_ROOTS:
            fprintf(f, "\n");
            break;
        default:
            assert(0);
            break;
    }
}


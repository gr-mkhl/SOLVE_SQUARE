#include "FILESQ.h"

int MakeFileName(char * filename, unsigned int max_str);

int MakeFileName(char * filename, unsigned int max_str)
{
    printf("Input file name:\n");
    scanf("%s", filename);
    if (max_str < strlen(filename) + strlen(".txt") + 1 /* символ '\0' */)
        return 0;
    if (strstr(filename, ".txt"))
        ;
    else
    {
        strcat(filename, ".txt");
    }
    return 1;
}

int ReadSqTestsFromFile(TestSquare * tests, int mas_len)
{
    assert(tests);


    char filename[FILE_SIZE] = {};

    assert(MakeFileName(filename, FILE_SIZE));

    FILE * f = fopen(filename, "r");
    assert(f);

    int i = 0;
    while (fscanf(f, "%d %lg %lg %lg %d",&tests[i].id, &tests[i].a, &tests[i].b, &tests[i].c, &tests[i].nRootsRef) == 5 && i < mas_len)
    {
        switch(tests[i].nRootsRef)
        {
            case 1:
                fscanf(f, "%lg", &tests[i].x1Ref);
                tests[i].x2Ref = NAN;
                break;
            case 2:
                fscanf(f, "%lg %lg\n", &tests[i].x1Ref, &tests[i].x2Ref);
                break;
            default:
                tests[i].x1Ref = tests[i].x2Ref = NAN;
        }
        i++;
    }
    fclose(f);
    return i;

}

int WriteSqTestsToFile(TestSquare * tests, int mas_len)
{
    assert(tests);


    char filename[FILE_SIZE] = {};

    assert(MakeFileName(filename, FILE_SIZE));


    FILE * f = fopen(filename, "w");
    assert(f);

    int i = 0;
    for (; i < mas_len; i++)
    {
        fprintf(f, "%d %lg %lg %lg %d ",tests[i].id, tests[i].a, tests[i].b, tests[i].c, tests[i].nRootsRef);
        switch(tests[i].nRootsRef)
        {
            case 1:
                fprintf(f, "%lg %s\n", tests[i].x1Ref, "NAN");
                break;
            case 2:
                 fprintf(f, "%lg %lg\n", tests[i].x1Ref, tests[i].x2Ref);
                 break;
            default:
                fprintf(f, "%s %s\n", "NAN", "NAN");
        }
    }
    fclose(f);
    return i;
}




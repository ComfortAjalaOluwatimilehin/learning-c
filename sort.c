#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b)
{

    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    char *name[127]; // pointer variable which will hold a value of type 'char'. Thus name is an address => &name[0]
    // https://stackoverflow.com/a/1088667/5386933
    char *tmp[200][127] = {
        "",
    };

    int count = 0;
    int i = 0, j;
    // scanf returns the number of values it was able to read
    while (scanf("%s[^\n]", name) == 1)
    {
        tmp[count] = name;

        count = count + 1;
    }

    int m;

    //  qsort(array, n_array, sizeof(const char *), compare);

    for (m = 0; m < 5; m++)
    {
        printf("%i %s \n", m, tmp[m]);
    }
    return 0;
}
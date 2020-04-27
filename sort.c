#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int myCompare(const void *a, const void *b)
{

    // setting up rules for comparison
    return strcmp(*(const char **)a, *(const char **)b);
}
void sort(const char *arr[], int n)
{
    // calling qsort function to sort the array
    // with the help of Comparator
    qsort(arr, n, sizeof(const char *), myCompare);
}

int main()
{
    char src[40][127];
    //what would happen if you used src[127]?

    int count = 0;
    // scanf returns the number of values it was able to read
    while (scanf("%s[^\n]", src + count) == 1)
    {

        count = count + 1;
    }
    const char * names[count];
    for (int i = 0; i < count; i++)
    {

        names[i] = src[i];
    }
    int n = sizeof(names) / sizeof(names[0]);
    sort(names, count);
    for (int i = 0; i < count; i++)
    {
        fprintf(stdout,"%s\n", names[i]);
        ///fprintf(stdout, "\n");
    }
    return 0;
}
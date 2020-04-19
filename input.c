#include <stdio.h>
#include <string.h>
int main()
{
    char name[10];
    char filter = 'A';
    // scanf returns the number of values it was able to read
    while (scanf("%s[^\n]", &name) == 1)
    {

        printf("%s\n", name);
    }
    return 0;
    return 0;
}
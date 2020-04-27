#include <stdio.h>
#include <string.h>
int main()
{
    char name[127];
    while (scanf("%s[^\n]", &name) == 1)
    {

        printf("%s\n", name);
    }
    return 0;
    return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
    char name[127];
    char filter = 'B';
    // scanf returns the number of values it was able to read
    while (scanf("%s[^\n]", &name) == 1)
    {
        char firstchar = name[0];
        char uppercase = toupper(firstchar);
        if (uppercase != filter)
        {
            fprintf(stderr, "%s\n", name);
        }
        else
        {
            fprintf(stdout, "%s\n", name);
        }
    }
    return 0;
}
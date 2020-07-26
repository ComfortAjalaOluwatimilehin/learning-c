#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main()
{
 char *my_env[] = {"FOOD=donuts", NULL};
    if(execle("code.exe", "code.exe", "cream", NULL, my_env ) == -1){

           fprintf(stderr, "Something went wrong: %s\n", strerror(errno));
           return 1; 
    }
    return 0;
}
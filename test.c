#include <stdio.h>
#include <string.h>

int int main()
{
    char a = 'A';
    printf("The size of char <a> is %ld, while the size of a char is %ld \n", sizeof(a), sizeof(char));

    char *b = "B";
    printf("The size of a pointer variable <b> is %ld, while the size of a pointer to a string is %ld \n", sizeof(b), sizeof(char *));

    char *message = "My name is Comfort Ajala";
    printf("The size of a pointer variable <message> is %ld, while the size of a pointer to a string is %ld \n", sizeof(message), sizeof(char *));

    char *friends[4] = {
        "Annie",
        "Tobi",
        "Karen",
        "Fransika"};
    printf("The size of a pointer variable <friends> is %ld, while the size of a pointer to an array of read-only strings is %ld \n", sizeof(friends), sizeof(char *));
    char *enemies[2] = {
        "Lisa", "Patrick"};
    printf("The size of a pointer variable <enemies> is %ld, while the size of a pointer to an array of read-only strings is %ld \n", sizeof(enemies), sizeof(char *));

    char *bestfriend[1] = {"me"};
    printf("The size of a pointer variable <bestfriend> is %ld, while the size of a pointer to an array of read-only strings is %ld \n", sizeof(bestfriend), sizeof(char *));

    char favedrink[] = "mineral water";
    printf("The size of a variable <favedrink> is %ld, while the size of an array characters is %ld \n", sizeof(favedrink), sizeof(char));

    char *fruits[] = {"apple", "orange", "mango"};
    printf("The size of a pointer variable <fruits> is %ld, while the size of a pointer to an array of read-only strings is %ld \n", sizeof(fruits), sizeof(char *));

    char *favcakes[3][100] = {"red velvet cake", "kasekuchen", "devil's chocolate cake"};
    printf("The size of a pointer variable <favcakes> is %ld, while the size of a pointer to chars is %ld \n", sizeof(favcakes), sizeof(char *));

    int favenumber = 2;
    printf("The size of a  variable <favenumber> is %ld, while the size of an int  is %ld \n", sizeof(favenumber), sizeof(int));

    int *notsofavenumber = 7;
    printf("The size of a  variable <notsofavenumber> is %ld, while the size of an int  is %ld \n", sizeof(notsofavenumber), sizeof(int *));

    int evennumbers[] = {2, 4, 6, 8, 10};
    printf("The size of a  variable <evennumbers> is %ld, while the size of an int  is %ld \n", sizeof(evennumbers), sizeof(int));

    int oddnumbers[] = {3, 6, 9};
    printf("The size of a  variable <oddnumbers> is %ld, while the size of an int  is %ld \n", sizeof(oddnumbers), sizeof(int));

    int numbersbyfive[] = {5, 10};
    int *numbersbyfive_ptr = numbersbyfive;
    printf("The size of a  variable <numbersbyfive> is %ld, while the size of an int  is %ld \n", sizeof(numbersbyfive), sizeof(int));
    printf("The size of a pointer variable <numbersbyfive_ptr> is %ld, while the size of a pointer to an int is %ld \n", sizeof(numbersbyfive_ptr), sizeof(int *));

    int numbersbytens[5] = {10, 20, 30, 40, 50};
    int(*tens_ptr)[5] = &numbersbytens;
    printf("The size of a array pointer variable <tens_ptr> is %ld \n", sizeof(tens_ptr));

    char **b_db_ptr = &b; // char *b = "B";
    printf("The size of double pointer variable <b_db_ptr> is %ld, while the size of a double pointer to an char is %ld\n", sizeof(b_db_ptr), sizeof(char **));

    char **message_db_ptr = &message; // char *message = "My name is Comfort Ajala";
    printf("The size of double pointer variable <message_db_ptr> is %ld, while the size of a double pointer to a read-only string is %ld\n", sizeof(message_db_ptr), sizeof(char **));

    char **friends_db_ptr = friends; // char *friends[4] = {"Annie","Tobi","Karen","Fransika"};
    printf("The size of double pointer variable <friends_db_ptr> is %ld, while the size of a double pointer to a char is %ld\n", sizeof(friends_db_ptr), sizeof(char **));

    int **favenumber_db_ptr = &notsofavenumber; // int *notsofavenumber = 7;
    printf("The size of double pointer variable <favenumber_db_ptr> is %ld, while the size of a double pointer to a int is %ld\n", sizeof(favenumber_db_ptr), sizeof(int **));

    return 0;
}
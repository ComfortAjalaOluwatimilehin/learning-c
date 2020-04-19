#include <stdio.h>
const int ARRAY_SIZE = 5;
int main()
{
    // what is "*" called --> indirection operator
    char people = 'n';
    // people cannot store a string / an array of characters, why
    char *name = "every good boy does fine"; // a pointer variable holding the address of the string literal "people which lives in the readonly or constant zone in memory
    // how does this pointer know the length of the string literal
    char notes[] = "every good boy does fine";
    notes[0] = 'E'; // why can we re-initalize each character of the notes array unlike pointer variable name

    int num = 4; // where in memory is this value stored ?
    int *numptr = &num;
    //array of integers
    int var[5] = {1, 2, 3, 4};
    printf("The third value is %i\n", var[2]);
    int *ptr = var; // is an array a pointer ?
    // what are the differences between an array and a pointer variable?
    printf("The address returned by the array of integers 'var' is %p\n", ptr);
    int *secondptr = &var[0];
    // what is the difference between pointing to the entire array and pointing to the first element of an array?
    printf("Ptr points to the 0th element of var and is = %p\n", ptr);
    int(*wholeptr)[ARRAY_SIZE] = &var;
    printf("The ptr to the entire array of integers is %p\n", wholeptr);
    int *fiveintptr[ARRAY_SIZE]; // an array of  pointers to integers
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        /* code */
        fiveintptr[i] = &var[i];
    }
    *fiveintptr[4] = 25; // what is this action called ?
    for (int k = 0; k < ARRAY_SIZE; k++)
    {
        /* code */
        printf("The value at index %d is = %d \n", k, *fiveintptr[k]);
    }
    // pointer to string literal
    char *myname = "Comfort Ajala"; // where is this stored in memory;
    // what is the pointer's type ?
    //array of strings
    char top5femalartists[5][20] = {
        "beyonce",
        "jessie j",
        "christina aguilera",
        "maria carey",
        "mary j blige"}; // what does the "5" and "20" mean ?
    // what happens when a string like "beyonce" is shorter than 20?
    // why would the following expression not work ? top5femalartists[1] = "jennifer hudson";
    char *top5maleartist[5] = {
        "bruno mars",
        "michael jackson"};
    top5maleartist[0] = "DO of exo";
    // why will the assignment work ?
    printf("My first top male artist is %s \n", top5maleartist[0]);
    // double pointers
    int **doubleptr = &numptr; // holds the address of the pointer variable holding the address of the integer 4
    // what value does it dereference ?
    printf("The dereferenced value from the first pointer of numptr is %d\n", *numptr);
    printf("While the dereferenced value from the pointer to numptr is %d\n", **doubleptr);
    // what happens when you use only one indirection operator on the double pointer ?
    printf("One indirection operator on a double pointer returns  -->  %p\n", *doubleptr);
    //pointer arithmetic

    //malloc
}
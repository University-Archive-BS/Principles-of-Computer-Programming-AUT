#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4] = { 1, 2, 3, 4 };
    int *arr_cpy;
    arr_cpy = arr;

    char s1[10] = "Hello";
    char* s2 = "Hello";
    char* s3 = s1;

    return 0;
}

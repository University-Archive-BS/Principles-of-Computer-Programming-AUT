#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *ptr;
    int **ptr2;
    x = 25;
    ptr = &x;
    ptr2 = &ptr;
    *ptr = 2 * **ptr2;
    printf("x = %d and address of x = 0x%p = 0x%p = 0x%x = 0x%p \n", x, ptr, &x, &x, *ptr2);
    return 0;
}

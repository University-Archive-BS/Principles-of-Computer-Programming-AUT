#include <stdio.h>
#define SIZE 9

int main()
{
    int i, j;
    int table[SIZE][SIZE];
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            table[i][j] = (i+1)*(j+1);
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

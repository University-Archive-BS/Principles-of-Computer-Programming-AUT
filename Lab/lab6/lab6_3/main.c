#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter 5 numbers to sort them for you.\n");
    int number[5];
    int i,j,temp;
    for(i=0;i<5;i++)
    {
        printf("Your number:");
        scanf("%d",&number[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(number[j]>number[j+1])
            {
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d\n",number[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int a[5];
    int i;
    printf("Please enter 5 numbers:\n");
    for(i=0;i<5;i++)
    {
        printf("your number:");
        scanf("%d",&a[i]);
    }
    printf("Now I will print your numbers vice versa:\n");
    for(i=4;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}

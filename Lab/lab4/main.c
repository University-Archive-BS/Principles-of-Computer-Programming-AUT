#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,x,i=0,j=0,t=0;
    scanf("%d",&n);
    int temp = n;
    for(i=0;i<2*n-1;i++)
    {
        printf("* ");
    }
    printf("\n");
    while(n > 1)
    {
        for(i=0;i<n-1;i++)
        {
            printf("* ");
        }
        for(i=0;i<=2*t;i++)
        {
            printf("  ");
        }
        for (i=0;i<n-1;i++)
        {
            printf("* ");
        }
        t++;
        n--;
        if(n>=1)
        {
            printf("\n");
        }
    }
    n=3;
    t = t-1;

     while(n <=temp)
    {
        for(i=0;i<n-1;i++)
        {
            printf("* ");
        }
        for(i=0;i<=2*t-2;i++)
        {
            printf("  ");
        }
        for (i=0;i<n-1;i++)
        {
            printf("* ");
        }
        printf("\n");
        t--;
        n++;
    }
    n--;
    for(i=0;i<2*n-1;i++)
    {
        printf("* ");
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}

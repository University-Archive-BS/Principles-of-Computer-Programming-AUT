#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max_factor(int n)
{
    int i=2;
    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            n = n/i;
        }
        else
        {
            i++;
        }
    }
    return n;
}

int all_factors(int n)
{
    int p=0;
    int k[1000],temp;
    temp = n;

    while ( temp!=1 )
    {
        k[p] = max_factor(temp);
        temp= temp/k[p];
        p++;
    }
    while(p>=0)
    {
        if
            k[0]==k[p]
    }
}

int main()
{
    int n,res,t=1;
    scanf("%d",&n);
    res= all_factors(n);
   // printf("%d",res);
    return 0;
}

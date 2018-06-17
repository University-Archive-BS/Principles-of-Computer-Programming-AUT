#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max_factor(int n)
{
    int t=2;
    while (t <= sqrt(n))
    {
        if (n % t == 0)
        {
            n = n/t;
        }
        else
        {
            t++;
        }
    }
    return n;
}

int all_factors(int n,int i)
{
    int r=0;
    while(n!=0)
    {
        if( n % i == 0 )
        {
            r++;
        }
        else
        {
            break;
        }
        n=n/i;
    }
    return r;
}

int p(int n)
{
    int i=2;
    while(i <= n/2)
    {
        if( n % i ==0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("1 = 1\n");
    int i,k;
    for( k = 2 ; k <= n ; k++ )
    {
        printf("%d = 1" , k);
        for( i = 2 ; i <= n ; i++ )
        {
            if(p(i))
            {
                if(all_factors(k,i))
                {
                    printf(" * %d^%d", i , all_factors(k,i) );
                }
            }
        }
        printf("\n");
    }
    return 0;
}

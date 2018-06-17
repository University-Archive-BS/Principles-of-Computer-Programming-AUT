#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n , sum = 0 , j = 1 , sum2 = 0 , i = 1, k = 0;
    int x[10000];

    while ( k < 10000)
    {
        x[k]=0;
        k++;
    }

	scanf("%d",&n);

	if ( n == 0)
    {
        printf("0\n");
        printf("0");
        return 1;
    }

    for( n ; n>0 ; n-- )
    {
        for( j ; j < n ; j++)
        {
            if( n % j == 0 )
            {
                sum += j;
            }
        }
        if( sum == n)
        {
            x[n]=n;
            sum2++;
        }
        j = 1;
        sum = 0;
    }
    printf("%d\n",sum2);
    while ( i < 10000 )
    {
        if( x[i] != 0)
        {
            printf("%d\n",x[i]);
        }
        i++;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);

    int o = 2;
    if ( x == y )
    {
        while ( o <= x)
        {
            printf("%d\n", o);
            o++;
        }
    }

    int n;
    n = fabs( x - y );

    int t = 2;
    while ( t <= n)
    {
        if ( n % t == 0)
        {
            printf("%d\n",t);
        }
        t++;
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    double x1,y1,w1,h1;
    double x2,y2,w2,h2;

    scanf("%lf",&x1);
    scanf("%lf",&y1);
    scanf("%lf",&w1);
    scanf("%lf",&h1);
    scanf("%lf",&x2);
    scanf("%lf",&y2);
    scanf("%lf",&w2);
    scanf("%lf",&h2);

    double a1,a2,a3,a4;
    a1 = fmax( x1 , x2);
    a2 = fmin( x1 + w1 , x2 + w2 );
    a3 = fmax( y1 , y2 );
    a4 = fmin ( y1 + h1 , y2 + h2 );

    double s;
    s =  ( a4 - a3 ) * ( a2 - a1 );

    printf("%.2lf",s);

    return 0;
}

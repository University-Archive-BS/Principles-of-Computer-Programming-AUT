#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1,y1,w1,h1;
    float x2,y2,w2,h2;

    scanf("%f",&x1);
    scanf("%f",&y1);
    scanf("%f",&w1);
    scanf("%f",&h1);
    scanf("%f",&x2);
    scanf("%f",&y2);
    scanf("%f",&w2);
    scanf("%f",&h2);

    float s;

    if ( (x2 >= x1) && ( (x2 + w2) <= (x1 + w1) ) )
    {
        if ( (y2 >= y1) && ((y2 + h2) <= (y1 + h1) ))   // full in the other
        {
            s = h2 * w2;
            printf("%.2f",s);
        }
        else if ( (y2 <= (y1 + h1)) && ( (y2 + h2) >= (y1 + h1) ))   // upside break
        {
            s = ((y1 + h1) - y2) * w2;
            printf("%.2f",s);
        }
        else if ( (y2 <= y1) && ( (y2 + h2) >= y1 ))  // downside break
        {
            s = ((y2 + h2) - y1) * w2;
            printf("%.2f",s);
        }
        else if ( (y2 >= (y1 + h1)) || ( (y2 + h2) <= y1 ) )    // no area
        {
            s = 0.000000;
            printf("%.2f",s);
        }
        else if ( (y2 <= y1) && ( (y2 + h2) >= ( y1 + h1 )) )   // the 2nd is bigger
        {
            s = h1 * w2;
            printf("%.2f",s);
        }
    }
    else if ( ((x2 + w2) >= ( x1 + w1)) && (h2 <= h1) )
    {
        if ( x2 >= ( x1 + w1 ))
        {
            s = 0.000000;
            printf("%.2f",s);
        }
        else if ( x2 <= ( x1 + w1 ) )
        {
            s = ( ( x1 + w1 ) - x2 ) * h2;
            printf("%.2f",s);
        }
    }
    else if ( ((x2 + w2) >= ( x1 + w1)) && (h2 >= h1) )
    {
        if ( x2 >= ( x1 + w1 ))
        {
            s = 0.000000;
            printf("%.2f",s);
        }
        else if ( x2 <= ( x1 + w1 ) )
        {
            s = ( ( x1 + w1 ) - x2 ) * h2;
            printf("%.2f",s);
        }
    }
    else if ( x2 <= x1 )
    {
        if ( x1 <= ( x2 + w2 ))
        {
            s = (( x2 + w2 ) - x1) * h2;
            printf("%.2f",s);
        }
        else if ( x1 >= ( x2 + w2 ) )
        {
            s = 0.000000;
            printf("%.2f",s);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1,x2,x3,x4;
    int y1,y2,y3,y4;

    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&x2);
    scanf("%d",&y2);
    scanf("%d",&x3);
    scanf("%d",&y3);
    scanf("%d",&x4);
    scanf("%d",&y4);


    if ( (x1 + x3 == x2 + x4) && (y1 + y3 == y2 + y4) )
    {
        printf("Parallelogram: true\n");
        if ( pow((x3 - x1),2) + pow((y3 - y1),2) == pow((x4 - x2),2) + pow((y4 - y2),2)  && pow((x2 - x1),2) + pow((y2 - y1),2) == pow((x3 - x2),2) + pow((y3 - y2),2) )
        {
            printf("Diamond: true\n");
            printf("Square: true\n");
            printf("Rectangle: true");
        }
        else if ( pow((x3 - x1),2) + pow((y3 - y1),2) == pow((x4 - x2),2) + pow((y4 - y2),2) )
        {
            printf("Rectangle: true\n");
            printf("Square: false\n");
            printf("Diamond: false");
        }
        else if ( pow((x2 - x1),2) + pow((y2 - y1),2) == pow((x3 - x2),2) + pow((y3 - y2),2) )
        {
            printf("Square: false\n");
            printf("Rectangle: false\n");
            printf("Diamond: true");
        }
    }
    else
    {
        printf("Square: false\n");
        printf("Rectangle: false\n");
        printf("Parallelogram: false\n");
        printf("Diamond: false");
    }
    return 0;
}

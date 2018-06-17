#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1,x2,x3,x4;
    int y1,y2,y3,y4;
    int l1,l2,l3,l4;
    int d1,d2;

    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&x2);
    scanf("%d",&y2);
    scanf("%d",&x3);
    scanf("%d",&y3);
    scanf("%d",&x4);
    scanf("%d",&y4);

    l1= pow((x2-x1),2) + pow((y2-y1),2);
    l2= pow((x3-x2),2) + pow((y3-y2),2);
    l3= pow((x4-x3),2) + pow((y4-y3),2);
    l4= pow((x1-x4),2) + pow((y1-y4),2);

    d1= pow((x3-x1),2) + pow((y3-y1),2);
    d2= pow((x4-x2),2) + pow((y4-y2),2);


    if ( l1==l2 && l1==l3 && l1==l4 && d1==d2 )
    {
        printf("Square: true\n");
    }
    else
    {
        printf("Square: false\n");
    }
    if ( l1==l3 && l4==l2 && d1==d2)
    {
        printf("Rectangle: true\n");
    }
    else
    {
        printf("Rectangle: false\n");
    }
    if (l1==l3 && l4==l2 )
    {
        printf("Parallelogram: true\n");
    }
    else
    {
        printf("Parallelogram: false\n");
    }
    if (l1==l2 && l1==l3 && l1==l4)
    {
        printf("Diamond: true\n");
    }
    else
    {
        printf("Diamond: false\n");
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    // sorry the quera forced me to remove this line ... printf("enter the side of the square:");
    scanf("%d",&x);

    double  Ghotr ,Mohati , Mohiti;
    int mohit , masahat;

    mohit = 4 * x;
    masahat = x * x;
    Ghotr = pow(2 , 0.5) * x;
    Mohati = ( 3.14 ) * (pow(((double)x/2) , 2));
    Mohiti = 2 * ( 3.14 ) * ((pow(2,0.5) * x) / 2);

    printf("Perimeter: %d\n", mohit);
    printf("Area: %d\n", masahat);
    printf("Diameter: %.2lf\n", Ghotr);
    printf("Inside Circle: %.2lf\n", Mohati);
    printf("Outside Circle: %.2lf", Mohiti);


    return 0;
}

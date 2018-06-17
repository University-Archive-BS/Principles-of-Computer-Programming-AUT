#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    double sum1=0.0,sum2=0.0,sum3=0.0;


    printf("enter an integer:");
    scanf("%d",&n);

    printf("Left to Right:");
    int i;
    for(i=0;i<n+1;i++)
    {
        sum1 += ((double)1/((double)pow(2,i)));
    }
    printf("%lf\n\n",sum1);


    printf("Right to Left:");
    double temp;
    sum2 = ((double)1/((double)pow(2,n)));
    temp = sum2;
    for(i=0;i<n;i++)
    {
        sum2 = ((double)sum2)*((double)2);
        temp += sum2;
    }
    printf("%lf\n\n",sum2);


    printf("Formulize:");
    sum3 = (double)2*((double)1-pow(0.5,n));
    printf("%lf\n\n",sum3);

    getchar();
    getchar();
    return 0;
}

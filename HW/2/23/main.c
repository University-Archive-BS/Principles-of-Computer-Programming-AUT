#include <stdio.h>
#include <math.h>

int main()
{
float a,b,c,d,e,f,h;
double g,i;

printf("enter a:");
scanf("%f",&a);
printf("enter b:");
scanf("%f",&b);
printf("enter c:");
scanf("%f",&c);
printf("enter d:");
scanf("%f",&d);
printf("enter e:");
scanf("%f",&e);

f = (a/b) + (a*b)/(b*c) + (a*b*c)/(c*d*e);
g = log(fabs((log (fabs(a)))/(log (10)) + sin(b+c)));
h = (a/b)/((a/b) + (b/c) + (c/d)) + ((a/b) + (b/c) + (c/d))/b;
i = pow(((1/pow(fabs(a),1.2))+ (1/pow(fabs(b),2.3))+(1/pow(fabs(c),3.4))),4.5);

printf("Formula 1 result = %f\n",f);
printf("Formula 2 result = %lf\n",g);
printf("Formula 3 result = %f\n",h);
printf("Formula 4 result = %lf",i);

    return 0;
}

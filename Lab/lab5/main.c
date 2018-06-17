#include <stdio.h>
#include <stdlib.h>

double a(double n,double m)
{
    return n+m;
}
double s(double n ,double m)
{
    return n-m;
}
double m(double n,double m)
{
    return n*m;
}
double d(double n,double m)
{
    return n/m;
}
double p(double n,int m)
{
    int i;
    double t=n;
    for(i=1;i<m;i++)
    {
        n = t*n;
    }
    return n;
}
int M(int n,int m)
{
    while(n>0)
    {
        n = n-m;
    }
    return n+m;
}
double S(double n)
{
    int j,sss=0;
    for(j=0;j<10;j++)
    {
        sss = p(-1,j) * (p(n,2*j+1)/f(2*j+1));
    }
    return sss;
}
double C(double n)
{
    int k,ccc=0;
    for(k=0;k<10;k++)
    {
        ccc = p(-1,k) * (p(n,2*k)/f(2*k));
    }
    return ccc;
}
double t(double n)
{
    return S(n)/C(n);
}
int f(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return n*f(n-1);
    }
}
double r(double n)
{
    return 1/n;
}
int c(int n,int m)
{
    return f(n)/(f(m)*f(n-m));
}
double L(double n)
{
    int z,lll=0;
    for(z=1;z<20;z++)
    {
        lll = p(-1,z-1) * (p(n-1,z)/z);
    }
    return lll;
}
/*int b(int n,int m,int q)
{
    int nr,i,full=0;
    nr =
    int arr
    for()
}
double q(int n,int m)
{

}*/
int main()
{
    printf("Hello friends...Hello friends!\n");
    printf("I'm a supercalculator.\n");
    printf("Please enter:\n");
    printf("m for multiply\nd for devide\na for add\ns for subtract\n");
    printf("M for modulus\nS for sin\nC for cos\nt for tan\np for point\nf for factorial\nr for reverse\nb for base\nL for ln\nc for combine\nq for square root\n");
    printf("and then enter your input(s).\n\n");
    while(1)
    {
        printf("Please enter operator:");
        char car;
        scanf("%c",&car);
        if(car=='*')
        {
            return 0;
        }
        if(car=='m') //zarb
        {
            double a1,a2;
            printf("enter your first number:");
            scanf("%lf",&a1);
            printf("enter your second number:");
            scanf("%lf",&a2);
            getchar();
            printf("%lf\n",m(a1,a2));
            printf("\n");
            continue;
        }
        if(car=='d')  //taqsim
        {
            double a3,a4;
            printf("enter your first number:");
            scanf("%lf",&a3);
            printf("enter your second number:");
            scanf("%lf",&a4);
            if(a4==0)
            {
                printf("out of range input.\n");
                printf("\n");
                continue;
            }
            getchar();
            printf("%lf\n",d(a3,a4));
            printf("\n");
            continue;
        }
        if(car=='a')   //jam
        {
            double a5,a6;
            printf("enter your first number:");
            scanf("%lf",&a5);
            printf("enter your second number:");
            scanf("%lf",&a6);
            getchar();
            printf("%lf",a(a5,a6));
            printf("\n");
            continue;
        }
        if(car=='s')   //menha
        {
            double a7,a8;
            printf("enter your first number:");
            scanf("%lf",&a7);
            printf("enter your second number:");
            scanf("%lf",&a8);
            getchar();
            printf("%lf",s(a7,a8));
            printf("\n");
            continue;
        }
        if(car=='M')  //mod
        {
            int b1,b2;
            printf("enter your first number:");
            scanf("%d",&b1);
            printf("enter your second number:");
            scanf("%d",&b2);
            getchar();
            printf("%d",M(b1,b2));
            printf("\n");
            continue;
        }
        if(car=='p')  //tavan
        {
            double b3;
            int b4;
            printf("enter your base:");
            scanf("%lf",&b3);
            printf("enter your qoveh:");
            scanf("%d",&b4);
            getchar();
            printf("%lf",p(b3,b4));
            printf("\n");
            continue;
        }
        if(car=='c') //tarkib
        {
            int b5,b6;
            printf("enter your first number:");
            scanf("%d",&b5);
            printf("how many objects you want to select:");
            scanf("%d",&b6);
            getchar();
            printf("%d",c(b5,b6));
            printf("\n");
            continue;
        }
        if(car=='q')  //jazr
        {
            double b7,b8;
            printf("enter your base:");
            scanf("%lf",&b7);
            printf("enter your forje:");
            scanf("%lf",&b8);
            getchar();
            //printf("%lf",q(b7,b8));
            printf("\n");
            continue;
        }
        if(car=='S')  //sin
        {
            double c1;
            printf("enter argoman:");
            scanf("%lf",&c1);
            getchar();
            printf("%lf",S(c1));
            printf("\n");
            continue;
        }
        if(car=='C')   //cos
        {
            double c2;
            printf("enter argoman:");
            scanf("%lf",&c2);
            getchar();
            printf("%lf",C(c2));
            printf("\n");
            continue;
        }
        if(car=='t')   //tan
        {
            double c3;
            printf("enter argoman:");
            scanf("%lf",&c3);
            getchar();
            printf("%lf",t(c3));
            printf("\n");
            continue;
        }
        if(car=='f')  //factor
        {
            int d1;
            printf("enter your number:");
            scanf("%d",&d1);
            getchar();
            printf("%d",f(d1));
            printf("\n");
            continue;
        }
        if(car=='r')  //aks
        {
            double d2;
            printf("enter your number:");
            scanf("%lf",&d2);
            getchar();
            printf("%lf",r(d2));
            printf("\n");
            continue;
        }
        if(car=='L')   //ln
        {
            double d3;
            printf("enter argoman:");
            scanf("%lf",&d3);
            getchar();
            printf("%lf",L(d3));
            printf("\n");
            continue;
        }
        if(car=='b')   //mabna
        {
            double e1,e2,e3;
            printf("enter the first number:");
            scanf("%lf",&e1);
            printf("enter the first base:");
            scanf("%lf",&e2);
            printf("enter the second base:");
            scanf("%lf",&e3);
            getchar();
            //printf("%d",b(e1,e2,e3));
            printf("\n");
            continue;
        }
        else
        {
            printf("unavailable operator.\n");
            printf("\n");
            continue;
        }

    }
    return 0;
}

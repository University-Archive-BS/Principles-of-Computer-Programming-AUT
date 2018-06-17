#include <stdio.h>

char names[100][100];
int mass[100];
float height[100];
float BMI[100];

float B_M_I(int mass[], float height[],int i,float BMI[])
{
    BMI[i] = mass[i]/((height[i])*(height[i]));
}

int pp;
void swap_t(int a[],int pp)
{
    int ttt;
    ttt = a[pp];
    a[pp] = a[pp+1];
    a[pp+1] = ttt;
}

int ppp;
void swap_tt(int a[ppp])
{
    int tttt;
    tttt = a[ppp];
    a[ppp] = a[ppp+1];
    a[ppp+1] = tttt;
}
int fini;
void bubbleSort(char names[][100], float BMI[])
{
    int y,t,tt;
    for(y=0;y<fini;y++)
    {
        for(t=0;t<fini;t++)
        {
            if(BMI[t]>BMI[t+1])
            {
                swap_t(BMI,t);
                swap_tt(names[t][100]);
            }
        }
    }
}

void main()
{
    int i;
    for(i=0;i<100;i++)
    {
        printf("Enter name:");
        scanf("%c",&names[i][100]);
        getchar();
        getchar();
        printf("enter mass in kg:");
        scanf("%d",&mass[i]);
        printf("enter height in meters:");
        scanf("%lf",&height[i]);
        if(names[i][100]=="FiNiSh")
        {
            fini = i;
            break;
        }
        B_M_I(mass,height,i,BMI);
    }
    for(i=0;i<fini;i++)
    {
        printf("%s\n",names[i][100]);
        printf("%d",BMI[i]);
    }
}


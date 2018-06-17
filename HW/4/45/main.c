#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    int i,j,k,counterr=0;

    clock_t start,end;
    time_t t=time(NULL);
    srand(t);
    double periodd=(end - start)/CLOCKS_PER_SEC;
    double ave_time =counterr/periodd;

    printf("Please enter num & length:");
    int tedad;
    scanf("%d",&tedad);
    int tool;
    scanf("%d",&tool);

    char * text[256];
    char * c[256];

    while(tedad!=0)
    {
        for (i=0;i<tedad;i++)
        {
            for (j=0;j<tool;j++)
            {
                c[j]=(rand()%26)+97;
                printf("%c",c[j]);

            }
            printf(" ");
        }
        start=clock();

        for (k=0;k<tedad;k++)
        {
            gets(c);
            if (strcmp(text[k],c[k])==0)
            {
                counterr++;
            }
        }
        end=clock();

        printf("Your score is %d out of %d:",counterr,tedad);
        printf("\nyour word per min is %lf",ave_time);

        printf("Please enter num & length:");
        scanf("%d",&tedad);
        scanf("%d",&tool);
    }
    return 0;
}

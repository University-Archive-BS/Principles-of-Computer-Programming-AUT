#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter 10 numbers and I will print the max and the average of them.\n");
    int a[10];
    int i,temp;
    float sum = 0 , ave;
    for(i=0;i<10;i++)
    {
        printf("Your number:");
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        sum += a[i];
    }
    ave = sum/10;
    for(i=0;i<10;i++)
    {
        if(a[i]>a[i+1])
        {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    printf("Average= %f\n",ave);
    printf("Max = %d",a[9]);
    return 0;
}

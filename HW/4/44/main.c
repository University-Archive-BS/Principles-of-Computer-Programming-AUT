#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int fir , mab , ne, i = 0,k=1,sum0=0,sum1=0,j=0,d=0;
    int x[30000];

    scanf("%d",&fir);
    scanf("%d",&mab);

    while ( d < 30000)
    {
        x[d]=0;
        d++;
    }

    while ( floor( fir/mab) != 0  && i<30000)
    {
        x[i] = fir % mab;
        fir = (fir - x[i])/mab;
        i++;
    }
    x[i]=fir;

    while( j < 30000 )
    {
        sum0 += x[j];
        j = j +2;
    }

    while( k < 30000 )
    {
        sum1 += x[k];
        k = k +2;
    }

    if ( sum1 == sum0)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}

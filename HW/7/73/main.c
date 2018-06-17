#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int b;
    float k;
}kasr;

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    int n;
    scanf("%d",&n);
    kasr kk[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&(kk[i].a));
        scanf("%d",&(kk[i].b));
        if((kk[i].b)==0) return 1;
        kk[i].k = (float)kk[i].a/(float)kk[i].b;
    }
    float y[n];
    for (i=0; i<n; i++)
    {
        y[i]= kk[i].k;
    }

    qsort(y,n,sizeof(int),cmp);
    int jah,j;
    scanf("%d",&jah);
    if(jah== 1)
    {
        for(i = 0 ; i<n ; i++)
        {
            for(j = 0 ; j<n ; j++)
            {
                if(y[i]==kk[j].k)
                {
                    printf("%d/%d\n",kk[j].a,kk[j].b);
                }
            }
        }
    }
    else if(jah== -1)
    {
        for(i =n-1 ; i>-1 ; i--)
        {
            for(j = 0 ; j<n ; j++)
            {
                if(y[i]==kk[j].k)
                {
                    printf("%d/%d\n",kk[j].a,kk[j].b);
                }
            }
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

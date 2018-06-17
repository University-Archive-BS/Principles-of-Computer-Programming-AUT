#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dig_index(int n ,int m ,int dir)
{
    int nr;  //tedad arqam
    nr = floor(log10(n));

    int x[nr],i=0;

    while(i<nr)
    {
        x[i]=n%10;
        n=n/10;
        i++;
    }
    i=0;
    if(dir == 1)
    {
        while ( i<nr )
        {
            if(x[i]==m)
            {
                return (i+1);
            }
            i++;
        }
    }
    i=nr-1;
    if (dir == -1)
    {
        while( i>=0 )
        {
            if(x[i]==m)
            {
                return (i+1);
            }
            i--;
        }
    }
    return 0;
}

int sym(int n)
{
    int j=1,temp=n;
    while(j<=floor(log10(temp))/2)
    {
        if(dig_index(n,n%10,-1)!=j)
        {
            return 0;
        }
        n=n/10;
        j++;
    }
    return 1;
}

int main()
{
    int n,m,dir,res;
    scanf("%d",&n);
    int d=sym(n);
    if(d==0)
        printf("False");
    else
        printf("True");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dig_index(int n, int m , int dir)
{
    int nr;  //tedad arqam
    nr = log10(n)+1;

    int x[nr],i=0;

    while(i<nr)
    {
        x[i]=n%10;
        n=n/10;
        i++;
    }

    if(dir == +1)
    {
        i = 0;
        while ( i<nr )
        {
            if(x[i]==m)
            {
                return (i+1);
            }
            i++;
        }
    }
    if (dir == -1)
    {
        i = nr - 1;
        while( i>=0 )
        {
            if(x[i]==m)
            {
                return (nr-i);
            }
            i--;
        }
    }
    return 0;
}

int sym(int n)
{
    int j=1;
    if( log10(n)+1 == 2)
    {
        if( n%10 != n/10)
        {
            return 0;
        }
    }
    while(j<(log10(n)+1)/2)
    {
        if(dig_index(n,n%10,-1)!= j)
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
    int n,res;

    scanf("%d",&n);
    res = sym(n);
    if ( res == 0 )
    {
        printf("False");
    }
    else
    {
        printf("True");
    }
    return 0;
}

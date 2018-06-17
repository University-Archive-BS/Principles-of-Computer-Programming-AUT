#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    int j=2;
    while(j <= n/2)
    {
        if( n % j ==0)
        {
            return 1;
        }
        j++;
    }
    return 0;
}

int next_prime_number(int n)
{
    int k=2;
    while(k <= n/2)
    {
        if( n % k ==0)
        {
            return 1;
        }
        k++;
    }
    return 0;
}

int check_Goldbach(int n)
{
    int i;
    if( n % 2 != 0)
    {
        return 1;
    }
    if( n<=2 )
    {
        return 1;
    }
    for ( i = 2 ; i <= n/2 ; i++)
    {

        if ( is_prime(i)==0 && next_prime_number(n-i)==0)
        {
            printf("Even number: %d\n",n);
            printf("Prime 1: %d\n",i);
            printf("Prime 2: %d\n",n-i);
            return 0;
        }
    }
}

int main()
{
    int n;
    printf("please enter an even integer:");
    scanf("%d",&n);
    for( n ; n > 2 ; n = n-2)
    {
        check_Goldbach(n);
    }
    return 0;
}

#include <stdio.h>

int main()
{
	int n , a1 , a2 , b1 , b2;
	scanf("%d", &n);
	a1 = n % 10;
	a2 = n / 10000;
	b1 = (n/10) % 10;
	b2 = (n/1000) % 10;

    if ( n > 99999 || n < 10000 )
    {
    printf("Error");
    return 1;
    }

    if ( a1 == a2 )
	{
		if ( b1 == b2 )
		{
			printf("True");
		}
		else
		{
			printf("False");
		}
	}
	else
	{
		printf("False");
	}
return 0;

}

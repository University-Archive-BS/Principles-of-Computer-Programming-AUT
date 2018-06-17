#include <stdio.h>
#include <stdlib.h>

void Cyclic_Swap(int *a,int *b,int *c)
{
    int temp1;
    temp1 = *a;
    *a = *c;
    *c = *b;
    *b = temp1;
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    Cyclic_Swap(&a,&b,&c);
    printf("\n\n%d\n%d\n%d",a,b,c);
    return 0;
}

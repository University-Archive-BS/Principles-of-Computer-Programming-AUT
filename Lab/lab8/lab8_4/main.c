#include <stdio.h>
#include <stdlib.h>

int cmp(char *str1,char *str2)
{
    int i;
    for(i=0;i<70;i++)
    {
        if(*(str1+i)=='\0'   ||   *(str2+i)=='\0')
        {
            break;
        }
        if(*(str1+i)!=*(str2+i))
        {
            printf("False");
            return 0;
        }
    }
    printf("True");
    return 1;
}
int main()
{
    char str1[70];
    printf("enter string 1:\n");
    scanf("%s",str1);

    char str2[70];
    printf("enter string 2:\n");
    scanf("%s",str2);

    cmp(str1,str2);

    return 0;
}

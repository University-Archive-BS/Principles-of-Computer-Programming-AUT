#include <stdio.h>
#include <stdlib.h>

int main()
{
    char msg[5]="Hello";
    int i;
    printf("%s\n",msg);
    for(i=0;i<5;i++)
    {
        printf("%c",msg[i]);
    }



    printf("\n");
    char mg[5] = "hell";
    mg[4] = 'o';
    printf("%s", mg);

    char gsm[5];
    gsm[5] = "BYE" ;
    printf("\n");
    for(i=0;i<5;i++)
    {
        if ( gsm[i]== '\0' )
        {
            printf("%d",i+1);
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE * fo;
void digit(char a)
{
         if(a==48) fprintf(fo,"zero");
    else if(a==49) fprintf(fo,"one");
    else if(a==50) fprintf(fo,"two");
    else if(a==51) fprintf(fo,"three");
    else if(a==52) fprintf(fo,"four");
    else if(a==53) fprintf(fo,"five");
    else if(a==54) fprintf(fo,"six");
    else if(a==55) fprintf(fo,"seven");
    else if(a==56) fprintf(fo,"eight");
    else if(a==57) fprintf(fo,"nine");
}
int main()
{
    FILE *fp;
    char fin1[20],fin2[20];
    printf("enter the name of input file:");
    scanf("%s",fin1);
    fp = fopen(fin1,"r");
    if(fp==NULL) return -1;
    printf("enter the name of output file:");
    scanf("%s",fin2);
    fo = fopen(fin2,"w");
    if(fo==NULL) return -1;
    char c;
    while( (c = fgetc(fp)) != EOF )
    {
        if(isdigit(c))
        {
            digit(c);
        }
        else if ( (c>=97) && (c<=122) )
        {
            c = c-32;
            fputc(c,fo);
        }
        else
        {
            fputc(c,fo);
        }
    }
    fclose(fp);
    fclose(fo);
    return 0;
}

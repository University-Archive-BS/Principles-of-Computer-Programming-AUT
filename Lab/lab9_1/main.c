#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* myfile = fopen("input.txt","r");
    char str_i[51];
    int i;
    fread(str_i,1,51,myfile);
    fclose(myfile);
    FILE* hisfile = fopen("out.txt","w");
    char str_o[51];
    for(i=0;i<51;i++)
    {
        str_o[i]=str_i[50-i];
    }
    fwrite(str_o,1,51,hisfile);
    return 0;
}

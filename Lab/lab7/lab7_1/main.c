#include <stdio.h>

void replace (char[], char, char);
int isMirrored (char[]);

int main()
{
    int i;
    char str[100], source_letter, target_letter;
    for(i;i<10;i++)
    {
        printf ("Enter the String: ");
        gets(str);
        if(isMirrored(str)==1)
        {
            printf("isMirrored");
            continue;
        }
        else
        {
            printf("notMirrored\n");
            printf("enter source_letter:");
            scanf("%c",&source_letter);
            getchar();
            printf("enter target_letter:");
            scanf("%c",&target_letter);
            replace(str,source_letter,target_letter);
            printf("%s",str);
        }
        _getch();
    }
    getchar();
    return 1;
}
void replace(char string[], char source_letter, char target_letter)
{
    int i;
    for(i=0;i<100;i++)
    {
        if(string[i]==source_letter)
        {
            string[i]= target_letter;
        }
    }
}
int isMirrored(char string[])
{
    int j,s,k;
    for(j=0;j<100;j++)
    {
        if(string[j]=='\0')
        {
            s = j;
            break;
        }
    }
    for(k=0;k<s;k++)
    {
        if(string[k]!=string[s-1-k])
        {
            return 0;
        }
    }
    return 1;
}

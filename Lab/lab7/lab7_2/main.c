#include <stdio.h>

int compare(char first[], char second[]);
int checkFinish(char input[]);
void bubbleSort(char str[][100]);

void main()
{
    char str[100][100];
    int n;
    printf("Please enter number of strings(Max. 100): ");
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++)
    {
        getchar();
        getchar();
        gets(str[i][100]);
        if(str[i][100]=="FiNiSh")
        {
            break;
        }
    }
    //Write your code here!
}
int compare(char first[], char second[])
{
    if(first[]<second)
    {
        return -1;
    }
    if(first[]==second[])
    {
        return 0;
    }
    if(first[]>second[])
    {
        return 1;
    }
}

void bubbleSort(char str[][100])
{
    int h,g;
    for(h=0;h<i;h++)
    {
        for(g=0;g<100;g++)
        {
            if
        }

    }
}


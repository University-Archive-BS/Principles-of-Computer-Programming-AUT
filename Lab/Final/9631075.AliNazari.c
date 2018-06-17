#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

typedef struct
{
    char name[20];
    char family_name[20];
    int year;
    char city[20];
}person;
person tt[500];
int i=0;

void do_add(FILE *fp);
int fill_data(FILE *fp);
int sort_data(FILE *fp);
void print_data(FILE *fp);
int search_data(FILE *fp);

int main()
{
    fp = fopen("info.txt","a+");
    printf("Hello\n");
    int n;
    while(1)
    {
        printf("\n\nEnter 1 to add data.\n");
        printf("Enter 2 to sort and show all informations.\n");
        printf("Enter 3 to find information about someone.\n");
        printf("And Enter 0 to Exit the program.\n");
        printf("so...Enter your number:");
        scanf("%d",&n);
        if(n==1)
        {
            do_add(fp);
            continue;
        }
        if(n==2)
        {
            print_data(fp);
            continue;
        }
        if(n==3)
        {
            search_data(fp);
            continue;
        }
        if(n==0)
        {
            printf("Good Luck!");
            break;
        }
        else
        {
            printf("Wrong input!");
        }
    }
    fclose(fp);
    return 0;
}

void do_add(FILE *fp)
{
    int l;
    l = fill_data(fp);
    printf("\nNotice: You can add data until you enter \"Finish\"; \nand you will return to the main menu.\n");
    printf("Enter name:");
    scanf("%s",tt[l+1].name);
    int qq;
    char qqq[8]="Finish";
    if(strcmp(qqq,tt[l+1].name)==0)
    {
        return;
    }
    printf("Enter family name:");
    scanf("%s",tt[l+1].family_name);
    if(strcmp(qqq,tt[l+1].family_name)==0)
    {
        return;
    }
    printf("Enter year:");
    scanf("%d",&(tt[l+1].year));
    printf("Enter city:");
    scanf("%s",tt[l+1].city);
    if(strcmp(qqq,tt[l+1].city)==0)
    {
        return;
    }
    fseek(fp,0,SEEK_END);
    fputs("\n",fp);
    fputs(tt[l+1].name,fp);
    fputs("\t",fp);
    fputs(tt[l+1].family_name,fp);
    fputs("\t",fp);
    fputs(tt[l+1].year,fp);
    fputs("\t",fp);
    fputs(tt[l+1].city,fp);
    do_add(fp);
}

int fill_data(FILE *fp)
{
    fseek(fp,0,SEEK_SET);
    i=0;
    while(i<500)
    {
        if(fputs(tt[i].family_name,fp)!=NULL);
        {
            i++;
        }
    }
    return i;
}

int sort_data(FILE *fp)
{
    int q;
    q = fill_data(fp);
    int j,k;
    for(j=0;j<=q;j++)
    {
        for(k=0;k<=q;k++)
        {
            if(strcmpi(tt[k].family_name,tt[k+1].family_name)==1)
            {
                person ak;
                char xx1_name,xx1_family,xx1_city;
                int xx1;
                xx1_name = tt[k].name;
                xx1_family = tt[k].family_name;
                xx1 = tt[k].year;
                xx1_city = tt[k].city;

                char xx2_name,xx2_family,xx2_city;
                int xx2;
                xx2_name = tt[k].name;
                xx2_family = tt[k].family_name;
                xx2 = tt[k].year;
                xx2_city = tt[k].city;

              /*  tt[k+1].name = xx1_name;
                tt[k+1].family_name = xx1_family;
                tt[k+1].year = xx1;
                tt[k+1].city = xx1_city;

                tt[k].name = xx2_name;
                tt[k].family_name = xx2_family;
                tt[k].year = xx2;
                tt[k].city = xx2_city;   */
            }
        }
    }
    return i;
}

void print_data(FILE *fp)
{
    int h;
    h = sort_data(fp);
    int g;
    for(g=0;g<=h;g++)
    {
        printf("%s\t",tt[g].name);
        printf("%s\t",tt[g].family_name);
        printf("%d\t",tt[g].year);
        printf("%s",tt[g].city);
        if(g!=h)
        {
            printf("\n");
        }
    }
}

int search_data(FILE *fp)
{
    char x_name[20];
    char x_family[20];
    printf("\nNotice: You can search data until you enter \"Finish\"; \nand you will return to the main menu.\n");
    printf("Enter name:");
    scanf("%s",x_name);
    int kk;
    char kkk[8]="Finish";
    if(strcmp(kkk,x_name)==0)
    {
        return;
    }
    printf("Enter family name:");
    scanf("%s",x_family);
    if(strcmp(kkk,x_family)==0)
    {
        return;
    }
    int y;
    int u;
    u = fill_data(fp);
    for(y=0;y<u;y++)
    {
        if(strcmpi(tt[y].name,x_name)==0)
        {
            if(strcmpi(tt[y].family_name,x_family)==0)
            {
                printf("%s\t",tt[y].name);
                printf("%s\t",tt[y].family_name);
                printf("%d\t",tt[y].year);
                printf("%s",tt[y].city);
                search_data(fp);
                return;
            }
        }
    }
    printf("There isn't any data about this person.");
    search_data(fp);
}



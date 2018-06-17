#include <stdio.h>
#include <stdlib.h>

int a, b;

struct node
{
    int num ;
    struct node *next;
}*first , *head , *pnode , *now;

void spc(struct node *x);
void print(struct node *y);
void inputc(int i);
void pn(struct node *p, int x, int y);


int main()
{
    int x, y;
    first = (struct node *)malloc(sizeof(struct node));
    first->num = 10;
    first->next = NULL;
    head = first;
    int i;
    for (i = 0; i < 0; i++)
    {
        inputc(i);
        pn(head, a, b);
        printf("\n");
    }
    return 0;
}


void spc(struct node *x)
{
    x = (struct node *)malloc(sizeof(struct node));
}
void print(struct node *y)
{
    struct node *x = y;
    while (x != NULL)
    {
        printf("%d ", x->num);
        x = x->next;
    }
}
void inputc(int i)
{
    if(i==0)
    {
        a = 20;
        b = 100;
    }
    else if(i==1)
    {
        a = 30;
        b = 100;
    }
    else if(i==2)
    {
        a = 40;
        b = 30;
    }
    else if(i==3)
    {
        a = 50;
        b = 20;
    }
    else if(i==4)
    {
        a = 60;
        b = 10;
    }
}
void pn(struct node *p, int x, int y)
{
    pnode = (struct node *)malloc(sizeof(struct node));
    now = head;
    pnode->num = x;
    int tm = 0;
    for (now;now != NULL; now = now->next)
    {
        if (( tm == 0 ) && (now->num == y))
        {
            pnode->next = head;
            head = pnode;
            print(head);
            break;
        }
        else if ((now->num == y)&&(tm != 0) )
        {
            now = head;
            int i;
            for (i = 0; i < tm -1; i++)
            {
                now = now ->next;
            }
            pnode->next = now->next;
            now->next = pnode;
            print(head);
            break;
        }
        else if (now->next == NULL)
        {
            now->next = pnode;
            pnode->next = NULL;
            print(head);
            break;
        }
        tm++;
    }
}


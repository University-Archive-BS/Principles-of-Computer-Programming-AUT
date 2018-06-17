#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>

int r_p[150][2];  // location of polices
char m_m[30][30];  // matrix characters
int r_r[1][2];  // location of thief
int count_r; //counter of r_r change locations
int count_p; //counter of polices change locations
int n;  // function new_location_police3
int thief[1][2];

void locate_first(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2]); // to locate the polices & thief  // ok
void print_m(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2]);  //draw the matrix  // ok
void print_m_final(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2]);  //draw the matrix  final  // ok
int check_police_see(int r_p[][2],int r_r[1][2],int n_p,int w_m,int h_m); // check whether the polices see the thief or not
int new_location_thief(int r_r[1][2],int w_m,int h_m);   // an idiot r_r change his location  // ok
int check_finish(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2]); //check whether the polices arrest the thief or not  // ok
int new_location_police(int r_p[][2],int n_p,int w_m,int h_m,int n);   //change police location when they don't know where is thief
int new_location_police_see(int r_p[][2],int r_r[1][2],int n_p,int w_m,int h_m,int n);  //change police location when they know where is thief


int main()
{
    printf("Hello Friends...Hello Friends!\n");
    Sleep(500);
    printf("some Polices want to arrest a r_r.\n");
    Sleep(500);
    printf("I want to consider a Matrix environment for this follow and scape process.\n");
    Sleep(500);
    printf("so I want you to enter the width and height of this matrix \nand also the number of polices,\n\n");
    Sleep(500);

    int w_m; //width
    printf("width(max is 13):");
    scanf("%d",&w_m);
    if(w_m>13)
    {
        printf("I told you that max is 13");
        return 1;
    }

    int h_m; //height
    printf("height(max is 13):");
    scanf("%d",&h_m);
    if(h_m>13)
    {
        printf("I told you that max is 13");
        return 1;
    }

    int n_p; //number of polices
    printf("polices(max is 100):");
    scanf("%d",&n_p);
    printf("\n");
    if(n_p>100)
    {
        printf("I told you that max is 100");
        return 1;
    }

    time_t t=time(NULL);
    srand(t);

    locate_first(r_p,n_p,w_m,h_m,m_m,r_r);

    int i;
    while(1)
    {
        if(check_police_see(r_p,r_r,n_p,w_m,h_m)==1)  //police see the thief
        {
            new_location_thief(r_r,w_m,h_m);
            count_r++;
            if(check_finish(r_p,n_p,w_m,h_m,m_m,r_r)==1)
            {
                return 0;
            }
            for(i=0;i<n_p;i++)  // error is here
            {
                new_location_police_see(r_p,r_r,n_p,w_m,h_m,i);
                count_p++;
                if(check_finish(r_p,n_p,w_m,h_m,m_m,r_r)==1)
                {
                    return 0;
                }
            }
            print_m(r_p,n_p,w_m,h_m,m_m,r_r);
            continue;
        }
        if(check_police_see(r_p,r_r,n_p,w_m,h_m)==0)  //police can't see the thief
        {
            new_location_thief(r_r,w_m,h_m);
            count_r++;
            if(check_finish(r_p,n_p,w_m,h_m,m_m,r_r)==1)
            {
                return 0;
            }
            for(i=0;i<n_p;i++) // error is here
            {
                new_location_police(r_p,n_p,w_m,h_m,i);
                count_p++;
                if(check_finish(r_p,n_p,w_m,h_m,m_m,r_r)==1)
                {
                    return 0;
                }
            }
            print_m(r_p,n_p,w_m,h_m,m_m,r_r);
            continue;
        }
    }
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();


    return 0;
}

void locate_first(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2])  // to locate the polices & thief  // ok
{
    int q=0;
    while(q<n_p)
    {
        r_p[q][0] = ((rand())%(w_m));  // x police
        r_p[q][1] = ((rand())%(h_m));  // y police
        if(m_m[r_p[q][1]][r_p[q][0]]!='P') // check to avoid locating 2 polices in 1 place
        {
            m_m[r_p[q][1]][r_p[q][0]]='P';
            q++;
        }
    }
    while(1) // to avoid finishing game at the first step
    {
        r_r[0][0]= ((rand())%(w_m)); //x thief
        r_r[0][1]= ((rand())%(h_m));  //y thief
        if(m_m[r_r[0][1]][r_r[0][0]]!='P')
        {
            m_m[r_r[0][1]][r_r[0][0]] = 'D';
            break;
        }
    }
    print_m(r_p,n_p,w_m,h_m,m_m,r_r);
}

void print_m(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2])  //draw the matrix  // ok
{
    int z,x,zz;
    for(z=0;z<h_m;z++)
    {
        for(x=0;x<w_m;x++)
        {
           m_m[z][x]=' ';
        }
    }
    m_m[r_r[0][1]][r_r[0][0]] = 'D';
    for(z=0;z<n_p;z++)
    {
        m_m[r_p[z][1]][r_p[z][0]] = 'P';
    }
    Sleep(2000);
    system("cls");
    for(z=0;z<w_m;z++)
    {
        printf("------");
    }
    printf("\n");
    for(z=(h_m-1);z>=0;z--)
    {
        for(x=0;x<w_m;x++)
        {
            printf("|  %c  ",m_m[z][x]);

        }
        printf("|");
        printf("\n");
        for(zz=0;zz<w_m;zz++)
        {
            printf("------");
        }
        printf("\n");
    }
}

void print_m_final(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2])  //draw the matrix final  // ok
{
    int qq,ww,zzz;
    for(qq=0;qq<h_m;qq++)
    {
        for(ww=0;ww<w_m;ww++)
        {
           m_m[qq][ww]=' ';
        }
    }
    m_m[r_r[0][1]][r_r[0][0]]='*';
    Sleep(1000);
    printf("\n");
    for(qq=0;qq<w_m;qq++)
    {
        printf("------");
    }
    printf("\n");
    for(qq=(h_m-1);qq>=0;qq--)
    {
        for(ww=0;ww<w_m;ww++)
        {
            printf("|  %c  ",m_m[qq][ww]);

        }
        printf("|");
        printf("\n");
        for(zzz=0;zzz<w_m;zzz++)
        {
            printf("------");
        }
        printf("\n");
    }
}

int check_police_see(int r_p[][2],int r_r[1][2],int n_p,int w_m,int h_m) // check whether the polices see the thief or not  //ok
{
    int w;
    for(w=0;w<n_p;w++)
    {
        if(fabs((r_p[w][0]-r_r[0][0])<=2)  &&  fabs((r_p[w][1]-r_r[0][1])<=2))
        {
            return 1;
        }
    }
    return 0;
}

int new_location_thief(int r_r[1][2],int w_m,int h_m)   // an idiot r_r change his location  //ok
{
    int qd;
    qd = ((rand())%9)+1;
    if((qd==1)&&(r_r[0][0]!=0)&&(r_r[0][1])!=(h_m-1))
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==2)&&(r_r[0][1])!=(h_m-1))
    {
        r_r[0][0]= (r_r[0][0]); //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==3)&&(r_r[0][0]!=(w_m-1))&&(r_r[0][1])!=(h_m-1))
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==4)&&(r_r[0][0]!=(w_m-1)))
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1]);  //new y thief
        return 0;
    }
    if((qd==5)&&(r_r[0][0]!=(w_m-1))&&(r_r[0][1])!=0)
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==6)&&(r_r[0][1])!=0)
    {
        r_r[0][0]= (r_r[0][0]); //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==7)&&(r_r[0][0]!=0)&&(r_r[0][1])!=0)
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==8)&&(r_r[0][0]!=0))
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1]);  //new y thief
        return 0;
    }
    if( qd==9 )
    {
        r_r[0][0]= r_r[0][0]; //new x thief
        r_r[0][1]= r_r[0][1];  //new y thief
        return 0;
    }
    new_location_thief(r_r,w_m,h_m);
    return 0;
}

int check_finish(int r_p[][2],int n_p,int w_m,int h_m,int m_m[30][30],int r_r[1][2]) //check whether the polices arrest the thief or not  // ok
{
    int y;
    for(y=0;y<n_p;y++)
    {
        if(r_r[0][0]==r_p[y][0])
        {
            if(r_r[0][1]==r_p[y][1])
            {
                printf("\n");
                printf("The follow and scape finished.\n");
                Sleep(1000);
                printf("Police arrested the thief.\n");
                printf("The place that thief arrested is signed with *.\n");
                print_m_final(r_p,n_p,w_m,h_m,m_m,r_r);
                printf("\n");
                Sleep(500);
                printf("Thief change location: %d times\n",count_r);
                printf("Police change location: %d times\n",count_p);
                return 1;
            }
        }
    }
    return 0;
}

int new_location_police(int r_p[][2],int n_p,int w_m,int h_m,int n)   //change police location when they don't know where is thief  //ok
{
    int u;
    u = (rand()%9)+1;
    if((u==1)&&(r_p[n][0]!=0)&&(r_p[n][1])!=(h_m-1))
    {
        r_p[n][0]= (r_p[n][0])-1; //new x police
        r_p[n][1]= (r_p[n][1])+1;  //new y police
        return 0;
    }
    if((u==2)&&(r_p[n][1])!=(h_m-1))
    {
        r_p[n][0]= (r_p[n][0]); //new x police
        r_p[n][1]= (r_p[n][1])+1;  //new y police
        return 0;
    }
    if((u==3)&&(r_p[n][0]!=(w_m-1))&&(r_p[n][1])!=(h_m-1))
    {
        r_p[n][0]= (r_p[n][0])+1; //new x police
        r_p[n][1]= (r_p[n][1])+1;  //new y police
        return 0;
    }
    if((u==4)&&(r_p[n][0]!=(w_m-1)))
    {
        r_p[n][0]= (r_p[n][0])+1; //new x police
        r_p[n][1]= (r_p[n][1]);  //new y police
        return 0;
    }
    if((u==5)&&(r_p[n][0]!=(w_m-1))&&(r_p[n][1])!=0)
    {
        r_p[n][0]= (r_p[n][0])+1; //new x police
        r_p[n][1]= (r_p[n][1])-1;  //new y police
        return 0;
    }
    if((u==6)&&(r_p[n][1])!=0)
    {
        r_p[n][0]= (r_p[n][0]); //new x police
        r_p[n][1]= (r_p[n][1])-1;  //new y police
        return 0;
    }
    if((u==7)&&(r_p[n][0]!=0)&&(r_p[n][1])!=0)
    {
        r_p[n][0]= (r_p[n][0])-1; //new x police
        r_p[n][1]= (r_p[n][1])-1;  //new y police
        return 0;
    }
    if((u==8)&&(r_p[n][0]!=0))
    {
        r_p[n][0]= (r_p[n][0])-1; //new x police
        r_p[n][1]= (r_p[n][1]);  //new y police
        return 0;
    }
    if( u==9 )
    {
        r_p[n][0]= r_p[n][0]; //new x r_r
        r_p[n][1]= r_p[n][1];  //new y r_r
        return 0;
    }
    new_location_police(r_p,n_p,w_m,h_m,n);
    return 0;
}

int new_location_police_see(int r_p[][2],int r_r[1][2],int n_p,int w_m,int h_m,int n)  //change police location when they know where is thief  //ok
{
    if(fabs(r_p[n][0]-r_r[0][0])<=1  && fabs(r_p[n][1]-r_r[0][1])<=1)  //layer 1
    {
        r_p[n][0] = r_r[0][0];
        r_p[n][1] = r_r[0][1];
        return 0;
    }
    if(fabs(r_p[n][0]-r_r[0][0])<=2  && fabs(r_p[n][1]-r_r[0][1])<=2  &&  fabs(r_p[n][0]-r_r[0][0])>1  && fabs(r_p[n][1]-r_r[0][1])>1)  //layer 2
    {
        if(r_p[n][0]<r_r[0][0])  // right side
        {
            if(r_p[n][1]<r_r[0][1]) //upside
            {
                r_p[n][0] = r_p[n][0]+1;
                r_p[n][1] = r_p[n][1]+1;
                return 0;
            }
            if(r_p[n][1]>r_r[0][1]) //downside
            {
                r_p[n][0] = r_p[n][0]+1;
                r_p[n][1] = r_p[n][1]-1;
                return 0;
            }
            else
            {
                r_p[n][0] = r_p[n][0]+1;
                r_p[n][1] = r_p[n][1];
                return 0;
            }
        }
        if(r_p[n][0]>r_r[0][0])  // left side
        {
            if(r_p[n][1]<r_r[0][1]) //upside
            {
                r_p[n][0] = r_p[n][0]-1;
                r_p[n][1] = r_p[n][1]+1;
                return 0;
            }
            if(r_p[n][1]>r_r[0][1]) //downside
            {
                r_p[n][0] = r_p[n][0]-1;
                r_p[n][1] = r_p[n][1]-1;
                return 0;
            }
            else
            {
                r_p[n][0] = r_p[n][0]-1;
                r_p[n][1] = r_p[n][1];
                return 0;
            }
        }
        else
        {
            if(r_p[n][1]<r_r[0][1]) //upside
            {
                r_p[n][0] = r_p[n][0];
                r_p[n][1] = r_p[n][1]+1;
                return 0;
            }
            if(r_p[n][1]>r_r[0][1]) //downside
            {
                r_p[n][0] = r_p[n][0];
                r_p[n][1] = r_p[n][1]-1;
                return 0;
            }
        }
    }
    else  //outer layers
    {
        if(r_p[n][0]<r_r[0][0])  // right side
        {
            r_p[n][0] = r_p[n][0]+1;
            r_p[n][1] = r_p[n][1];
            return 0;
        }
        if(r_p[n][0]>r_r[0][0])  // left side
        {
            r_p[n][0] = r_p[n][0]-1;
            r_p[n][1] = r_p[n][1];
            return 0;
        }
        else
        {
            if(r_p[n][1]<r_r[0][1]) //upside
            {
                r_p[n][0] = r_p[n][0];
                r_p[n][1] = r_p[n][1]+1;
                return 0;
            }
            if(r_p[n][1]>r_r[0][1]) //downside
            {
                r_p[n][0] = r_p[n][0];
                r_p[n][1] = r_p[n][1]-1;
                return 0;
            }
        }
    }
}


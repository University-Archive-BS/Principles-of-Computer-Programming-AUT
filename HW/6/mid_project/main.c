#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>

int g;
int xt,yt;
int check_repetition(int r_p[g][2],int xt,int yt)  // check to avoid locating 2 polices in 1 place
{
    int b;
    for(b=0;b<g;b++)
    {
        if(xt == r_p[b][0])
        {
            if(yt == r_p[b][1])
            {
                return 0;
            }
        }
    }
    return 1;
}

int s;
void yes_repetition(int r_p[s][2],int w_m,int h_m)  // to change a repetitive police location
{
    r_p[s][0] = ((rand())%(w_m));  // x police
    xt = r_p[s][0];
    r_p[s][1] = ((rand())%(h_m));  // y police
    yt = r_p[s][1];
    while(1)
    {
        if (check_repetition(r_p[s][2],xt,yt)==1)
        {
            break;
        }
        if (check_repetition(r_p[s][2],xt,yt)==0)
        {
            yes_repetition(r_p[s][2],w_m,h_m);
        }
    }
}

void beginning_location_police(int r_p[][2],int n_p,int w_m,int h_m) // to locate the polices
{
    int q,b;
    for(q=0;q<n_p;q++)
    {
        r_p[q][0] = ((rand())%(w_m));  // x police
        xt = r_p[q][0];
        r_p[q][1] = ((rand())%(h_m));  // y police
        yt = r_p[q][1];
        while(1)
        {
            if (check_repetition(r_p[q][2],xt,yt)==1)
            {
                break;
            }
            if (check_repetition(r_p[q][2],xt,yt)==0)
            {
                yes_repetition(r_p[q][2],w_m,h_m);
            }
        }
    }
}

// until now...I located polices correctly in the matrix

int check_first_thief_police(int r_p[][2],int r_r[1][2],int n_p)  // to avoid finishing game at the first second
{
    int qq;
    for(qq=0;qq<n_p;qq++)
    {
        if(r_r[0][0]==r_p[qq][0])
        {
            if(r_r[0][1]==r_p[qq][1])
            {
                return 0;
            }
        }
    }
    return 1;
}

int beginning_location_thief(int r_r[1][2],int n_p,int w_m,int h_m) // to locate the thief
{
    r_r[0][0]= ((rand())%(w_m)); //x thief
    r_r[0][1]= ((rand())%(h_m));  //y thief
}

// until here we located polices and the thief in their first locations

int thief[1][2];
int check_police_see(int r_p[][2],int r_r[1][2],int n_p,int w_m,int h_m) // check whether the polices see the thief or not
{
    int ggg;
    for(ggg=0;ggg<n_p;ggg++)
    {
        if(fabs((r_p[ggg][0]-r_r[0][0])<=2)  &&  fabs((r_p[ggg][1]-r_r[0][1])<=2))
        {
            thief[0][0] = r_r[0][0];
            thief[0][1] = r_r[0][1];
            return 1;
        }
    }
    return 0;
}

int new_location_thief(int r_r[1][2],int w_m,int h_m)   // an idiot thief change his location
{
    int qd;
    qd = ((rand())%9)+1;
    if((qd==1)&&(r_r[0][0]!=1)&&(r_r[0][1])!=h_m)
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==2)&&(r_r[0][1])!=h_m)
    {
        r_r[0][0]= (r_r[0][0]); //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==3)&&(r_r[0][0]!=w_m)&&(r_r[0][1])!=h_m)
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1])+1;  //new y thief
        return 0;
    }
    if((qd==4)&&(r_r[0][0]!=w_m))
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1]);  //new y thief
        return 0;
    }
    if((qd==5)&&(r_r[0][0]!=w_m)&&(r_r[0][1])!=1)
    {
        r_r[0][0]= (r_r[0][0])+1; //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==6)&&(r_r[0][1])!=1)
    {
        r_r[0][0]= (r_r[0][0]); //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==7)&&(r_r[0][0]!=1)&&(r_r[0][1])!=1)
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1])-1;  //new y thief
        return 0;
    }
    if((qd==8)&&(r_r[0][0]!=1))
    {
        r_r[0][0]= (r_r[0][0])-1; //new x thief
        r_r[0][1]= (r_r[0][1]);  //new y thief
        return 0;
    }
    if( qd==9 )
    {
        r_r[0][0]= r_r[0][0]; //new x thief
        r_r[0][1]= r_r[0][1];  //new y thief
    }
    else
    {
        new_location_thief(r_r[1][2],w_m,h_m);
    }
}

int j;
int new_location_police(int r_p[j][2],int n_p,int w_m,int h_m)   //change police location when they don't know where is thief
{
    int u;
    u = ((rand())%9)+1;
    if((u==1)&&(r_p[j][0]!=1)&&(r_p[j][1])!=h_m)
    {
        r_p[j][0]= (r_p[j][0])-1; //new x police
        r_p[j][1]= (r_p[j][1])+1;  //new y police
        return 0;
    }
    if((u==2)&&(r_p[j][1])!=h_m)
    {
        r_p[j][0]= (r_p[j][0]); //new x police
        r_p[j][1]= (r_p[j][1])+1;  //new y police
        return 0;
    }
    if((u==3)&&(r_p[j][0]!=w_m)&&(r_p[j][1])!=h_m)
    {
        r_p[j][0]= (r_p[j][0])+1; //new x police
        r_p[j][1]= (r_p[j][1])+1;  //new y police
        return 0;
    }
    if((u==4)&&(r_p[j][0]!=w_m))
    {
        r_p[j][0]= (r_p[j][0])+1; //new x police
        r_p[j][1]= (r_p[j][1]);  //new y police
        return 0;
    }
    if((u==5)&&(r_p[j][0]!=w_m)&&(r_p[j][1])!=1)
    {
        r_p[j][0]= (r_p[j][0])+1; //new x police
        r_p[j][1]= (r_p[j][1])-1;  //new y police
        return 0;
    }
    if((u==6)&&(r_p[j][1])!=1)
    {
        r_p[j][0]= (r_p[j][0]); //new x police
        r_p[j][1]= (r_p[j][1])-1;  //new y police
        return 0;
    }
    if((u==7)&&(r_p[j][0]!=1)&&(r_p[j][1])!=1)
    {
        r_p[j][0]= (r_p[j][0])-1; //new x police
        r_p[j][1]= (r_p[j][1])-1;  //new y police
        return 0;
    }
    if((u==8)&&(r_p[j][0]!=1))
    {
        r_p[j][0]= (r_p[j][0])-1; //new x police
        r_p[j][1]= (r_p[j][1]);  //new y police
        return 0;
    }
    if( u==9 )
    {
        r_p[j][0]= r_p[j][0]; //new x thief
        r_p[j][1]= r_p[j][1];  //new y thief
    }
    else
    {
        new_location_police(r_p[j][2],n_p,w_m,h_m);
    }
}

int new_location_police_see(int r_p[][2],int n_p,int w_m,int h_m)  //change police location when they know where is thief
{
    int kk;
    for(kk=0;kk<n_p;kk++)
    {
        if(fabs(r_p[kk][0]-thief[0][0])<=1  && fabs(r_p[kk][1]-thief[0][1])<=1)  //layer 1
        {
            r_p[kk][0] = thief[0][0];
            r_p[kk][1] = thief[0][1];
            return 0;
        }
        if(fabs(r_p[kk][0]-thief[0][0])<=2  && fabs(r_p[kk][1]-thief[0][1])<=2)  //layer 2
        {
            if(r_p[kk][0]<thief[0][0])  // right side
            {
                if(r_p[kk][1]<thief[0][1]) //upside
                {
                    r_p[kk][0] = r_p[kk][0]+1;
                    r_p[kk][1] = r_p[kk][1]+1;
                    return 0;
                }
                if(r_p[kk][1]>thief[0][1]) //downside
                {
                    r_p[kk][0] = r_p[kk][0]+1;
                    r_p[kk][1] = r_p[kk][1]-1;
                    return 0;
                }
                else
                {
                    r_p[kk][0] = r_p[kk][0]+1;
                    r_p[kk][1] = r_p[kk][1];
                    return 0;
                }
            }
            if(r_p[kk][0]>thief[0][0])  // left side
            {
                if(r_p[kk][1]<thief[0][1]) //upside
                {
                    r_p[kk][0] = r_p[kk][0]-1;
                    r_p[kk][1] = r_p[kk][1]+1;
                    return 0;
                }
                if(r_p[kk][1]>thief[0][1]) //downside
                {
                    r_p[kk][0] = r_p[kk][0]-1;
                    r_p[kk][1] = r_p[kk][1]-1;
                    return 0;
                }
                else
                {
                    r_p[kk][0] = r_p[kk][0]-1;
                    r_p[kk][1] = r_p[kk][1];
                    return 0;
                }
            }
            else
            {
                if(r_p[kk][1]<thief[0][1]) //upside
                {
                    r_p[kk][0] = r_p[kk][0];
                    r_p[kk][1] = r_p[kk][1]+1;
                    return 0;
                }
                if(r_p[kk][1]>thief[0][1]) //downside
                {
                    r_p[kk][0] = r_p[kk][0];
                    r_p[kk][1] = r_p[kk][1]-1;
                    return 0;
                }
            }
        }
        else  //outer layers
        {
            if(r_p[kk][0]<thief[0][0])  // right side
            {
                r_p[kk][0] = r_p[kk][0]+1;
                r_p[kk][1] = r_p[kk][1];
                return 0;
            }
            if(r_p[kk][0]>thief[0][0])  // left side
            {
                r_p[kk][0] = r_p[kk][0]-1;
                r_p[kk][1] = r_p[kk][1];
                return 0;
            }
            else
            {
                if(r_p[kk][1]<thief[0][1]) //upside
                {
                    r_p[kk][0] = r_p[kk][0];
                    r_p[kk][1] = r_p[kk][1]+1;
                    return 0;
                }
                if(r_p[kk][1]>thief[0][1]) //downside
                {
                    r_p[kk][0] = r_p[kk][0];
                    r_p[kk][1] = r_p[kk][1]-1;
                    return 0;
                }
            }
        }
    }
}

int main()
{
    printf("Hello Friends...Hello Friends!\n");
    printf("some Polices want to arrest a thief.\n");
    printf("I want to consider a Matrix environment for this follow and scape process.\n");
    printf("so I want you to enter the width and height of this matrix and also the number of polices,\n");

    int w_m; //width
    printf("width:");
    scanf("%d",&w_m);

    int h_m; //height
    printf("height:");
    scanf("%d",&h_m);

    int n_p; //number of polices
    printf("polices:");
    scanf("%d",&n_p);
    printf("\n");

    char m_m[h_m][w_m];  //making the matrix environment
    int c,v;
    for(c=0;c<h_m;c++)  //fill the matrix with space
    {
        for(v=0;v<w_m;v++)
        {
           m_m[c][v]=' ';
        }
    }

    int r_p[n_p][2]; //location of the polices
    int r_r[1][2]; //location of the thief

    time_t t = time(NULL);
    srand(t);

    beginning_location_police(r_p,n_p,w_m,h_m); // locate polices
    for(c=0;c<n_p;c++)
    {
        m_m[r_p[c][1]][r_p[c][0]] = 'P';
    }

    //  for show where is the polices
    int i;
    for(i=0;i<n_p;i++)
    {
        printf("%d  ",r_p[i][0]);
        printf("%d\n",r_p[i][1]);
    }
    // until here

    while(1) //check to avoid finishing the process in the first second
    {
        beginning_location_thief(r_r,n_p,w_m,h_m);  //locate the thief
        if(check_first_thief_police(r_p,r_r,n_p)==0)
        {
            return beginning_location_thief(r_r,n_p,w_m,h_m);
        }
        if(check_first_thief_police(r_p,r_r,n_p)==1)
        {
            break;
        }
    }

    // to show where is the thief
    printf("%d  ",r_r[0][0]);
    printf("%d\n",r_r[0][1]);
    // until here
    Sleep(5);
    m_m[r_r[0][1]][r_r[0][0]] = 'D';

    int count_r=0; //counter of thief change locations
    int count_p=0; //counter of polices change locations

    for(c=(h_m)-1;c>=0;c--)  //draw the matrix
    {
        for(v=0;v<w_m;v++)
        {
            printf("%c",m_m[c][v]);
            printf(" ");
        }
        printf("\n");
    }
    int iii,ttt,kkk,jjj,ooo;
    while(1)
    {
        if(check_police_see(r_p,r_r,n_p,w_m,h_m)==1)  //police see the thief
        {
            new_location_thief(r_r,w_m,h_m);
            count_r++;
            for(iii=0;iii<n_p;iii++) //thief go to police haha...
            {
                if(r_r[0][0]==r_p[iii][0])
                {
                    if(r_r[0][1]==r_p[iii][1])
                    {
                        printf("The follow and scape finished.\n");
                        printf("Police arrested the thief.\n");
                        printf("thief change location: %d times\n",count_r);
                        printf("Police change location: %d times\n",count_p);
                        return 0;
                    }
                }
            }
            for(jjj=0;jjj<n_p;jjj++)
            {
                new_location_police_see(r_p[jjj][2],n_p,w_m,h_m);
                count_p++;
                if(r_r[0][0]==r_p[jjj][0])
                {
                    if(r_r[0][1]==r_p[jjj][1])
                    {
                        printf("The follow and scape finished.\n");
                        printf("Police arrested the thief.\n");
                        printf("thief change location: %d times\n",count_r);
                        printf("Police change location: %d times\n",count_p);
                        return 0;
                    }
                }
            }
            system("cls");
            for(c=(h_m)-1;c>=0;c--)  //draw the matrix
            {
                for(v=0;v<w_m;v++)
                {
                    printf("%c",m_m[c][v]);
                    printf(" ");
                }
                printf("\n");
            }
            continue;
        }
        if(check_police_see(r_p,r_r,n_p,w_m,h_m)==0)  //police can't see the thief
        {
            new_location_thief(r_r,w_m,h_m);
            count_r++;
            for(kkk=0;kkk<n_p;kkk++)   //thief go to police haha...
            {
                if(r_r[0][0]==r_p[kkk][0])
                {
                    if(r_r[0][1]==r_p[kkk][1])
                    {
                        printf("The follow and scape finished.\n");
                        printf("Police arrested the thief.\n");
                        printf("thief change location: %d times\n",count_r);
                        printf("Police change location: %d times\n",count_p);
                        return 0;
                    }
                }
            }
            for(ooo=0;ooo<n_p;ooo++)
            {
                new_location_police(r_p[ooo][2],n_p,w_m,h_m);
                count_p++;
            }
            for(ttt=0;ttt<n_p;ttt++)
            {
                if(r_r[0][0]==r_p[ttt][0])
                {
                    if(r_r[0][1]==r_p[ttt][1])
                    {
                        printf("The follow and scape finished.\n");
                        printf("Police arrested the thief.\n");
                        printf("thief change location: %d times\n",count_r);
                        printf("Police change location: %d times\n",count_p);
                        return 0;
                    }
                }
            }
            system("cls");
            for(c=(h_m)-1;c>=0;c--)  //draw the matrix
            {
                for(v=0;v<w_m;v++)
                {
                    printf("%c",m_m[c][v]);
                    printf(" ");
                }
                printf("\n");
            }
        }
    }
    getchar();
    getchar();
    return 0;
}

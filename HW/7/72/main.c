#include <stdio.h>
#include <stdlib.h>

int i,j,m,n;

void zarb_m(int n,int m,int a[n][m],int b[m][n],int c[n][n])
{
    int s=0;
    int r;
    for(r=0;r<n;r++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                s += a[r][j]*b[j][i];
            }
            c[r][i] = s;
            s=0;
        }
    }

}

void chap_m(int m,int n,int a[n][m]) // print matrix
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d",&m);
    int p=0;

    int A[100][m];
    for(i=0; ;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&A[i][j]);
        }
        for(j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
                p++;
            }
        }
        if(p==m)
        {
            n = i;
            break;
        }
    }
    printf("A:\n");
    chap_m(m,n,A);
    printf("\n");

    printf("B:\n");
    int B[m][n];
    for(i=0;i<m;i++)      //B
    {
        for(j=0;j<n;j++)
        {
            B[i][j] = A[j][i];
        }
    }
    chap_m(n,m,B);
    printf("\n");

    int C[n][n],D[m][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            D[i][j]=0;
        }
    }

    printf("C:\n");
    zarb_m(n,m,A,B,C);
    chap_m(n,n,C);
    printf("\n");
    printf("D:\n");
    zarb_m(m,n,B,A,D);
    chap_m(m,m,D);
    return 0;
}

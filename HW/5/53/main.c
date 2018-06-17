#include <stdio.h>
#include <stdlib.h>

int res_call=0;
int combination(int p,int q)
{
    res_call++;
    if(q==0 || p==q)
    {
        return 1;
    }
    else
    {
        return (combination((p-1),q)+combination((p-1),(q-1)));
    }
}

int main()
{
    int n,m,res_comb;
    scanf("%d",&n);
    scanf("%d",&m);
    res_comb= combination(n,m);
    printf("%d\n",res_comb);
    printf("%d",res_call);
    return 0;
}

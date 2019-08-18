#include<cstdio>
int f[2][4205];
int main()
{
    int n, p, cur=1;
    scanf("%d%d",&n,&p);
    if(n==1)return !printf("%d\n",1%p);
    f[cur^1][1]=1;
    for(int i = 2; i <= n; i++, cur^=1)
        for(int j = 1; j <= i; j++)
            f[cur][j]=(f[cur][j-1]+f[cur^1][i-j])%p;
    printf("%d\n",f[cur^1][n]*2%p);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define MAXN 100
using namespace std;
LL n,ans;
LL fib[MAXN]={0,1,2},f[MAXN][2],a[MAXN];
int top;
int main()
{
    cin>>n;
    for (int i=3;i<=90;i++) fib[i]=fib[i-1]+fib[i-2];
    for (int i=90;i>=1;i--)
        if (n>=fib[i])  n-=fib[i],a[++top]=i;
    f[top][1]=1;f[top][0]=(a[top]-1)>>1;
    for (int i=top-1;i;i--)
    {
        f[i][1]=f[i+1][0]+f[i+1][1];
        f[i][0]=((a[i]-a[i+1]-1)>>1)*f[i+1][1]+((a[i]-a[i+1])>>1)*f[i+1][0];
    }
    ans=f[1][0]+f[1][1];
    cout<<ans<<endl;
}

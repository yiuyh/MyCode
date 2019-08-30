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

/*
Description
    第二关和很出名的斐波那契数列有关，地球上的OIer都知道：F1=1, F2=2, Fi = Fi-1 + Fi-2，
    每一项都可以称为斐波那契数。现在给一个正整数N，它可以写成一些斐波那契数的和的形式。
    如果我们要求不同的方案中不能有相同的斐波那契数，那么对一个N最多可以写出多少种方案呢？
Input
       只有一个整数N。
Output
       一个方案数
Sample Input
       16
Sample Output
       4
*/

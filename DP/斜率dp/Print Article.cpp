#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 500003
using namespace std;
int n,m,q[N],a[N],sum[N],f[N];
int y(int x,int y)
{
	return f[y]-f[x]+sum[y]*sum[y]-sum[x]*sum[x];
}
int x(int x,int y)
{
	return sum[y]-sum[x];
}
int main()
{
	 while (scanf("%d%d",&n,&m)!=EOF)
	  {
	  	memset(sum,0,sizeof(sum));
	  	memset(f,0,sizeof(f));
	  	for (int i=1;i<=n;i++)
		  {
		  	scanf("%d",&a[i]);
		  	sum[i]=sum[i-1]+a[i];
		  }
		int head=0,tail=0;
		for (int i=1;i<=n;i++)
		{
			int k=2*sum[i];
			while (head<tail&&y(q[head],q[head+1])<=k*x(q[head],q[head+1]))
			 head++;
			f[i]=f[q[head]]+x(q[head],i)*x(q[head],i)+m;
			while (head<tail&&y(q[tail-1],q[tail])*x(q[tail],i)>=y(q[tail],i)*x(q[tail-1],q[tail]))
			 tail--;
			tail++; q[tail]=i;
		}
		printf("%d\n",f[n]);
	  }
	 return 0;
}

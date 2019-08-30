#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#define inf 1000000000

using namespace std;

bool tag[21],a[21][110],vis[21];
int head[21],to[1010],next[1010],len[1010],dis[21],q[21];
int f[110][110],dp[110];
int n,m,num,k,Day,cnt;

void addedge(int x,int y,int z)
{
	num++;to[num]=y;len[num]=z;next[num]=head[x];head[x]=num;
}

void spfa()
{
	for (int i=2;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	int l=0,r=1;
	q[1]=1;vis[1]=1;
	while (l!=r)
	{
		l++;if (l==21) l=0;
		int x=q[l];
		for (int p=head[x];p;p=next[p])
		  if (dis[x]+len[p]<dis[to[p]])
		  {
		  	dis[to[p]]=dis[x]+len[p];
		  	if (!vis[to[p]] && !tag[to[p]])
		  	{
		  		r++;if (r==21) r=0;
		  		q[r]=to[p];vis[to[p]]=1;
		  	}
		  }
		vis[x]=0;
	}
}
int main()
{
	scanf("%d%d%d%d",&Day,&n,&k,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	scanf("%d",&cnt);
	for (int i=1;i<=cnt;i++)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		for (int j=l;j<=r;j++) a[x][j]=1;
	}
	for (int i=1;i<=Day;i++)
	{
		memset(tag,0,sizeof(tag));
		for (int j=i;j<=Day;j++)
		{
			for (int k=1;k<=n;k++) tag[k]|=a[k][j];
			spfa();
			f[i][j]=dis[n];
		}
	}
	dp[0]=-k;
	for (int i=1;i<=Day;i++)
	{
		dp[i]=inf;
		for (int j=0;j<i;j++) if (f[j+1][i]!=inf) dp[i]=min(dp[i],dp[j]+f[j+1][i]*(i-j)+k);
	}
	printf("%d\n",dp[Day]);
	return 0;
}


/*

Description
　　物流公司要把一批货物从码头A运到码头B。由于货物量比较大，需要n天才能运完。货物运输过程中一般要转
停好几个码头。物流公司通常会设计一条固定的运输路线，以便对整个运输过程实施严格的管理和跟踪。由于各种
因素的存在，有的时候某个码头会无法装卸货物。这时候就必须修改运输路线，让货物能够按时到达目的地。但是
修改路线是一件十分麻烦的事情，会带来额外的成本。因此物流公司希望能够订一个n天的运输计划，使得总成本
尽可能地小。
Input
　　第一行是四个整数n（1<=n<=100）、m（1<=m<=20）、K和e。n表示货物运输所需天数，m表示码头总数，K表示
每次修改运输路线所需成本。接下来e行每行是一条航线描述，包括了三个整数，依次表示航线连接的两个码头编
号以及航线长度（>0）。其中码头A编号为1，码头B编号为m。单位长度的运输费用为1。航线是双向的。再接下来
一行是一个整数d，后面的d行每行是三个整数P（ 1 < P < m）、a、b（1< = a < = b < = n）。表示编号为P的码
头从第a天到第b天无法装卸货物（含头尾）。同一个码头有可能在多个时间段内不可用。但任何时间都存在至少一
条从码头A到码头B的运输路线。
Output
　　包括了一个整数表示最小的总成本。总成本=n天运输路线长度之和+K*改变运输路线的次数。
Sample Input
5 5 10 8
1 2 1
1 3 3
1 4 2
2 3 2
2 4 4
3 4 1
3 5 2
4 5 2
4
2 2 3
3 1 1
3 3 3
4 4 5
Sample Output
32
//前三天走1-4-5，后两天走1-3-5，这样总成本为(2+2)*3+(3+2)*2+10=32

*/

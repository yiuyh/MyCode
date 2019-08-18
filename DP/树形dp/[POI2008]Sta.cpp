#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define LL long long
const int max_n=1e6+5;
const int max_e=max_n*2;
int n,x,y;
int tot,next[max_e],point[max_n],v[max_e];
LL h[max_n],size[max_n],sum,ans;
int ansp;
inline void add(int x,int y){++tot;next[tot]=point[x];point[x]=tot;v[tot]=y;}
inline void dfs(int x,int fa,int dep){
    h[x]=dep; sum+=h[x]; size[x]=1;
    for (int i=point[x];i;i=next[i])
      if (v[i]!=fa){
        dfs(v[i],x,dep+1);
        size[x]+=size[v[i]];
      }
}
inline void calc_ans(int x,int fa,LL sum){
    for (int i=point[x];i;i=next[i])
      if (v[i]!=fa){
        LL t=sum-size[v[i]]+(size[1]-size[v[i]]);
        if (t>ans||t==ans&&v[i]<ansp) ans=t,ansp=v[i];
        calc_ans(v[i],x,t);
      }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,0,1); ans=sum; ansp=1;
    calc_ans(1,0,sum);
    printf("%d\n",ansp);
}

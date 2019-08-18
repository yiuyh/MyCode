#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long num[66537],dp[65][66537],P[65],n,tmp[65][66537];
int dig[100],sz;
bool vis[100];
int k;

void dfs(int pos,int remain,int limit){
    if(pos<0){
        num[remain]++;
        return ;
    }
    if(!limit&&vis[pos]){
        int rr=remain*P[pos+1]%k;
        for(int i=0;i<k;i++)
            num[ (rr+i)%k ]+=dp[pos][i];
        return ;
    }
    int now=sz;
    if(!limit)
        ++sz,memcpy(tmp[now],num,k*sizeof(long long));
    int last=(limit==0 ? 1:dig[pos]);
    for(int i=0;i<=last;i++)
        dfs(pos-1,(remain*3+i)%k,limit && (i==last) );
    if(!limit){
        vis[pos]=true;
        for(int i=0;i<k;i++)
            dp[pos][i]=num[i]-tmp[now][i];
    }
}

void solve(long long m){
    int ed=0;
    for(int i=0;i<=63;i++){
        if((1LL<<i)&m)
            ed=i,dig[i]=1;
        else
            dig[i]=0;
    }
    dfs(ed,0,1);
}

int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%lld%d",&n,&k);
        memset(vis,false,sizeof(vis));
        memset(num,0,sizeof(num));
        memset(dp,0,k*sizeof(long long));
        memset(tmp,0,k*sizeof(long long));
        P[0]=1,sz=0;
        for(int i=1;i<=64;i++)
            P[i]=P[i-1]*3%k;
        solve(n);
        long long ans=0;
        num[0]--;
        for(int i=0;i<k;i++)
            ans^=num[i];
        printf("%lld\n",ans);
    }
    return 0;
}

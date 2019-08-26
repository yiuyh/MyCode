//dfs序转移
#include<bits/stdc++.h>

using namespace std;
const int N = 300;
vector<int> g[N];
int now, pos[N], r[N], Size[N];
void dfs(int u){
    pos[++now] = u;
    Size[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
        dfs(g[u][i]), Size[u] += Size[g[u][i]];
    r[u] = now;
}
int dp[N][N], v[N];

int main(){
    int n, m, a, b;
    while(~scanf("%d%d", &n, &m)){
        if(n==0 && m==0) break;
        now = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= n+1; j++) dp[i][j] = 0;
        for(int i = 0; i <= n; i++) g[i].clear();
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &a, &v[i]);
            g[a].push_back(i);
        }
        dfs(0);
        m++;
        for(int i = n+1; i; i--){
            //cout << pos[i] << " ";
            int x = pos[i];
            for(int j = 1; j <= m; j++)
                dp[i][j] = max(dp[i+1][j-1]+v[x], dp[i+Size[x]][j]);
        }
        cout << endl;
        cout << dp[1][m] << endl;
    }
    return 0;
}


//运用树形dp独特的优化,枚举有效的元素

//dp[i][j]代表在以i为根的子树中选择j个元素所能容纳的最大值
const int N = 300;
vector<int> g[N];
int now, pos[N], l[N], Size[N];
int dp[N][N], v[N], n, m, a;

void dfs(int u){
    Size[u] = 1; dp[u][1] = v[u];
    for(int k = 0; k < g[u].size(); k++){
        dfs(g[u][k]);
        for(int i = Size[u]; i >= 1; i--){
            for(int j = 0; j<=Size[g[u][k]]&&i+j<=m; j++){
                dp[u][i+j] = max(dp[u][i+j], dp[u][i]+dp[g[u][k]][j]);
            }
        }
        Size[u] += Size[g[u][k]];
    }
}
// ans = dp[0][m]

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (1<<19)+5;
int n, m, g[20][20], f[maxn];
ll dp[maxn][20];
int lowbit(int x){return x&-x;}

int main(){
    for(int i = 0; i < 20; i++){
        f[1<<i] = i;
    }
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a>b) swap(a, b);
        g[a][b] = g[b][a] = 1;
        dp[(1<<a)^(1<<b)][b] = 1;
    }
    int N = 1<<n;
    ll ans = 0;
    for(int S = 0; S < N; S++){
        int i = f[lowbit(S)];
        for(int j = i+1; j < n; j++){
            if((S>>j)&1){
                int T = S^(1<<i)^(1<<j);
                if(!T) continue;
                for(;T;T-=lowbit(T)){
                    int k = f[lowbit(T)];
                    if(g[j][k]) dp[S][j] += dp[S^(1<<j)][k];
                }
                if(g[i][j]) ans += dp[S][j];
            }
        }
    }
    cout << ans/2 << endl;
    return 0;
}

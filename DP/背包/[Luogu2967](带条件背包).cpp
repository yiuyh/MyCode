#include<bits/stdc++.h>

using namespace std;
int dp[55][100010];


int main(){
    int n, V;
    cin >> n >> V;
    for(int i = 1; i <= n; i++){
        int p, g;
        scanf("%d%d", &p, &g);
        for (int j=V; j>=p; --j)  dp[i][j] = dp[i-1][j-p];
        while(g--){
            int w, v;
            scanf("%d%d", &w, &v);
            for(int j = V; j >= p+w; j--) dp[i][j] = max(dp[i][j], dp[i][j-w]+v);
        }
        for(int j = 0; j <= V; j++) dp[i][j] = max(dp[i][j], dp[i-1][j]);
    }
    int ans = 0;
    for(int i = 0; i <= V; i++){
        ans =  max(dp[n][i], ans);
    }
    cout << ans << endl;
    return 0;
}

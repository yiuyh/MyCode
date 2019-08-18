#include<bits/stdc++.h>

using namespace std;
int arr[100010], dp[100010];
int vis[10][100010];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < m-1; i++){
        int cur, next;
        scanf("%d", &cur);
        for(int j = 0; j < n-1; j++){
            scanf("%d", &next);
            vis[i][next] = cur;
            cur = next;
        }
    }
    /*for(int i = 0; i < m-1; i++){
        for(int j = 1; j <= n; j++){
            cout << vis[i][j] << " ";
        }
    }*/
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 0; j < m-1; j++){
            if(vis[j][arr[i]] != arr[i-1]){
                flag = false;
                break;
            }
        }
        if(flag) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i];
    cout << ans <<endl;;
    return 0;
}

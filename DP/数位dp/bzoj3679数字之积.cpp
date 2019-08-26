#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
int a[20];

map<ll, ll> dp[20];


ll dfs(int len, ll c, bool limit){
    if(len < 0){
        if(c == -1) c = 0;
        return (c<=n && c>=1);
    }
    if((!limit) && (dp[len].find(c) != dp[len].end())){return dp[len][c];}
    int up = limit? a[len] : 9;
    //cout << up << endl;
    ll ans = 0;
    for(int i = 0; i <= up; i++){
        if(c == -1) {
            if(i == 0) ans += dfs(len - 1, -1, limit && (i == a[len]));
            else ans += dfs(len - 1, i, limit && (i == a[len]));
        }
        else ans += dfs(len-1, i*c, limit&&(i==a[len]));
    }
    //cout << ans << endl;
    if(!limit) dp[len][c] = ans;
    return ans;
}

ll solve(ll n){
    if(n <= 0) return 0;
    int len = 0;
    while(n){
        a[len++] = n%10;
        n/=10;
    }
    //cout << len << endl;
    return dfs(len-1, -1, true);
}

int main(){
    ll l, r;
    cin >> n;
    cin >> l >> r;
    ll ans = solve(r-1)-solve(l-1);
    cout << ans << endl;
    return 0;
}

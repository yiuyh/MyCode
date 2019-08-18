#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100010;
ll a[maxn], sum[maxn];


int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    ll l = 1, r = 1;
    ll ans = 0;
    while(r <= n){
        ll cnt = 0, mpos = (l+r)/2;
        cnt = sum[r]-sum[mpos]+(2*mpos-l-r)*a[mpos]-sum[mpos-1]+sum[l-1];
        if(cnt > k){
            if(l < r) l++;
            else {r++; l++;}
        }else{
            ans = max(ans, (r-l+1));
            r++;
        }
    }
    cout << ans <<endl;
    return 0;
}

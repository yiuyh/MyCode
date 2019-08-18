#include<bits/stdc++.h>

using namespace std;
const int maxn = 310;
int n, k;
int a[maxn], vis[maxn];


int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++) scanf("%d", &a[i]);
    sort(a, a+k);
    int p = 0;
    long long ans = 0;
    for(int i = 0, j = 0; i < n/2 && j < k; i++, j++){
        ans += a[j]*(n-j*2-1);
    }
    cout << ans << endl;
    return 0;
}

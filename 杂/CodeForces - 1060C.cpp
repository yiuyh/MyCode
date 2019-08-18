#include<bits/stdc++.h>

using namespace std;
int a[2010], b[2010];
int asum[2010], bsum[2010];
int ma[2010], mb[2010];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      scanf("%d", &a[i]);
      asum[i] = asum[i-1] + a[i];
    }
    for(int i = 1; i <= m; i++){
      scanf("%d", &b[i]);
      bsum[i] = bsum[i-1] + b[i];
    }
    int k;
    cin >> k;
    for(int i = 1; i <= n; i++){
      for(int j = i; j<= n; i++){
        ma[j-i+1] = min(ma[j-1+i], asum[j] - asum[i-1]);
      }
    }
    for(int i = 1; i <= m; i++){
      for(int j = i; j<= m; i++){
        mb[j-i+1] = min(mb[j-1+i], bsum[j] - bsum[i-1]);
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++){
        if(ma[i] * mb[j] <= x) ans = max(ans, i*j);
      }
    cout << ans << endl;
    return 0;
}

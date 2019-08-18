#include<bits/stdc++.h>

using namespace std;

int a[1024], b[1024];
int dp[1024][1024];

int lowbit(int x){
  return x&(-x);
}


int main(){
  int n, m;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[1<<i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> b[1<<i];
  for(int i = 1; i < (1<<n); i++) a[i] = a[i^(lowbit(i))] + a[lowbit(i)];
  for(int i = 1; i < (1<<m); i++) b[i] = b[i^(lowbit(i))] + b[lowbit(i)];
  for(int i = 1; i < (1<<n); i++){
    for(int j = 1; j < (1<<m); j++){
      for(int k = 0; k < max(n,m); k++){
          if(i&(1<<k)) dp[i][j] = max(dp[i][j], dp[i^(1<<k)][j]);
          if(j&(1<<k)) dp[i][j] = max(dp[i][j], dp[i][j^(1<<k)]);
      }
      if(a[i] == b[j]) dp[i][j]++;
    }
  }
  printf("%d\n", n+m-2*dp[(1<<n)-1][(1<<m)-1]);
  return 0;
}

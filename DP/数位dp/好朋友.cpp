#include <bits/stdc++.h>

long long ans;

long long dp[20][20];
int num[20];

long long dfs(int len, int cnt, int nz, bool limit) {
  if (len <= 0) return 1;
  if (!limit && ~dp[len][cnt] && nz) return dp[len][cnt];
  long long tmp = 0;
  int mx = limit ? num[len] : 9;
  for (int i = 0; i <= mx; ++i) {
    if (nz && cnt > 1 && i == 7) continue;
    tmp += dfs(len - 1, nz ? cnt + (i == 0) : 0, nz || i, limit && i == mx);
  }
  if (!limit && nz) dp[len][cnt] = tmp;
  return tmp;
}

long long solve(long long a) {
  int l = 0;
  while (a) num[++l] = a % 10, a /= 10;
  return dfs(l, 0, 0, 1);
}

int main() {
  int T;
  long long l, r;
  scanf("%d", &T);
  memset(dp, -1, sizeof dp);
  while (T--) {
    scanf("%lld%lld", &l, &r);
    if (r < 1007) continue;
    else ans ^= (r - solve(r) - l + solve(l - 1) + 1);
  }
  printf("%lld\n", ans);
  return 0;
}

#include<iostream>
#include<cstdio>

using namespace std;
const int maxn = 1000010;
int a[maxn];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  for(int i = 0; i < n-1; i++) ans += max(a[i], a[i+1]);
  printf("%lld\n", ans);
  return 0;
}

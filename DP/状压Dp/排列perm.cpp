#include<bits//stdc++.h>

using namespace std;
int a[10];
int dp[(1<<10)+10][1010];
int vis[10];

int main(){
  int t;
  cin >> t;
  while (t--) {
    char ch[15];
    int n;
    memset(dp, 0, sizeof(dp));
    scanf("%s", ch);
    scanf("%d", &n);
    int len = strlen(ch);
    //cout << len << endl;
    for(int i = 0; i < len; i++) a[i] = ch[i] - '0';
    dp[0][0] = 1;
    for(int i = 0; i < (1<<len); i++){
      memset(vis, 0, sizeof(vis));
      for(int j = 0; j < len; j++){
        if(!(i&(1<<j)) && !vis[a[j]]){
          vis[a[j]] = 1;
          for(int k = 0; k < n; k++){
            dp[i|(1<<j)][(k*10+a[j]) % n] += dp[i][k];
          }
        }
      }
    }
    printf("%d\n", dp[(1<<len)-1][0]);
  }
  return 0;
}

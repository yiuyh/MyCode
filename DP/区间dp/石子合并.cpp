#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn = 1010;
int arr[maxn], sum[maxn];
int dp[maxn][maxn];

int main(){
    int n;
    while (cin >> n) {
        for(int i = 1; i <= n; i++) {
          scanf("%d", &arr[i]);
        }
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for(int i = 1; i <= n; i++) dp[i][i] = arr[i];
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n-k+1; i++){
                 for(int j = i; j < i+k; j++){
                    dp[i][i+k-1] = min(dp[i][i+k-1], dp[i][j]+dp[j+1][i+k-1]);
                 }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}

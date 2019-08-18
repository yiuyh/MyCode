#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 110;
int arr[maxn];
int dp[maxn][maxn];

int main(){
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
    for(int l = 2; l < n; l++){
        for(int i = 2; i <= n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = 1000000000;
            for(int k = i; k <= j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[k]*arr[i-1]*arr[j]);
            }
        }
    }
    printf("%d\n", dp[2][n]);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int arr[20],  f[(1<<20)], sum[(1<<20)];
long long dp[(1<<20)];


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < (1<<n); i++){
        dp[i] = 1, f[i] = 0;
        sum[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < (1<<n); j++){
            if(j&(1<<(i-1))) sum[j] += arr[i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < (1<<n); j++){
            if(j&(1<<(i-1)) && sum[j] - arr[i] == arr[i]) f[j]++;
        }
    }
    for(int i = 1; i < (1<<n); i++){
        int k = (1<<n) - 1 - i;
        for(int j = k; ; j=(j-1)&k){
            dp[i|j] += dp[j]*f[i];
            if(j==0) break;
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}

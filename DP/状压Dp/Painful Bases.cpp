//if(!(i&(1<<j))) dp[i|(1<<j)][(k*m+num[i]%m)%m] += dp[i][k];
#include<bits/stdc++.h>

using namespace std;
int const maxn = 20;
int num[maxn];
int dp[20][1<<20];
char ch[20];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m >> ch;
        int len = strlen(ch);
        for(int i = 0; i < len; i++){
            if(ch[i] >= '0' && ch[i] <= '9') num[i] = ch[i] - '0';
            else num[i] = ch[i] - 'A' + 10;
        }
        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j < n; j++){
                if(!(i&(1<<j))){
                    for(int k = 0; k <= m; k++){
                        int tmp = ((k*n)+num[j]%m) % m;
                        dp[i|(1<<j)][tmp] += dp[i][k];
                    }
                }
            }
        }
    }
    return 0;
}

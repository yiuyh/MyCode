//2019南京icpc C题
#include<bits/stdc++.h>

using namespace std;
int n, m;
struct node{
    int x, y;
    node(int _x, int _y){
        x = _x; y = _y;
    }
};
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
vector<node> v[1000010];
int Map[1010][1010];
const long long mod = 1000000007LL;
long long dp[1010][1010][5];
int a[1000010];
int cnt = 1;
map<int, int> ma;

void init(){
    sort(a, a+(n*m));
    for(int i = 0; i < (n*m); i++){
        if(!ma[a[i]]) ma[a[i]] = cnt++;
    }
}

bool judge(int x, int y){
    if(x <= 0 || x > n || y <= 0 || y > m) return false;
    else return true;
}

int main(){
    cin >> n >> m;
    int _max = 0;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &Map[i][j]);
            a[tmp++] = Map[i][j];
        }
    }
    init();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int p = ma[Map[i][j]];
            v[p].push_back(node(i, j));
        }
    }
    long long ans = 0;
    for(int i = 1; i < cnt; i++){
        int nm;
        for(int j = 0; j < v[i].size(); j++){
            int x = v[i][j].x, y = v[i][j].y;
            nm = Map[x][y];
            int ff = 0;
            for(int k = 0; k < 4; k++){
                int xx = x+dir_x[k], yy = y+dir_y[k];
                if(!judge(x,y)) continue;
                int num = Map[xx][yy];
                if(num == nm+1){
                    ff++;
                }
                if(num == nm-1){
                    for(int l = 2; l <= 4; l++){
                        dp[x][y][l] += dp[xx][yy][l-1];
                    }
                    dp[x][y][4] += dp[xx][yy][4];
                }
            }
            long long fff = 0;
            for(int l = 2; l <= 4; l++){
                fff += dp[x][y][l];
                dp[x][y][l] %= mod;
            }
            if(fff == 0) dp[x][y][1] = 1;
            if(ff == 0) ans = (ans+dp[x][y][4])%mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

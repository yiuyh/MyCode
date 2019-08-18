#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn], y[maxn], cnt[maxn];
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t, ca = 1, n, k, w, tx;
    cin >> t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> w >> k;
        for(int i = 0; i < n; i++)
            cin >> tx >> y[i];
        sort(y, y+n, cmp);
        for(int i = 0; i < n; i++)
        {
            int temp = 0;
            for(int j = i; j >= 0; j--)
            {
                if(y[j]-y[i] <= w)
                    temp++;
            }
            cnt[i] = temp;
        }
        for(int j = 1; j <= k; j++)
            for(int i = 0; i < n; i++)
        {
            if(i >= cnt[i])
                dp[i][j] = max(dp[i-1][j], dp[i-cnt[i]][j-1] + cnt[i]);
            else
                dp[i][j] = cnt[i];
        }
        printf("Case %d: %d\n", ca++, dp[n-1][k]);
    }
    return 0;
}

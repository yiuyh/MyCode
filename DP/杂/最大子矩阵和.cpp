#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long num[401][401];
long long presum[401][401];
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int N, M;
    long long sum, ans;
    cin >> N >> M;
    ans = -1000000001;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> num[i][j];
            ans = max(ans, num[i][j]);
        }
    }
    if (ans <= 0) {
        cout << ans << endl;
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                presum[i][j] = presum[i - 1][j] + num[i][j];
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                sum = 0;
                for (int k = 1; k <= M; k++) {
                    if (sum + presum[j][k] - presum[i - 1][k] < 0) {
                        sum = 0;
                    } else {
                        sum += presum[j][k] - presum[i - 1][k];
                    }
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

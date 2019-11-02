#include<bits/stdc++.h>

using namespace std;
int t, n, x;
int z[50010];//z[i]当能和前i-1块中的某一块符合， 则-1。
//若与i+1到n中的某一块符合， 则+1。
//所以Σ(j = 0, i)z[i] 表示在第i块之后放上阻挡物会使得多少对不成立

int main(){
    cin >> t;
    int T = 1;
    while(t--){
        stack<pair<int, int> >s;
        scanf("%d", &n);
        memset(z, 0, sizeof(z));
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            while(s.size() > 0 && x >= s.top().first){
                z[s.top().second]++;
                z[i]--;
                s.pop();
            }
            if(s.size() > 0){
                z[s.top().second]++;
                z[i]--;
            }
            s.push(make_pair(x, i));
        }
        int p = 0;
        for(int i = 1; i <= n; i++){
            z[i] += z[i-1];
            if(z[p] < z[i]) p = i;
        }
        printf("Case #%d: %d %d\n", T++, p+1, z[p]);
    }
    return 0;
}

// http://codeforces.com/contest/989/problem/D


#include<bits/stdc++.h>

using namespace std;
const int maxn = 100010;
int n, L, W;
int a[maxn], b[maxn];
int t1, t2;
long long ans = 0LL;

int main(){
    int x, y;
    scanf("%d%d%d", &n, &L, &W);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        if(y == 1) a[++t1] = x;
        else b[++t2] = x;
    }
    sort(a+1, a+t1+1);
    sort(b+1, b+t2+1);
    //cout << t1 << " " << t2 << endl;;
    for(int i = 1, j = 1; i <= t1; i++){
        while(j <= t2 && abs(a[i]+b[j]+L)>=1LL*W*(b[j]-a[i]+L)) j++;
        ans +=(t2-j+1);
        //cout << b[j] << endl;

    }
    printf("%lld\n", ans);
    return 0;
}

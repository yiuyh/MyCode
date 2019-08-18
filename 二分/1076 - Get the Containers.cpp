#include<bits/stdc++.h>

using namespace std;
int a[1010];
int n, k, maxa, sum;
bool judge(int x){
    int ct = 0, s = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > x) return false;
        if(s+a[i] > x){
            ct++;
            s = 0;
        }
        s += a[i];
    }
    return k > ct;
}

int main(){
    int t, tcase = 1;
    cin >> t;
    while(t--){
        maxa = 0, sum = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            maxa = max(maxa, a[i]);
            sum += a[i];
        }
        int l = maxa, r = sum;
        while(l < r){
            int mid = (l+r)/2;
            if(judge(mid)) r = mid;
            else l = mid+1;
        }
        printf("Case %d: %d\n", tcase++, l);
    }
    return 0;
}

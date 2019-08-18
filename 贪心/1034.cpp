#include<bits/stdc++.h>

using namespace std;
const int maxn = 100010;
int n;
int a[maxn], b[maxn];

int solve(int a[], int b[]){
    int ans = 0;
    int l1, l2, r1, r2;
    l1 = l2 = 1, r1 = r2 = n;
    while(l1 <= r1 && l2 <= r2){
        if(a[l1] > b[l2]) {ans += 2; l1++, l2++;}
        else if(a[r1] > b[r2]) {ans += 2; r1--, r2--;}
        else{
            if(a[l1] == b[r2]) ans++;
                l1++, r2--;
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    printf("%d %d\n", solve(a, b), 2*n - solve(b, a));

    return 0;
}

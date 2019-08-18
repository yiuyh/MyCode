#include<bits/stdc++.h>

using namespace std;
const int maxn = 3000010;
int arr[maxn];
int q1[maxn], q2[maxn], h1 = 0, h2 = 0, t1 = 0, t2 = 0, ind = -1;
int ans = 0;

int main(){
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        while(h1 <= t1 && arr[i] <= arr[q1[t1]]) t1--;
        while(h2 <= t2 && arr[i] >= arr[q2[t2]]) t2--;
        q1[++t1] = q2[++t2] = i;
        while(arr[q2[h2]] - arr[q1[h1]] > k){
            if(q2[h2] > q1[h1]){
               ind = q1[h1]; h1++;
            }else{
               ind = q2[h2]; h2++;
            }
        }
        ans = max(ans, i-ind);
    }
    cout << ind << endl;
    cout << ans << endl;
    return 0;
}
/*
3 9
4 3 2 2 2 1 2 2 2
*/

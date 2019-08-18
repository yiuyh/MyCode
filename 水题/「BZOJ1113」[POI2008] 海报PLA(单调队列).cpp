#include<bits/stdc++.h>

using namespace std;
const int maxn = 250010;

int arr[maxn];
int q[maxn], head = 0, tail = 0;

int main(){
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d%d", &num, &arr[i]);
    }
    q[++tail] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > q[tail]){
            ans++;
            q[++tail] = arr[i];
        }else if(arr[i] < q[tail]){
            while(arr[i] < q[tail] && tail != head) tail--;
            if(arr[i] != q[tail]){
                ans++;
                q[++tail] = arr[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
﻿

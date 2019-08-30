//对任意数字加一或者减一  使得序列不递减
#include<bits/stdc++.h>

using namespace std;
priority_queue<int> q;


int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(q.empty() || a >= q.top()) q.push(a);
        else ans += q.top()-a, q.pop(), q.push(a), q.push(a);
    }
    cout << ans << endl;
    return 0;
}
//对任意数字加一或者减一  使得序列不递增 867E
#include<bits/stdc++.h>

using namespace std;
priority_queue<int> q;
int b[300010];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    long long ans = 0;
    for(int i = n-1; i >= 0; i--){
        int a = b[i];
        if(q.empty() || a >= q.top()) q.push(a);
        else ans += q.top()-a, q.pop(), q.push(a), q.push(a);
    }
    cout << ans << endl;
    return 0;
}

// https://ac.nowcoder.com/acm/problem/14269

#include<bits/stdc++.h>
#define lson rt<<1
#define rson (rt<<1)|1
#define Lson l, m, lson
#define Rson m+1, r, rson
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int tree[maxn<<2][35];
long long rec[35];
const ll mod = (1e9+7);

ll pow(ll x, ll n){
    ll res = 1;
    while(n){
        if(n%2){
            res = res*x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        n >>= 1;
    }
    return res;
}

void pushup(int rt){
    for(int i = 0; i < 32; i++){
        tree[rt][i] = tree[lson][i]+tree[rson][i];
    }
}

void build(int l, int r, int rt){
    if(l == r){
        int num;
        scanf("%d", &num);
        for(int i = 0; i < 32; i++){
            if(num & (1<<i)) tree[rt][i] = 1;
            else tree[rt][i] = 0;
        }
        return;
    }
    int m = (l+r)>>1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void update(int p, int num, int l, int r, int rt){
    if(l == r){
        for(int i = 0; i < 32; i++){
            if(num & (1<<i)) tree[rt][i] = 1;
            else tree[rt][i] = 0;
        }
        return;
    }
    int m = (l+r)>>1;
    if(p<=m) update(p, num, Lson);
    else update(p, num, Rson);
    pushup(rt);
}

void query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        for(int i = 0; i < 32; i++) rec[i] += tree[rt][i];
        return;
    }
    int m = (l+r)>>1;
    if(L<=m) query(L, R, Lson);
    if(m<R) query(L, R, Rson);
}

int main(){
    int n;
    cin >> n;
    build(1, n, 1);
    int q;
    cin >> q;
    while(q--){
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if(op == 1) update(a, b, 1, n, 1);
        else{
            memset(rec, 0, sizeof(rec));
            query(a, b, 1, n, 1);
            ll ans = 0;
            //cout << "xxx" <<endl;
            for(int i = 0; i < 32; i++){
                if(rec[i]) ans = ans+(((pow(2LL, rec[i])+mod-1)%mod)*((1<<i)%mod))%mod;
                ans %= mod;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}


/*

链接：https://ac.nowcoder.com/acm/problem/14269
来源：牛客网

考虑维护一个这样的问题：
（1） 给出一个数组A，标号为1~n
（2） 修改数组中的一个位置。
（3） 询问区间[l,r]中所有子集的位运算and之和mod(109+7)。
位运算and即为“pascal中的and”和“C/C++中的&”
我们定义集合S={ l , l+1 , ... , r-1 , r}
若集合T，T ∩ S = T，则称T为S的子集
设f（T）=AT1 and AT2 and ... and ATk  (设k为T集大小，若k=0则f(T)=0)
所有子集的位运算and之和即为∑f(T)
那么，现在问题来了。
输入描述:
第一行，一个正整数N
第二行，N个非负整数，为数组A
第三行，一个正整数M，为操作次数
接下来M行格式如下
修改操作： 1 x y，将Ax修改为y
询问操作： 2 l r，区间[l,r]中所有子集的位运算and之和 mod(109+7)
*/

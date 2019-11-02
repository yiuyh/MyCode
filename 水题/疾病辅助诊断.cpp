#include<iostream>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define lson (x<<1)
#define rson ((x<<1)+1)

using namespace std;
int tree[(1<<10)<<4];
bitset<1010> b[2][15], ans, tmp;//（每个b[x][y]表示一个有1010位的二进制串,ans,tmp都是是一个长度为1010的二进制串）b[0][1]记录指标为H的  b[1][0]记录指标为L的  ans记录第k个人结果是Y还是N
int n, m;
void built(int x, bitset<1010> ind){
    int i = log2(x)+1;
    if(i > m) return;
    bitset<1010> b1 = ind & b[0][i];
    int cnt1 = b1.count();
    if(cnt1){
        bitset<1010> tmp1 = b1 & ans;
        if(tmp1.count() == 0) tree[lson] = 0;
        else if(tmp1.count() == cnt1) tree[lson] = 1;
        else{
            tree[lson] = 2;
            built(lson, b1);
        }
    }

    bitset<1010> b2 = ind & b[1][i];
    int cnt2 = b2.count();
    if(cnt2){
        bitset<1010> tmp2 = b2 & ans;
        if(tmp2.count() == 0) tree[rson] = 0;
        else if(tmp2.count() == cnt2) tree[rson] = 1;
        else{
            tree[rson] = 2;
            built(rson, b2);
        }
    }
}

void dfs(int x, string str){
    if(tree[x] == -1) return;
    if(tree[x] == 0) {cout << str << "N;"; return;}
    else if(tree[x] == 1) {cout << str << "Y;"; return;}
    else if(tree[x] == 2){
        if(tree[lson] != -1) dfs(lson, str+'H');
        if(tree[rson] != -1) dfs(rson, str+'L');
    }
}

int main(){
    for(int i = 0; i < 1010; i++) tmp[i] = 1;
    while(~scanf("%d%d", &n, &m)){
        if(n==0 && m == 0) break;
        memset(tree, -1, sizeof(tree));
        char c;
        for(int i = 0; i < n; i++){
            int num;
            scanf("%d ", &num);
            for(int j = 1; j <= m; j++){
                scanf("%c ", &c);
                if(c == 'H') b[0][j].set(i);
                else if(c == 'L') b[1][j].set(i);
            }
            scanf("%c", &c);
            if(c == 'Y') ans.set(i);
        }
        tree[1] = 2;
        built(1, tmp);
        dfs(1, "");
        cout << endl;
        ans.reset();
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= 11; j++) b[i][j].reset();
    }
    return 0;
}

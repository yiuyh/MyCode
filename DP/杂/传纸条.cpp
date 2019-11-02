#include <iostream>
#define maxn 55
using namespace std;
int f[maxn][maxn][maxn][maxn],a[maxn][maxn];
int n,m;
int max_ele(int a,int b,int c,int d){
    if (b>a)
        a = b;
    if (c>a)
        a = c;
    if (d>a)
        a = d;
    return a;
}
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
                cin >> a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                for (int l=j+1;l<=m;l++)
                    f[i][j][k][l]=max_ele(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+a[i][j]+a[k][l];
    cout << f[n][m-1][n-1][m] << endl;
    return 0;
}

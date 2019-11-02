#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100010;
char Ma[maxn*2];
int Mp[maxn*2];
int ll[maxn*2], rr[maxn*2];

void Manacher(char s[], int len){
    int l = 0;
    Ma[l++] = '$', Ma[l++] = '#';
    for(int i = 0; i < len; i++){
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i < l; i++){
        Mp[i] = mx>i? min(Mp[2*id-i], mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx){
            mx = i+Mp[i];
            id = i;
        }
        ll[i+Mp[i]-1] = max(ll[i+Mp[i]-1], Mp[i]-1);
        rr[i-Mp[i]+1] = max(rr[i-Mp[i]+1], Mp[i]-1);
    }
}
char s[maxn];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    Manacher(s, len);
    int ans = 0;
    for(int i = 1; i < 2*len+2; i+= 2) rr[i] = max(rr[i], rr[i-2]-2);
    for(int i = 2*len+2-1; i >= 1; i-= 2) ll[i] = max(ll[i], ll[i+2]-2);
    for(int i = 1; i <= 2*len+2; i+=2) if(rr[i]&&ll[i]) ans = max(ans, ll[i]+rr[i]);
    cout << ans << endl;
    return 0;
}

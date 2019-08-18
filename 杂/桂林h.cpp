#include<bits/stdc++.h>

using namespace std;
const int maxn = 10010;
char a[maxn], b[maxn];

int main(){
    int t, tcase = 1;
    cin >> t;
    while(t--){
        scanf("%s%s", a, b);
        int len = strlen(a);
        char c[maxn];
        memset(c, 'a', len);
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(a[i] == b[i]) continue;
            if(a[i] == 'a') cnt++;
            if(b[i] == 'a') cnt--;
        }
        int num = cnt, pos;
        if(cnt > 0){
            for(int i = len-1; i >= 0; i--){
                if(b[i] != 'a'){
                    if(a[i] == 'a') num -= 2;
                    else num--;
                }
                if(num <= 0) {pos = i; break;}
            }
            if(num == -1) {num++;}
            for(int i = pos; i < len && num < cnt; i++){
                if(b[i] != 'a'){
                    if(a[i] == 'a'){
                        if(cnt-num == 1){
                            if(b[i] == 'b') c[i] = 'c';
                            else c[i] = 'b';
                            num++;
                        }else {c[i] = b[i]; num+=2;}
                    }else{
                        c[i] = b[i];
                        num++;
                    }
                }
            }
        }else if(cnt < 0){
            for(int i = len-1; i >= 0; i--){
                if(a[i] != 'a'){
                    if(b[i] == 'a') num += 2;
                    else num++;
                }
                if(num >= 0) {pos = i; break;}
            }
            if(num == 1) {num--;}
            for(int i = pos; i < len && num > cnt; i++){
                if(a[i] != 'a'){
                    if(b[i] == 'a'){
                        if(num - cnt == 1){
                            if(a[i] == 'b') c[i] = 'c';
                            else c[i] = 'b';
                            num--;
                        }else {c[i] = a[i]; num-=2;}
                    }else{
                        c[i] = a[i];
                        num--;
                    }
                }
            }
    }
        for(int i = 0; i < len; i++) printf("%c", c[i]);
        printf("\n");
    }
    return 0;
}

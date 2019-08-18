//正解

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=1e9;
struct Node{
	int fail,ch[26],val;
	void clear(){
		fail=val=0;
		memset(ch,0,sizeof(ch));
	}
}tr[605];
int sz;
int bin[20],n;
void insert(char *s,int val){
	int u=0,len=strlen(s);
	for(int i=0;i<len;i++){
		int c=s[i]-'A';
		if(!tr[u].ch[c]){
			tr[u].ch[c]=++sz;
			tr[sz].clear();
		}
		u=tr[u].ch[c];
	}
	tr[u].val|=bin[val];
}
void build(){
	queue<int>q;q.push(0);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(tr[u].ch[i]){
				int v=tr[u].ch[i];
				if(u)tr[v].fail=tr[tr[u].fail].ch[i];
				q.push(v);
			}else tr[u].ch[i]=tr[tr[u].fail].ch[i];
		}
	}
}
int fromu[605][4100],froms[605][4100];
bool vis[605][4100];
void print(int u,int s){
	if(!u)return;
	print(fromu[u][s],froms[u][s]);
	for(int i=0;i<26;i++){
		int v=tr[fromu[u][s]].ch[i],t=froms[u][s];
		for(int p=v;p;p=tr[p].fail)
		t|=tr[p].val;
		if(v==u&&t==s){
			putchar('A'+i);
			break;
		}
	}
}
void bfs(){
	queue<int>q1,q2;
	q1.push(0);q2.push(0);
	vis[0][0]=1;
	while(!q1.empty()){
		int u=q1.front(),s=q2.front();q1.pop();q2.pop();
		for(int i=0;i<26;i++){
			int v=tr[u].ch[i],t=s;
			for(int p=v;p;p=tr[p].fail)
			t|=tr[p].val;
			if(!vis[v][t]){
				vis[v][t]=1;
				q1.push(v);q2.push(t);
				fromu[v][t]=u;
				froms[v][t]=s;
				if(t==bin[n+1]-1){
					print(v,t);
					return;
				}
			}
		}
	}
}
char s[55];
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);
	tr[sz=0].clear();
	bin[1]=1;
	for(int i=2;i<20;i++)bin[i]=bin[i-1]<<1;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		insert(s,i);
	}
	build();
	bfs();
	return 0;
}



#include<iostream>

using namespace std;
string str[15];
string dp[1<<12];

string con(string str1, string str2){
    if(str1.find(str2) != string::npos) return str1;
    if(str2.find(str1) != string::npos) return str2;
    int len1 = str1.length(), len2 = str2.length();
    int maxl1 = 0;
    string tmp1 = "";
    for(int i = 0; i < len1; i++){
       int j;
       for(j = 0; j < len2 && i+j < len1; j++){
          if(str1[j+i] != str2[j]) break;
       }
       //cout << j << " ";
       if(j+i == len1) {maxl1 = max(maxl1, j); break;}
    }
    //cout << maxl1 << " " << str1 << " " << str2 << " ";
    tmp1 = str1+str2.substr(maxl1);
    //cout << tmp1 << endl;
    maxl1 = len1 + len2 - maxl1;
    return tmp1;
    /*int maxl2 = 0;
    string tmp2;
    for(int i = 0; i < len2; i++){
       int j;
       for(j = 0; j < len1 && i+j < len2; j++){
          if(str2[j+i] != str1[j]) break;
       }
       if(j+i == len2) {maxl2 = max(maxl2, j); break;}
    }
    tmp2 = str2+str1.substr(maxl2);
    maxl2 = len1 + len2 - maxl2;
    if(maxl1 < maxl2) return tmp1;
    else if(maxl1 > maxl2) return tmp2;
    else{
      if(tmp1 > tmp2) return tmp2;
      else return tmp1;
    }*/
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> str[i];
  for(int i = 0; i < 1<<n; i++) dp[i] = "";
  for(int i = 0; i < (1<<n); i++){
    for(int j = 0; j < n; j++){
      //if(i == 0) {dp[i|(1<<j)] = str[j];continue;}
      if(!(i&(1<<j))){
          int len1 = dp[i|(1<<j)].length();
          //cout << i << " ";
          string tmp = con(dp[i], str[j]);
          if(len1 == 0) dp[i|(1<<j)] = tmp;
          else{
              int len2 = tmp.length();
              if((len2 < len1) || (len2 == len1 && dp[i|(1<<j)] > tmp)) dp[i|(1<<j)] = tmp;
          }
      }
    }
  }
  //for(int i = 0; i < (1<<n); i++) cout << dp[i] << endl;
  cout << dp[(1<<n)-1] << endl;
  return 0;
}

/*2
qwer
wert
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#define ll long long
using namespace std;
const int maxn=(1<<20)+5;
ll dp1[maxn],dp2[maxn];
int cnt[maxn],a[21];


int main() {
	int t,n;
	scanf("%d",&t);
	for(int i=0; i<(1<<20); i++)cnt[i]=cnt[i>>1]+(i&1);
	while(t--) {
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		scanf("%d",&n);
		for(int i=0; i<n; i++)scanf("%d",&a[i]);
		int w=(1<<n)-1;
		dp1[0]=1,dp2[0]=1;
		for(int i=1; i<=w; i++)
			for(int j=0; j<n; j++)
				if(i>>j&1) {
					if(a[j]!=cnt[i])dp1[i]+=dp1[i^(1<<j)];
					if(n-a[j]+1!=cnt[i])dp2[i]+=dp2[i^(1<<j)];
				}
		ll ans=0;
		for(int i=1; i<=w; i++) {
			ll sum=0,ct=0;
			for(int j=0; j<n; j++) {
				if(!(i>>j&1))sum+=j,ct++;
				else ans+=(ct*j-sum)*dp1[i]*dp2[i^w];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

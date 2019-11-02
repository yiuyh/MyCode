/*
现在有n个人，从1标号到n。同时有一些奇怪的约束条件，每个都形如：a必须在b之前。
同时，社会是不平等的，这些人有的穷有的富。1号最富，2号第二富，以此类推。有钱人就贿赂负责人，所以他们有一些好处。
负责人现在可以安排大家排队的顺序，由于收了好处，所以他要让1号尽量靠前，如果此时还有多种情况，就再让2号尽量靠前，如果还有多种情况，就让3号尽量靠前，以此类推。
那么你就要安排大家的顺序。我们保证一定有解。
*/

#include<bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, less<int> > q;
vector<int> edge[30010];
int in[30010];
int ans[30010];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            in[a]++;
            edge[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(!in[i]) q.push(i);
        }
        for(int i = 1; i <= n; i++){
            int now = q.top();
            q.pop();
            ans[i] = now;
            for(int i = 0; i < edge[now].size(); i++){
                int next = edge[now][i];
                in[next]--;
                if(in[next] == 0) q.push(next);
            }
        }
        for(int i = n; i >= 1; i--){
            if(i == 1) printf("%d", ans[i]);
            else printf("%d ", ans[i]);
        }
        printf("\n");
        for(int i = 1; i <= n; i++) edge[i].clear();
    }
    return 0;
}

//例题：洛谷 P3387 【模板】缩点
//缩点，求所点后的最大联通路径
const int N=1e6+5;
int n,m,k,ans;
int a[N];
int tot=0;
vector<int> e[N];
int dfn[N],low[N],ins[N], belong[N];
stack<int> sta;
vector<int> suo;
int is[N];
void tarjan(int t)
{
    dfn[t]=low[t]=++tot;
    ins[t]=1;sta.push(t);
    for(int i:e[t]){
        if(!dfn[i]){
            tarjan(i);
            low[t]=min(low[i],low[t]);
        }
        else if(ins[i]){
            low[t]=min(low[t],dfn[i]);
        }
    }
    if(low[t]==dfn[t]){
        while(1){
            int x = sta.top(); sta.pop();
            ins[x] = 0;
            belong[x] = t;  // 记录所属SCC的根节点
            if(x == t) break;
            a[t] += a[x];   // 累加权值到根节点
        }
        suo.push_back(t);
        is[t] = 1;
    }
}
vector<int> to[N];
int in[N], dp[N];

void solve()
{
    queue<int> q;
    for(int x : suo){
        if(in[x] == 0){
            q.push(x);
            dp[x] = a[x];
        }
    }
    int ans=0;
    while(!q.empty()){
        int t = q.front(); q.pop();
        ans = max(ans, dp[t]);
        for(int i : to[t]){
            if(dp[i] < dp[t] + a[i]){
                dp[i] = dp[t] + a[i];
            }
            if(--in[i] == 0){
                q.push(i);
            }
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;  
    for(int i=1;i<=n;i++) cin>>a[i];
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    // 构建新图，处理所有原边
    set<pair<int, int>> edges;
    for(int u=1; u<=n; u++){
        for(int v : e[u]){
            int ru = belong[u], rv = belong[v];
            if(ru != rv && edges.find({ru, rv}) == edges.end()){
                to[ru].push_back(rv);
                in[rv]++;
                edges.insert({ru, rv});
            }
        }
    }
    solve();
    return 0;
}

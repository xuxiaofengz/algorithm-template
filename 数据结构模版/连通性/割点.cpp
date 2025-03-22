//例题:洛谷 P3387 【模板】缩点
// 统计无向图的所有割点
const int N=1e6+5;
int n,m,k;
int a[N];
int tot=0;
vector<int> e[N];
int dfn[N],low[N],ins[N];
vector<int> res;
int root;
void tarjan(int t)
{
	dfn[t]=low[t]=++tot;
	int son=0;//特判根节点
	for(int i:e[t]){
		if(!dfn[i]){
			son++;
			tarjan(i);
			low[t]=min(low[i],low[t]);
			if(low[i]>=dfn[t]&&t!=root)res.push_back(t);
		}
		else{
			low[t]=min(low[t],dfn[i]);
		}
	}
	if(t==root&&son>1)res.push_back(t);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;	
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(i);
		}
	}
	sort(res.begin(),res.end());
	int len=unique(res.begin(),res.end())-res.begin();
	cout<<len<<"\n";
	for(int i=0;i<len;i++){
		cout<<res[i]<<" ";
	}
	
	return 0;
}


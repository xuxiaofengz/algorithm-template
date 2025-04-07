//例题：洛谷：P7771 【模板】欧拉路径
//欧拉回路和通路（有向图）-（可扩展为无向图）
//欧拉路径：
          无向图:不存在或者仅存在两个点度为奇数并且必须以他们为起点
          有向图:不存在或者仅存在一对（一个出度比入度大1，一个比入度比初度大1）,其他初度和入度相等
          
const int N=1e5+5;
int n,m;
vector<int> e[N];
int del[N];//维护某一个节点的邻接表中哪些边已经被访问过（有向图）,对于无向图可以考虑用map维护
int in[N];
stack<int> res;
int cnt=0;

//hierholzer
void dfs(int cur){
	for(int i=del[cur];i<e[cur].size();i=del[cur]){
		del[cur]=i+1;
		dfs(e[cur][i]);
	}
	res.push(cur);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		e[u].push_back(v);
		in[u]--;
		in[v]++;
	}
	int numchu=0,numin=0,s=1;
	for(int i=n;i>=1;i--){
		if(in[i]<-1||in[i]>1){
			cout<<"No";return 0;
		}
		if(in[i]<0){
			numchu++;
			s=i;
		}
		if(in[i]>0){
			numin++;
		}
		//sort(e[i].begin(),e[i].end());
	}
//判断是否存在欧拉回路（有向图）
	if(numin!=numchu||numin>1||numchu>1){
		cout<<"No";return 0;
	}
	dfs(s);
	while(!res.empty()){
		cout<<res.top()<<" ";
		res.pop();
	}
	
	return 0;
}


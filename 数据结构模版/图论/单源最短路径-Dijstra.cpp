//例题：洛谷 P4779 【模板】单源最短路径（标准版）
typedef long long ll;
#define pii pair<ll,ll>
int n,m,k,s;
vector<pii> e[N];//存储有向边
ll res[N];
int vis[N];//记录某一点到源点的最短距离是否已经确定

void djis()
{
	priority_queue<pii,vector<pii>,greater<pii>> que;
	vis[s]=1;
	res[s]=0;
	for(int i=0;i<e[s].size();i++){
		que.push(e[s][i]);
	}
	while(!que.empty()){
		auto cur=que.top();que.pop();
		ll w=cur.first,v=cur.second;
		if(vis[v])continue;//性能的关键(倘若某点已经确定，说明其已经扩展过，不需要再重复)
		res[v]=min(res[v],w);vis[v]=1;
//		cout<<v<<" "<<w<<endl;
		for(int i=0;i<e[v].size();i++){
			if(vis[e[v][i].second])continue;
			que.push({w+e[v][i].first,e[v][i].second});
		}
	}
}

例题：P5960 【模板】差分约束
注意：将n+1,作为超级源点，避免图不连通的情况（具体为建立一条n+1到所有的点的边，权值均为0）

int dis[N];
int vis[N],cnt[N];

vector<pair<int,int>> e[N];
void spfa()
{
	fill(dis,dis+N,1000000000);
	queue<int> q;
	q.push(n+1);
	vis[n+1]=1;
	dis[n+1]=0;
	
	while(!q.empty()){
		int t=q.front();q.pop();
		vis[t]=0;
		for(auto i:e[t]){
			int len=dis[t]+i.second;
			if(len<dis[i.first]){
				dis[i.first]=len;
				cnt[i.first]=cnt[t]+1;
				if(cnt[i.first]>n){//存在负环
					cout<<"NO"<<endl;
					return;
				}
				if(!vis[i.first]){
					q.push(i.first);
					vis[i.first]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){//输出可能的解
		cout<<dis[i]<<" ";
	}
}

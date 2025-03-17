//例题：P1144 最短路计数
//说明：统计起点1到其他所有点的最短路的条数（存在自环和重边均能考虑），spfa

int dis[N];
int vis[N],cnt[N];

vector<int> e[N];
void spfa()
{
	fill(dis,dis+N,1000000000);
	queue<int> q;
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	cnt[1]=1;
	
	while(!q.empty()){
		int t=q.front();q.pop();
		vis[t]=0;
		for(int i:e[t]){
			int len=dis[t]+1;
			if(len<=dis[i]){
				if(len==dis[i])
					cnt[i]+=cnt[t];
				else cnt[i]=cnt[t];
				cnt[i]%=mod;
				dis[i]=len;
				if(!vis[i]){
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<"\n";
	}
}

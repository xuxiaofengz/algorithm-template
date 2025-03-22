// 洛谷：P4782 【模板】2-SAT

#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
int n,m;
int tot=0;
vector<int> e[N];
int low[N],dfn[N],ins[N];
int bel[N];
stack<int> sta;
int tt=0;

void tarjan(int t)
{
//	cout<<t<<endl;
	low[t]=dfn[t]=++tot;
	sta.push(t);ins[t]=1;
	for(int i:e[t]){
		if(!dfn[i]){
			tarjan(i);
			low[t]=min(low[t],low[i]);
		}
		else if(ins[i])low[t]=min(low[t],dfn[i]);
	}
	if(dfn[t]==low[t]){
		++tt;
		while(true&&!sta.empty()){
			int x=sta.top();sta.pop();
			ins[x]=0;bel[x]=tt;
			if(x==t)break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	int x,a,y,b;
	for(int i=1;i<=m;i++){
		cin>>x>>a>>y>>b;
		e[x+(!a)*n].push_back(y+b*n);
		e[y+(!b)*n].push_back(x+a*n);
	}
	for(int i=1;i<=2*n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(bel[i]==bel[i+n]&&bel[i]!=0){
			cout<<"IMPOSSIBLE";return 0;
		}
	}
	cout<<"POSSIBLE"<<"\n";
	for(int i=1;i<=n;i++){
		if(bel[i]>bel[i+n])cout<<"1 ";
		else cout<<"0 ";
	}
	return 0;
}

//例题：洛谷：P3379 【模板】最近公共祖先（LCA）
//倍增
vector<int> e[N];
int dep[N];
int fa[N][20];

void dfs(int cur,int f){
	dep[cur]=dep[f]+1;
	fa[cur][0]=f;
	for(int i=1;i<20;i++){
		fa[cur][i]=fa[fa[cur][i-1]][i-1];
	}
	for(auto i:e[cur]){
		if(i==f)continue;
		dfs(i,cur);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

//例题：洛谷 P3834 【模板】可持久化线段树 2
//维护区间的第k小的数

#include<bits/stdc++.h>
#define lc(x) tr[x].lc
#define rc(x) tr[x].rc

using namespace std;

const int N=2e5+5;
int n,m;
int a[N],root[N];//root存放所有的根节点
int ind=0;
//树中的节点
struct node{
	int lc,rc;
	int s;
}tr[N*33];

//建树
void build(int &x,int l,int r)
{
	x=++ind;
	if(l==r)return;
	int mid=l+(r-l)/2;
	build(lc(x),l,mid);
	build(rc(x),mid+1,r);
}

//动态开点
void add(int x,int &y,int l,int r,int v)
{
	y=++ind;tr[y]=tr[x];tr[y].s++;
	if(l==r)return;
	int mid=l+(r-l)/2;
	if(v<=mid)add(lc(x),lc(y),l,mid,v);
	else add(rc(x),rc(y),mid+1,r,v);
}

//查询区间了[l,r]中的第K小的值，这里因为离散化了，所以返回的是对应的Id
int query(int x,int y,int l,int r,int k)
{
	if(l==r)return l;
	int mid=l+(r-l)/2;
	int s=tr[lc(y)].s-tr[lc(x)].s;
	if(k<=s)return query(lc(x),lc(y),l,mid,k);
	else return query(rc(x),rc(y),mid+1,r,k-s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	vector<int> vec(n,0);
	root[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec[i-1]=a[i];
	}

  //离散化
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	//建树，有时可省略
	build(root[0],1,vec.size());
	for(int i=1;i<=n;i++){
		int id=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin()+1;
		add(root[i-1],root[i],1,vec.size(),id);
	}
	int l,r,k;
	while(m--){
		cin>>l>>r>>k;
		int id=query(root[l-1],root[r],1,vec.size(),k);
		cout<<vec[id-1]<<"\n";//因为离散化后的下标是从0开始，主席树维护的是从1开始的，所以这了减一
	}

	return 0;	
}

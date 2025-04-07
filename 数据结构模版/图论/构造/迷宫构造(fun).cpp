//根据路径回忆，构造迷宫
//题：第十三届蓝桥杯大赛软件赛省赛Java 大学 B 组 回忆迷宫

/*
15
RRRRDDDDDDRRRRDDDDDDRRRRRDDDD
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<iomanip>
#include<array>/*use array must include*/

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

const int N=101;
int n,m,k;
int a[4];//0:x-min,1:y-min,2:x-max,3:y-max;
string s;

bool judge(vector<vector<char>>mp,int x,int y)
{
	if(mp[x-1][y]==' ')return false;
	if(mp[x][y-1]==' ')return false;
	if(mp[x+1][y]==' ')return false;
	if(mp[x][y+1]==' ')return false;
	return true;
}

void solve()
{
	vector<pair<int,int>> vec;
	int x=0,y=0;
	vec.push_back({x,y});
	for(int i=0;i<s.size();i++){
		if(s[i]=='L'){
			y--;
			vec.push_back({x,y});
			a[1]=min(a[1],y);
		}
		else if(s[i]=='R'){
			y++;
			vec.push_back({x,y});
			a[3]=max(a[3],y);
		}
		else if(s[i]=='U'){
			x--;
			vec.push_back({x,y});
			a[0]=min(a[0],x);
		}
		else{
			x++;
			vec.push_back({x,y});
			a[2]=max(a[2],x);
		}
	}
	x=a[2]-a[0]+3;
	y=a[3]-a[1]+3;
	int px=2-a[0];
	int py=2-a[1];
	vector<vector<char>> mp(x+2,vector<char>(y+2,'*'));
	for(int i=0;i<=n;i++){
		int tx=vec[i].first+px,ty=vec[i].second+py;
		mp[tx][ty]=' ';
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(mp[i][j]=='*'){
				if(judge(mp,i,j)){
					cout<<' ';
				}else{
					cout<<'*';
				}
			}else{
				cout<<' ';
			}
		}
		cout<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	cin>>s;
	solve();
	return 0;
}


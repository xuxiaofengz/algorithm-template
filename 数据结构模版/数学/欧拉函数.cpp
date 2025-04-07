//例题:蓝桥题库 1154 互质个数和
//欧拉函数，计算小于i的数中与i互质的数的个数
int vis[N],phi[N],p[N];//phi[i]：欧拉函数的值,p[i]：存放第i个素数
int cnt=0;
ll sum[N];

void oula()//计算欧拉值,结合了线性筛素数
{
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			p[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++){
			ll t=(ll)i*p[j];
			if(t>=N)break;
			vis[t]=1;
			if(i%p[j]==0){//线性的关键
				phi[t]=p[j]*phi[i];
				break;
			}else{
				phi[t]=(p[j]-1)*phi[i];
			}
		}
	}
}

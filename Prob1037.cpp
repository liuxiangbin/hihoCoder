/*
	Problem1037:数字三角形
	一个简单的动态规划问题,其状态方程为：
	best[i][j] = max{best[i-1][j-1]+rewards[i][j],
					 best[i-1][j]+rewards[i][j]}
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 201;

//奖券数
int rewards[MAXN][MAXN];

//best(i,j)表示到达第i+1层第j+1个房间时最多的奖券数
int best[MAXN][MAXN];

int main()
{
	int n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	
	memset(best,0,sizeof(best));
	memset(rewards,0,sizeof(rewards));
	
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
			cin>>rewards[i][j];
	
	best[0][0] = rewards[0][0];
	for(int i=1;i<n;++i){
		best[i][0] = best[i-1][0]+rewards[i][0];
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<=i;++j){
			best[i][j] = max(best[i-1][j-1]+rewards[i][j],best[i-1][j]+rewards[i][j]);
		}
	
	int max = 0;
	for(int i=0;i<n;++i){
		if(best[n-1][i]>max)
			max = best[n-1][i];
	}
	
	cout<<max<<endl;

	return 0;
}
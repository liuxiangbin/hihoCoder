/*
	Problem 1038: 01背包
	经典动态规划问题，状态转移方程为：
	best[i][x] = max{best[i-1][x],
					 best[i-1][x-need[i]]+value[i]}
	表示前i件物品中以不超过x的花费可以得到的最大价值				 
*/
#include <iostream>
#include <vector>
//#include <cstdio>	//for freopen

using namespace std;

//const int MAXN = 501;
//const int MAXM = 100001;

//int best[MAXN][MAXM];


int main()
{
	//freopen("in.txt","r",stdin);

	int N,M;
	cin>>N>>M;
	
	//每件物品所需花费
	vector<int> need(N+1);
	//每件物品价值
	vector<int> value(N+1);
	
	int i,j;
	for(i=1;i<=N;++i)
		cin>>need[i]>>value[i];
	
	//方法一：内存开销太大
	/*for(i=0;i<=M;++i)
		best[0][i] = 0;
	
	for(i=1;i<=N;++i)
		for(j=0;j<=M;++j){
			if(j<need[i])
				best[i][j] = best[i-1][j];
			else
				best[i][j] = max(best[i-1][j],best[i-1][j-need[i]]+value[i]);
		}
	
	cout<<best[N][M]<<endl;*/

	//方法二：使用一个best[M+1]数组存储即可
	vector<int> best(M+1);

	for(i=0;i<=M;++i)
		best[i] = 0;
		
	for(i=1;i<=N;++i)
		for(j=M;j>=need[i];--j){
			best[j] = max(best[j],best[j-need[i]]+value[i]);
		}
	
	cout<<best[M]<<endl;
	
	return 0;
}
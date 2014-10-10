/*
	Problem1043：完全背包
	经典动态规划问题，状态转移方程为：
	best[i][x] = max{best[i-1][x-k*need[i]]+ k*value[i]|0<=k<=x/need[i]}
	因为：
	best[i][x-need[i]] = max{best[i-1][x-k*need[i]]+k*value[i]|1<=k<=x/need[i]}
	故：
	best[i][x] = max{best[i-1][x],best[i][x-need[i]]}
*/
#include <iostream>
#include <vector>
//#include <cstdio>		//for freopen

using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	
	int N,M;
	cin>>N>>M;
	
	int i,j;
	vector<int> need(N+1);
	vector<int> value(N+1);
	for(i=1;i<=N;++i)
		cin>>need[i]>>value[i];
		
	vector<int> best(M+1);
	for(i=0;i<=M;++i)
		best[i] = 0;
		
	for(i=1;i<=N;++i)
		for(j=need[i];j<=M;++j)
			best[j] = max(best[j],best[j-need[i]]+value[i]);
	
	cout<<best[M]<<endl;
			
	return 0;
}
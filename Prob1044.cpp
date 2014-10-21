/*
	Problem1044：状态压缩一
	令best[i][p1,p2,...pM-1]表示前i个位置确定时可以清理的最大垃圾数，
	又p1,p2...pM-1可用一个M-1位的二进制数s表示，于是其状态转移方程为：
		best[i+1][s>>1] = best[i][s]; //第i为不选
		best[i+1][2^(M-2)+s>>1] = best[i][s]+value[i+1]; //第i位选取
*/
#include <iostream>
#include <vector>
//#include <cstdio>		//for freopen

using namespace std;

//返回s的二进制表示中1的个数
int numOfOne(int s)
{
	int count = 0;
	while(s){
		++count;
		s &= (s-1);
	}
	
	return count;
}

int main()
{
	//freopen("in.txt","r",stdin);

	int N,M,Q;
	cin>>N>>M>>Q;
	
	int i,j;
	vector<int> value(N+1);
	for(i=1;i<=N;++i)
		cin>>value[i];
		
	int s = 1<<(M-1);
	//cout<<"s = "<<s<<endl;
	
	vector<vector<int> > best(N+1,vector<int>(s,0));
	
	for(i=0;i<N;++i)
		for(j=0;j<s;++j){
			int tmp = numOfOne(j);
			if(tmp>Q){
				best[i+1][j] = 0;
				continue;
			}	
			
			if(tmp<Q)
				best[i+1][j] = max(best[i][j>>1],best[i][(1<<(M-2))+(j>>1)]+value[i+1]);				
			else
				best[i+1][j] = best[i][j>>1];
		}
	
	int max = 0;
	for(j=0;j<s;++j){
		if(best[N][j]>max)
			max = best[N][j];
	}
	cout<<max<<endl;

	return 0;
}
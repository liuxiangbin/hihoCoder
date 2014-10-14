/*
	Problem	1051:补提交卡
	对于给定的M，枚举补交a1, a2, ...  aN中的连续M个，得到可以获得的最长连续天数。
*/
#include <iostream>
#include <vector>
//#include <cstdio>		//for freopen

using namespace std;

//返回此序列中的最长连续天数
int longestDay(vector<int> vi,int b,int e)
{
	vi.erase(vi.begin()+b,vi.begin()+e);
	int max = vi[0]-1;
	for(int i=1;i<vi.size();++i){
		int tmp = vi[i]-vi[i-1]-1;
		if(tmp > max)
			max = tmp;
	}
	
	return max;
}

int main()
{
	//freopen("in.txt","r",stdin);

	int T;
	cin>>T;
	int N,M;
	while(T--){
		cin>>N>>M;
		vector<int> vi(N);
		for(int i=0;i<N;++i)
			cin>>vi[i];
		if(N<=M){
			cout<<100<<endl;
			continue;
		}
		
		int max = 0;
		for(int i=0;i+M<N;++i){
			int tmp = longestDay(vi,i,i+M);
			if(tmp > max)
				max = tmp;
		}
		cout<<max<<endl;
	}

	return 0;
}
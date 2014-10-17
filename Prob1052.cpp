/*
	Problem 1052：基因工程
	设 gap = 字符串长度 - K，则距离为gap的一组字符需要进行比较， 
	只需要计算这组字符中个数最多的字符，然后将其他字符变为这个字符即可。
	所有组中改变的字符个数之和即是最少需要修改的字符个数。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//计算一组字符中最少需要修改的字符个数
int minChange(vector<char> &vc)
{
	int len = vc.size();
	sort(vc.begin(),vc.end());
	int max = 0,cnt = 1;
	for(int i=1;i<len;++i){
		if(vc[i]==vc[i-1]){
			++cnt;
		}
		else{	
			if(cnt > max)
				max = cnt;
			cnt = 1;
		}
	}
	if(cnt > max)
		max = cnt;
	
	return len-max;
}

int main()
{
	int T;
	cin>>T;
	string str;
	int k;
	while(T--){
		cin>>str;
		cin>>k;
		
		int len = str.size();
		if(len == k){
			cout<<0<<endl;
			continue;
		}	
		
		int cnt = 0;
		int gap = len - k;
		for(int i=0;i<gap;++i){
			vector<char> vc;
			int j = i;
			while(j<len){
				vc.push_back(str[j]);
				j += gap;
			}
			cnt += minChange(vc);
		}
		cout<<cnt<<endl;
		
	}

	return 0;
}
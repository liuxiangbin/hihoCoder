/*
	Problem 1039：字符消除
	枚举每个可能的插入情况，求得消除最多字符的情况
*/
#include <iostream>
#include <string>

using namespace std;

//消除相邻同样的字符，并返回消除字符数
int removeSameChar(string& str)
{
	int len = str.size();
	int i=0,j=0,cnt=0;
	while(i<len){
		j = i+1;
		while(j<len && str[j]==str[i])
			++j;
		if(j-i==1)
			str[cnt++] = str[i];
		i = j;
	}
	str.erase(cnt,len);
	int ret = len - cnt;
	if(ret!=0)
		return ret+removeSameChar(str);
	else
		return 0;
}


//枚举每个位置的可能情况的解决方法。
int main()
{
	int T;
	cin>>T;
	string str;
	while(T--){
		cin>>str;
		if(str.size()==0){
			cout<<0<<endl;
			continue;
		}
		
		int max = 0;
		int len = str.size();
		for(int i=0;i<len;++i)
			for(char c='A';c<='C';++c){
				string s = str.substr(0,i) + c + str.substr(i);	
				int tmp = removeSameChar(s);
				if(tmp > max)
					max = tmp;
			}
			
		cout<<max<<endl;
	}

	return 0;
}
/*
	Problem 1032：最长回文子串
	此处实现了三种算法：
	（1）暴力枚举算法：
		枚举每一个子串求取最长的回文子串，时间复杂度为O(N^3)
	（2）从中心位置向两边扩展的算法：
		枚举每个可能的中心位置，时间复杂度为O(N^2)
	（3）Manacher算法：
		求解最长回文子串的Manacher算法的简单应用，时间复杂度为O(N)
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool IsPalindrome(string str)
{
	int len = str.length();
	for(int i=0;i<len/2;++i){
		if(str[i]!=str[len-i-1])
			return false;
	}
	return true;
}

//暴力枚举算法
int Palindrome1(string str)
{
	int len = str.length();
	if(len == 1)
		return 1;
	string substr;
	int count = 0,tmp;
	for(int i=0;i<len;++i)
		for(int j=i+1;j<len;++j){
			tmp = j-i+1;
			substr = str.substr(i,tmp);
			if(IsPalindrome(substr) && tmp>count)
				count = tmp;
		}
	return count;
}

int extend(string str,int pos1,int pos2)
{
	int len = str.length();
	int l = pos1,r = pos2;
	
	while(l>=0 && r<len && str[l]==str[r]){
		--l;
		++r;
	}
	
	return r-l-1;
}

//从中心位置向两边扩展的算法
int Palindrome2(string str)
{
	int len = str.length();
	int count = 1;
	if(len == 1)
		return count;
	//两次扩展是为了统一奇偶长度的处理
	for(int i=0;i<len-1;++i){
		int tmp = extend(str,i,i);
		if(tmp > count)
			count = tmp;
		tmp = extend(str,i,i+1);
		if(tmp > count)
			count = tmp;
	}
	return count;
}

//对输入字符串进行预处理，统一奇偶长度的处理方法
string preprocess(string str)
{
	string res="$#";
	for(int i=0;i<str.size();++i){
		res += str[i];
		res += "#";
	}
	return res;
}

//求解最长回文子串的Manacher算法，O(N)时间
int Manacher(string str)
{
	int len = str.size();
	int *p = new int[len];
	memset(p,0,sizeof(p));
	
	int mx = 0,id = 0;
	for(int i=1;i<len;++i){
		if(mx > i)
			p[i] = min(p[2*id-i],mx-i);
		else 
			p[i] = 1;
			
		while(str[i-p[i]] == str[i+p[i]])
			++p[i];
		if(i+p[i] > mx){
			mx = i+p[i];
			id = i;
		}
	}
	
	int maxlen = 0;
	for(int i=1;i<len-1;++i)
		if(p[i]>maxlen)
			maxlen = p[i];
	delete[] p;
	
	return maxlen-1;	
}


int main()
{
	int N;
	cin>>N;
	string str;
	while(N--){
		cin>>str;
		str = preprocess(str);
		//cout<<str<<'\n';
		//cout<<Palindrome1(str)<<'\n';
		//cout<<Palindrome2(str)<<'\n';
		cout<<Manacher(str)<<'\n';
	}	

	return 0;
}
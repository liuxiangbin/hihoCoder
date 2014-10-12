/*
	Problem 1015:KMP算法
	KMP算法的实现和简单应用
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int next[10001];

//暴力匹配算法
int violentMatch(string text,string pattern)
{
	int count = 0;
	int tLen = text.size();
	int pLen = pattern.size();

	int i=0,j=0;
	while(i<tLen && j<pLen){
		if(text[i]==pattern[j]){
			++i;
			++j;
		}
		else{
			i = i-j+1;
			j = 0;
		}
		if(j==pLen){
			++count;
			i = i-j+1;
			j = 0;
		}
	}
	return count;
}

//产生Next数组
void genNext(string pattern)
{
	int pLen = pattern.size();
	next[0] = -1;
	int k = -1,j = 0;
	while(j<pLen){
		if(k==-1 || pattern[j]==pattern[k]){
			++k;
			++j;
			next[j] = k;
		}
		else{
			k = next[k];
		}
	}

	/*for(int i=0;i<=pLen;++i)
        cout<<next[i]<<" ";
    cout<<endl;*/
}

//KMP算法
int KMPMatch(string text,string pattern)
{
	int count = 0;
	int i=0,j=0;
	int tLen = text.length(),pLen = pattern.length();
	if(tLen<pLen)
		return 0;
		
	while(i<tLen && j<pLen){
		if(j==-1 ||text[i]==pattern[j]){
			++i;
			++j;
		}
		else{
			j = next[j];
		}
		if(j==pLen){
			++count;
			j = next[j];
		}
	}
	return count;
}

int main()
{
	int N;
	cin>>N;
	string text,pattern;

	while(N--){
		cin>>pattern;
		cin>>text;
		//cout<<violentMatch(text,pattern)<<'\n';
		genNext(pattern);
		cout<<KMPMatch(text,pattern)<<'\n';
		
	}
	return 0;
}


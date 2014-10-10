/*
	Problem 1049:后序遍历
	根据一棵树的先序序列和中序序列得到其后序序列，
	postOrder(str1,str2)= postOrder(str1Left,str2Left)+
					postOrder(str1Right,str2Right)+root
*/
#include <iostream>
#include <string>

using namespace std;

//str1：先序序列，str2:中序序列
//返回后序序列
string postOrder(string str1,string str2)
{
	if(str1.empty() || str2.empty())
		return "";
	char root = str1[0];

	int i;
	for(i=0;i<str2.size();++i)
		if(root==str2[i])
			break;

	string str1Left = str1.substr(1,i);
	string str1Right = str1.substr(i+1);
	string str2Left = str2.substr(0,i);
	string str2Right = str2.substr(i+1);
	
	return postOrder(str1Left,str2Left)+postOrder(str1Right,str2Right)+root;
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	//cout<<str1<<'\n'<<str2<<'\n';
	
	cout<<postOrder(str1,str2)<<endl;

	return 0;
}
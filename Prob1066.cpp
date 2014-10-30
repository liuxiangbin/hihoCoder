/*
	Problem 1066: 无间道之并查集
	并查集的简单应用
*/
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdio>

using namespace std;

map<string,string> parent;

string find(string name)
{
	if(parent.find(name)==parent.end())
		return name;
	if(parent[name] == name){
		return name;
	}
	else{
		return parent[name] = find(parent[name]);
	}
}

void unite(string name1,string name2)
{
	name1 = find(name1);
	name2 = find(name2);
	if(name1 == name2)
		return ;
	else{
		parent[name2] = name1;
	}
}

bool same(string name1,string name2)
{
	return find(name1)==find(name2);
}

int main()
{
	freopen("in.txt","r",stdin);

	int N;
	cin>>N;
	while(N--){
		int op;
		string name1,name2;
		cin>>op>>name1>>name2;
		if(op==0){
			if(parent.find(name1)==parent.end())
				parent[name1] = name1;
			if(parent.find(name2)==parent.end())
				parent[name2] = name2;
			unite(name1,name2);
		}
		else if(op==1){
			if(same(name1,name2))
				cout<<"yes\n";
			else	
				cout<<"no\n";
		}
	}
	
	return 0;
}
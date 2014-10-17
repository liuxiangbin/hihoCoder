/*
	Problem 1062:最近公共祖先 一
	建立起父子关系树，然后查找即可。
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
//#include <cstdio>

using namespace std;

//表示父子关系，键值为儿子
map<string,string> relation;

int main()
{
//	freopen("in.txt","r",stdin);
	
	int N;
	cin>>N;
	string father,son;
	for(int i=0;i<N;++i){
		cin>>father>>son;
		relation[son] = father;
	}
	
	int M;
	string ch1,ch2;
	cin>>M;
	for(int i=0;i<M;++i){
		cin>>ch1>>ch2;
		set<string> ancestor;
		
		//注意此处要求自己也是自己的祖先
		ancestor.insert(ch1);
		while(relation.find(ch1)!=relation.end()){	
			ch1 = relation[ch1];
			ancestor.insert(ch1);			
		}
		
		if(ancestor.empty()){
			cout<<-1<<endl;
			continue;
		}
		
		bool flag = false;
		if(ancestor.find(ch2)!=ancestor.end()){
				cout<<ch2<<endl;
				continue;			
		}
		while(relation.find(ch2)!=relation.end()){
			ch2 = relation[ch2];
			if(ancestor.find(ch2)!=ancestor.end()){
				cout<<ch2<<endl;
				flag = true;
				break;
			}			
		}
		if(!flag)
			cout<<-1<<endl;
	}

	return 0;
}
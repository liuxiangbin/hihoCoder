/*
	Trie树的简单使用问题。
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

#define TREE_WIDTH 26

struct trie_t{
	int count;
	struct trie_t *next[TREE_WIDTH];
};

static struct trie_t root = {0,{NULL}};


int insert(string word)
{
	struct trie_t *curr,*newnode;
	curr = &root;
	for(int i=0;i<word.length();++i){
		int tmp = word[i]-'a';
		if(curr->next[tmp]==NULL){
			newnode = (struct trie_t *)malloc(sizeof(struct trie_t));
			newnode->count = 0;
			memset(newnode->next,NULL,sizeof(newnode->next));
			curr->next[tmp] = newnode;
		}
		curr = curr->next[tmp];
		curr->count++;
	}

	return 0;
}

int find(string word)
{
	struct trie_t *p = &root;
	for(int i=0;i<word.length();++i){
	    int tmp = word[i]-'a';
		if(p->next[tmp]==NULL)
			return 0;
		p = p->next[tmp];
	}
	return p->count;
}

int main()
{
	int n,m;
	string word;

	cin>>n;
	for(int i=0;i<n;++i){
		cin>>word;
		//cout<<word<<endl;
		insert(word);
	}

	cin>>m;
	for(int j=0;j<m;++j){
		cin>>word;
		cout<<find(word)<<endl;
	}

	return 0;
}

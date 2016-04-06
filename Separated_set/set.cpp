#include "set.h"
TSet::TSet(){
	size=0;
}

TSet::TSet(int _size){
	size=_size;
	parent=new int[size];
	rank=new int[size];
	for (int i=0;i<size;i++)
		parent[i]=-1;
}

TSet::~TSet(){
	delete [] parent;
	delete [] rank;
	size=0;
}

void TSet::create(int x){
	rank[x]=0;
	parent[x]=x;
}

void TSet::merge_set(int a,int b){
	int s1=search(a);
	int s2=search(b);
	int r1=rank[s1];
	int r2=rank[s2];
	for(int i=0;i<size;i++){
		if(s2==parent[i])
			parent[i]=s1;}
	if (r1<r2)
		parent[s1]=s2;
	else {
		parent[s2]=s1;
		if (r1==r2)
			rank[s1]++;
	}
}

int TSet::search(int find){	// Возвращает голову множества, в которое входит этот элемент. 
	//int x=find;
	//int p=parent[x];
	//while(p!=x){
	//x=p;
	//p=parent[p];
	//}
	//while (find!=p){
	//x=parent[find];
	//parent[find]=p;
	//find=x;}
	if(find<size)
		return parent[find];
	else
		return -1;
}

void TSet::print()
{
	for(int i=0;i<size;i++)
		if (parent[i]==i)
		{
			for(int j=0;j<size;j++)
				if (parent[j]==i)
					cout<<"["<<j<<"]"<<endl;
			cout<<endl;
		}
}


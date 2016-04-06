#include "set.h"

void main(){
	setlocale (LC_ALL, "Russian");
	int n,m=0;
	cout << "Введите количество вершин:";
	cin >> n;
	cout << "Введите количество рёбер:";
	cin >> m;
	cout << "Заданы одноэлементные множества: ";
	for(int i=0;i<n;i++)
		cout<<i<<" ";
	cout<<endl<<endl;

	int **mas=new int *[m];
	for(int i=0;i<m;i++)
		mas[i]=new int [2];

	cout << "Введите пары вершин, между которыми есть рёбра"<<endl;
	for(int i=0;i<m;i++){
		cout << "Введите первую вершину:";
		cin >> mas[i][0];
		cout << "Введите вторую вершину:";
		cin >> mas[i][1];
	}

	TSet a(n);				//задали пустое множество с множеством допустимых значений: 0..n
	for (int i=0;i<n;i++)
		a.create(i);
	for (int j=0;j<m;j++){
		int x,y;
		x=a.search(mas[j][0]);
		y=a.search(mas[j][1]);
		a.merge_set(x,y);
	} 

	a.print();
	int find,flag=0;
	while (flag==0)
	{
		cout<<endl<<"Найти элемент:";
		cin>>find;
		if(a.search(find)!=(-1))
			cout<<"Голова этого элемента:"<<a.search(find)<<endl;
		else
			cout<< "Элемент отсутвует"<<endl;
		cout << "Хотите найти другой элемент?"<<endl<<"0-да"<<endl<<"1-нет"<<endl;
		cin>>flag;
	}
	getch();
}



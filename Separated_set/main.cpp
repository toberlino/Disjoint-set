#include "set.h"

void main(){
	setlocale (LC_ALL, "Russian");
	int n,m=0;
	cout << "������� ���������� ������:";
	cin >> n;
	cout << "������� ���������� ����:";
	cin >> m;
	cout << "������ �������������� ���������: ";
	for(int i=0;i<n;i++)
		cout<<i<<" ";
	cout<<endl<<endl;

	int **mas=new int *[m];
	for(int i=0;i<m;i++)
		mas[i]=new int [2];

	cout << "������� ���� ������, ����� �������� ���� ����"<<endl;
	for(int i=0;i<m;i++){
		cout << "������� ������ �������:";
		cin >> mas[i][0];
		cout << "������� ������ �������:";
		cin >> mas[i][1];
	}

	TSet a(n);				//������ ������ ��������� � ���������� ���������� ��������: 0..n
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
		cout<<endl<<"����� �������:";
		cin>>find;
		if(a.search(find)!=(-1))
			cout<<"������ ����� ��������:"<<a.search(find)<<endl;
		else
			cout<< "������� ���������"<<endl;
		cout << "������ ����� ������ �������?"<<endl<<"0-��"<<endl<<"1-���"<<endl;
		cin>>flag;
	}
	getch();
}



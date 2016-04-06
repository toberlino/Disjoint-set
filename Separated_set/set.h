#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class TSet {
public:
	int *parent;
	int *rank;
	int size;
	TSet ();
	TSet (int _size);
	~TSet();
	void create(int x);
	void merge_set(int a,int b);
	int search(int find);
	void print ();
};
#pragma once
#include "sach.h"
bool ascending(string ma1, string ma2);
bool decending(string ma1, string ma2);
class list
{private:
	sach* p;
	int length;
public:
	list(const list&);
	void input();
	void show();
	void add(sach, int);
	void addfirst(sach);
	void addfinal(sach);
	int indexOf(string);
	void update(string,string,int,int);
	void remove(string);
	void removeAt(int);
	// tim theo ma sach
	void find(int , int , string);
	//sap xep theo ten sach
	void QuickSort(const int& ,const int&,bool(*)(string,string)=ascending);
	list();
	~list();
	list(sach*&, int);
	int getLength();
	void setLength(int);
	sach& operator[](int)const;
	
};


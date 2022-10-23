#include "list.h"
#include"sach.h"
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>

using namespace std;
list::list() {
	p=nullptr; 
	length = 0;
}

sach& list::operator[](int index) {
	return *(this->p + index);
}
list::list(sach*& p, int length) {
	this->p = p;
	this->length = length;
}
list::~list() {
	delete[]p;
}
void list::input() {
	cout << "Nhap so luong sach: ";
	cin >> length;
	p = new sach[length];
	/*p[1] = sach("12345", "Duong toi mat troi", 1998, 20, true);
	p[2] = sach("87654", "Duong toi mat troi", 1998, 20, true);*/
	if(p!=nullptr)
	{for (int i = 0; i < length; i++)
	{
		cin>>p[i];
	}
	}
	
}
int list::getLength() {
	return length;
}
void list::setLength(int length) {
	this->length = length;
}
void list::add(sach s, int idx) {
	int check = 0;
	for (int i = 0; i < length; i++)
	{
		if (p[i].getmaSach() == s.getmaSach()) {
			p[i].setsoQuyen(p[i].getsoQuyen() + s.getsoQuyen());
			check = 1;
		}
	}
	if (check == 0) {
		sach* tmp = new sach[length + 1];
		for (int i = 0; i < length; i++) {
			tmp[i] = p[i];
		}
		for (int i = length; i > idx; i--) {
			tmp[i] = tmp[i - 1];
		}
		tmp[idx] = s;
		delete[] p;
		p = new sach[length + 1];
		for (int i = 0; i < length + 1; i++) {
			p[i] = tmp[i];
		}
		delete[]tmp;
		length++;
	}
}
void list::addfinal(sach sach) {
	add(sach, length);
}
void list::addfirst(sach sach) {
	add(sach, 0);
}
int list::indexOf(string masach) {
	for (int i = 0; i < length; i++) {
		if (p[i].getmaSach() == masach)
			return i;
	}
	return -1;
}
void list::removeAt(int index) {
	if (p[index].getsoQuyen() != 0) { p[index].setsoQuyen(p[index].getsoQuyen() - 1); }
	else {
		sach* tmp = new sach[length - 1];
		for (int i = 0; i < index; i++) {
			tmp[i] = p[i];
		}
		for (int i = index; i < length - 1; i++) {
			tmp[i] = p[i + 1];
		}
		delete[] p;
		p = new sach[length - 1];
		for (int i = 0; i < length - 1; i++) {
			p[i] = tmp[i];
		}
		delete[] tmp;
		length--;
	}
}
void list::remove(string masach) {
	while (1) {
		int idx = indexOf(masach);
		if (idx == -1) return;
		removeAt(idx);
	}
}
void list::show() {
	cout << "DANH SACH SACH:" << endl;
	cout << endl;
	cout << setw(5) << left <<"STT "<< setw(10) << left << "Ma sach" <<setw(20) << left << "Ten Sach" << setw(18) << left <<" Nam Xuat Ban" << setw(13) << left <<" So Luong" << setw(10) << left << "Tinh Trang" << endl;
	for (int i = 0; i < length
		; i++) {
		cout << setw(5) << left<< i + 1;
		cout << p[i];
	}
}
void list::update( string ms, string newName, int newnam, int newsl) {
	for (int i = 0; i < length; i++) {
		if (p[i].getmaSach() == ms) {
			p[i].settenSach(newName);
			p[i].setnamXB(newnam);
			p[i].setsoQuyen(newsl);
			//p[i].settinhTrang(check);
		}
	}
	
}
void list::find( int r,int l,string x) {
	
	if (r >= l) {
		int mid = l + (r - 1) / 2; 	
		if (x.compare(p[mid].getmaSach())==0)
		{
			
			cout << p[mid];
			return ;
		}		
		else if (p[mid].getmaSach() > x)
			return find(l, mid - 1, x);

		else return find(mid + 1, r, x);
	}
	else cout << "Khong tim thay sach co ma: " << x <<endl;
}

void list::QuickSort(const int &left,const int &right,bool(*sx)(string, string))
{
	int i, j;
	string x;
	i = left;
	j = right;
	
	x= p[(left + right) / 2].gettenSach();
	while (i <= j)
	{
		while (sx(p[i].gettenSach() , x)) i++;
		while (sx(x,p[j].gettenSach())) j--;
		if (i <= j)
		{	if(i<j)
				swap(p[i], p[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort( left, i,sx);
	if (right > i)
		QuickSort( i, right,sx);
}

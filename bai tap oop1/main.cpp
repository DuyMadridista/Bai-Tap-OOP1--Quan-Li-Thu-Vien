#include"list.h"
#include"sach.h"
#include"menu.h"
#include<iostream>
using namespace std;

int main() {
	list a;
	a.input();
	/*a.addfirst(sach("12345", "Duong toi mat troi", 1998, 20, true));
	a.addfirst(sach("52385", "Hoa hai duong", 1997, 20, true));
	a.addfirst(sach("42345", "Hala Madrid", 1977, 5, true));
	a.addfirst(sach("22345", "Duong Di", 1978, 50, true));
	a.addfirst(sach("32345", "Anh Trang", 1968, 0, false));*/
	
	menu c;
	c.mainmenu(a);


	//cout << b;
	
	//a.show();
	//a.add(s, 1);
	//a.show();
	//a.find(a.getLength() - 1,0, "1");
	//a.QuickSort(0, a.getLength()-1,ascending);
	//a.show();
}
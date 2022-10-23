#include"list.h"
#include"sach.h"
#include"menu.h"
#include<iostream>
using namespace std;

int main() {
	list a;
	//a.input();
	a.addfirst(sach("12345", "duong toi mat troi", 1998, 20, true));
	a.addfirst(sach("52385", "hoa hai duong", 1997, 20, true));
	a.addfirst(sach("42345", "hala madrid", 1977, 5, true));
	a.addfirst(sach("22345", "duong di", 1978, 50, true));
	a.addfirst(sach("32345", "anh trang", 1968, 0, false));
	
	menu c;
	c.mainmenu(a);


}
#include "menu.h"
#include"list.h"
#include"sach.h"
#include<iostream>
#include<string>
using namespace std;
bool ascending(string ma1, string ma2)
{
	return ma1 < ma2;
}
bool decending(string ma1, string ma2) {
	return ma1 > ma2;
}
menu::menu(){};
void menu::mainmenu( list a) {
	int check=0;
	while (!check)
	{
		cout << "================ MENU QUAN LI THU VIEN ==================\n";
		cout << "1.Xem danh sach sach co trong thu vien\n";
		cout << "2.Them sach vao dau danh sach\n";
		cout << "3.Them sach vao cuoi danh sach\n";
		cout << "4.Them sach vao vi tri bat ki trong danh sach\n";
		cout << "5.Cap nhat thong tin sach\n";
		cout << "6.Xoa sach o dau danh sach\n";
		cout << "7.Xoa sach o cuoi danh sach\n";
		cout << "8.Xoa sach bat  ki trong danh sach theo ma sach\n";
		cout << "9.Tim kiem sach theo ma sach\n";
		cout << "10.Sap xep sach theo ten sach\n";
		cout << "0.Thoat\n";
		cout << "=========================================================\n";
		int choise;
		cout << "Moi nhap lua chon: ";
		cin >> choise;
		switch (choise)
		{
		case 1: {
			a.show();
			system("pause");
			break;
		}
		case 2: {
			sach s;
			cout << "Nhap Thong Tin Sach Can Them:\n";
			cin >> s;
			a.addfirst(s);
			break;
			
		}
		case 3: {
			sach s;
			cout << "Nhap Thong Tin Sach Can Them:\n";
			cin >> s;
			a.addfinal(s);
			break;

		}
		case 4: {
			sach s;
			cout << "Nhap Thong Tin Sach Can Them:\n";
			cin >> s;
			int i;
			cout << "Nhap Vi Tri Them: ";
			cin >> i;
			a.add(s, i);
			break;
		}
		case 5: {
			string newma, newten;
			int newnamXB, newsl;
			cout << "Nhap ma Sach can thay doi thong tin: ";
			cin.ignore();
			getline(cin, newma);
			cout << "Nhap ten moi: ";
			getline(cin, newten);
			cout << " Nhap nam Xuat ban: ";
			cin >> newnamXB;
			cout << "Nhap so luong con lai: ";
			cin >> newsl;
			a.update(newma, newten, newnamXB, newsl);
			break;
		}
		case 6: {
			a.removeAt(0);
			cout << "Da xoa sach o dau danh sach";
			system("pause");
			break;

		}
		case 7: {
			a.removeAt(a.getLength()-1);
			cout << "Da xoa sach o cuoi danh sach";
			system("pause");
			break;

		}
		case 8: {	string ma;
			cout << "Nhap ma sach muon xoa: ";
			cin >> ma;
			a.remove(ma);
			cout << " Da xoa Sach co ma: " << ma << endl;
			system("pause");
			break;
		}
		case 9: {
			string ma;
			cout << "Nhap ma sach can tim: ";
			cin >> ma;
			cout << "Thong tin sach can tim: \n";
			a.find(a.getLength() - 1, 0, ma);
			system("pause");
			break;

		}
		case 10:{
			cout << "Sap Xep Sach Theo Ten" << endl;
			cout << "1.Sap xep theo thu tu tu A-Z\n";
			cout << "2.Sap Xep theo thu tu tu Z-A\n";
			cout << "Moi nhap lua chon: ";
			int choise;
			cin >> choise;
			if (choise == 1) a.QuickSort(0, a.getLength() - 1, ascending);
			else if (choise == 2) a.QuickSort(0, a.getLength() - 1, decending);
			cout << "Danh sach da sap xep la:\n";
			a.show();
			system("pause");
			break;
		}
		case 0: {
			cout << "Da thoat";
			check = 1;
			break;
		}
		default:
			break;
		}
	}

}
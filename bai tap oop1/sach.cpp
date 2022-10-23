#include "sach.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

sach::sach() : maSach(""), tenSach(""), namXB( 0), soQuyen ( 0),tinhTrang(false)  {}
sach::sach(string MSsach, string name, int nam,int sl,bool check)
	: maSach(MSsach), tenSach(name),namXB(nam),soQuyen(sl),tinhTrang(check) {}
sach::~sach() {
	//cout << "Huy sinh vien" << endl;
}
string sach::getmaSach() {
	return maSach;
}
void sach::setmaSAch(string MSsach) {
	this->maSach = MSsach;
}
string sach::gettenSach() {
	return tenSach;
}
void sach::settenSach(string name) {
	this->tenSach = name;
}
int sach::getnamXB() {
	return namXB;
}
void sach::setnamXB(int nam) {
	this->namXB = nam;
}
int sach::getsoQuyen() {
	return soQuyen;
};
void sach::setsoQuyen(int sl) {
	this->soQuyen = sl;
};
bool sach::gettinhTrang() {
	return tinhTrang;
};
void sach::settinhTrang(bool check) {
	this->tinhTrang = check;
};
ostream& operator<<(ostream& out, sach& sach) {
	if(sach.soQuyen>0)
	out <<setw(10)<<left << sach.maSach << setw(20) << left << sach.tenSach << setw(22) << left << sach.namXB << setw(15) << left << sach.soQuyen << setw(10) << left << "Con"<<endl;
	else
	out <<setw(10)<<left << sach.maSach << setw(20) << left << sach.tenSach << setw(22) << left << sach.namXB << setw(15) << left << sach.soQuyen << setw(10) << left << "Het"<<endl;
	//out << "MSsach: " << sach.maSach << endl;
	//out << "Ten sach: " << sach.tenSach << endl;
	//out << "Nam Xuat Ban: " << sach.namXB << endl;
	//out << "So Quyen: " << sach.soQuyen << endl;
	//out << "Tinh Trang: " << sach.tinhTrang << endl;
	return out;
}
int sach::checkMaSach(const string& id) {
	if (id.size() != 5) return 0;
	if (id[0] > '5' || id[0] < '1') return 0;
	for (int i = 1; i <= 4; i++) {
		if (id[i] > '9' || id[i] < '0') return 0;
	}
	return 1;
}
istream& operator>>(istream& in, sach& sach) {
	while (1) {
		cout << "nhap ma sach: ";
		in >> sach.maSach;
		if (sach.checkMaSach(sach.maSach)) {
			cout << "nhap ten sach: ";
			in.ignore();
			getline(in, sach.tenSach);
			cout << "nhap nam XB: ";
			cin >> sach.namXB;
			cout << "nhap so luong: ";
			cin >> sach.soQuyen;
			if (sach.soQuyen == 0) sach.tinhTrang = false;
			else sach.tinhTrang = true;
			return in;
			break;
		}
		else cout << "Ma sach khong dung, moi nhap lai!!!" << endl;

	}
}
	//do {
	//	cout << "nhap ma sach: ";
	//	/*in.ignore();*/
	//	in>> sach.maSach;
	//} while (!sach.checkMaSach(sach.maSach));
	//	cout << "nhap ten sach: ";
	//	in.ignore();
	//	getline(in, sach.tenSach);
	//	cout << "nhap nam XB: ";
	//	cin >> sach.namXB;
	//	cout << "nhap so luong: ";
	//	cin >> sach.soQuyen;
	//	if (sach.soQuyen == 0) sach.tinhTrang = false;
	//	else sach.tinhTrang = true;
	//	return in;
	//
	
	
//}

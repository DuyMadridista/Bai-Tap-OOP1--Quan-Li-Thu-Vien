#pragma once
#include<string>
using namespace std;
class sach
{
private:
	string maSach;
	string tenSach;
	int namXB;
	int soQuyen;
	bool tinhTrang;
public:
	sach();
	sach(string, string, int, int, bool);
	~sach();
	string getmaSach();
	void setmaSAch(string);
	string gettenSach();
	void settenSach(string);
	int getnamXB();
	void setnamXB(int);
	int getsoQuyen();
	void setsoQuyen(int);
	bool gettinhTrang();
	void settinhTrang(bool);
	void show();
	int checkMaSach(const string&);
	friend ostream& operator<<(ostream&, sach&);
	friend istream& operator>>(istream&, sach&);
	


};


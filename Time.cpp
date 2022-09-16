#include <iostream>
#include <fstream>

using namespace std;

class Time
{
public:
	Time();
	void Nhap();
	void Cong(int n);
	void Tru(int n);
	void HienThi(string s);
private:
	int gio, phut, giay;

};

Time::Time()
{
};

void Time::Nhap() {
	cout << "Nhap thoi gian (gio,phut,giay) : ";
	do {
		cin >> gio >> phut >> giay;
	} while (gio < 0 || phut < 0 || giay < 0);
};

void Time::Cong(int m) {
	giay += m;
	if (giay >= 60) {
		phut += giay / 60;
		giay %= 60;
	}
	if (phut >= 60) {
		gio += phut / 60;
		phut %= 60;
	}
};

void Time::Tru(int n) {
	giay -= n;
	if (giay < 0) {
		phut -= (abs(giay / 60) + 1);
		giay += (abs(giay / 60) + 1) * 60;
	}
	if (phut < 0) {
		gio -= (abs(phut / 60) + 1);
		phut += (abs(phut / 60) + 1) * 60;
	}
}

void Time::HienThi(string s) {
	cout << "Thoi gian sau khi " << s << " : "<< gio << ":" << phut << ":" << giay << endl;
};

int main() {
	Time S;
	int n,m;
	S.Nhap();
	cout << "Nhap so giay muon cong them : " ;
	cin >> m;
	S.Cong(m);
	S.HienThi("cong");
	cout << "Nhap so giay muon tru di : " ;
	cin >> n;
	S.Tru(n);
	S.HienThi("tru");
	return 0;
};
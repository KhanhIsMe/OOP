#include <iostream>
#include <fstream>

using namespace std;

class Time
{
public:
	Time();
	void Nhap();
	void Cong(int n);
	void HienThi();
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

void Time::Cong(int n) {
	int s, p, h;
	s = giay + n;
	if (s >= 60) {
		p = s / 60;
		giay = s % 60;
	}
	p = p + phut;
	if (p >= 60) {
		h = p / 60;
		phut = p % 60;
	}
	gio += h;
};

void Time::HienThi() {
	cout << gio << ":" << phut << ":" << giay;
};

int main() {
	Time S;
	int n;
	S.Nhap();
	cout << "Nhap so giay muon cong them : ";
	cin >> n;
	S.Cong(n);
	S.HienThi();
	return 0;
};
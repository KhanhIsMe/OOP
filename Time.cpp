#include <iostream>
#include <fstream>

using namespace std;

class Time
{
    
public:
	Time();
	Time(int h, int m, int s);
	void Nhap();
	Time Cong(int n);
	Time Tru(int n);
	friend Time Cong(Time a, Time b);
	friend Time Tru(Time a, Time b);
	void HienThi(string s);
private:
	int gio, phut, giay;

};

Time::Time()
{
};

Time::Time(int h, int m, int s) {
	gio = h;
	phut = m;
	giay = s;
}

void Time::Nhap() {
	cout << "Nhap thoi gian (gio,phut,giay) : ";
	do {
		cin >> gio >> phut >> giay;
	} while (gio < 0 || phut < 0 || giay < 0);
};

Time Time::Cong(int m) {
	Time s(gio,phut,giay);
	s.giay += m;
	if (s.giay >= 60) {
		s.phut += s.giay / 60;
		s.giay %= 60;
	}
	if (s.phut >= 60) {
		s.gio += s.phut / 60;
		s.phut %= 60;
	}
	return s;
};

Time Cong(Time a, Time b) {
	Time s(a.gio + b.gio, a.phut + b.phut, a.giay + b.giay);
	if (s.giay >= 60) {
		s.phut += s.giay / 60;
		s.giay %= 60;
	}
	if (s.phut >= 60) {
		s.gio += s.phut / 60;
		s.phut %= 60;
	}
	return s;
};

Time Time::Tru(int n) {
	Time s(gio, phut, giay);
	s.giay -= n;
	if (s.giay < 0) {
		s.phut -= (abs(s.giay / 60) + 1);
		s.giay += (abs(s.giay / 60) + 1) * 60;
	}
	if (s.phut < 0) {
		s.gio -= (abs(s.phut / 60) + 1);
		s.phut += (abs(s.phut / 60) + 1) * 60;
	}
	return s;
};

Time Tru(Time a, Time b) {
	Time s(a.gio - b.gio, a.phut - b.phut, a.giay - b.giay);
	if (s.giay < 0) {
		s.phut -= (abs(s.giay / 60) + 1);
		s.giay += (abs(s.giay / 60) + 1) * 60;
	}
	if (s.phut < 0) {
		s.gio -= (abs(s.phut / 60) + 1);
		s.phut += (abs(s.phut / 60) + 1) * 60;
	}
	return s;
}

void Time::HienThi(string s) {
	cout << "Thoi gian sau khi " << s << " : " << gio << ":" << phut << ":" << giay << endl;
};

int main() {
	Time S1, S2, C, T;
	int n, m;
	S1.Nhap();
	S2.Nhap();
	cout << "Nhap so giay muon cong them : ";
	cin >> m;
	C = S1.Cong(m);
	C.HienThi("cong");
	C = Cong(S1, S2);
	C.HienThi("cong");
	cout << "Nhap so giay muon tru di : ";
	cin >> n;
	T = S1.Tru(n);
	T.HienThi("tru");
	T = Tru(S1,S2);
	T.HienThi("tru");
	return 0;
};
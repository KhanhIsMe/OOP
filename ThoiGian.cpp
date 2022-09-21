#include <iostream>

using namespace std;

class Time{
    private:
        int gio,phut,giay;
    public:
    Time();
    Time(int a, int b, int c);
    void Nhap();
    void Xuat();
    friend Time Cong(Time a, int b);
};

Time::Time(){

}

Time::Time(int a, int b, int c){
    gio = a;
    phut = b;
    giay = c;
};

void Time::Nhap(){
    cout << "Nhap thoi gian(gio,phut,giay) : ";
    cin >> gio >> phut >> giay;
};

void Time::Xuat(){
    cout << "Gio sau khi cong : " << gio << ":" << phut << ":" << giay << endl;
};

Time Cong(Time a, int b){
    Time kq;
    int c,d;
    kq.giay = a.giay + b;
    if (kq.giay >= 60){
        c = kq.giay / 60;
        kq.giay = kq.giay % 60;
        kq.phut = a.phut + c;
        if (kq.phut >= 60){
            d = kq.phut / 60;
            kq.phut = kq.phut % 60;
            kq.gio = a.gio + d;
        }
    }
    return kq;
}

int main(){
    Time a,kq;
    int b;
    cout << "Nhap so giay muon cong : ";
    cin >> b;
    a.Nhap();
    kq = Cong(a,b);
    kq.Xuat();
    
}
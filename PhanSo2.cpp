#include <iostream>
#include <fstream>

using namespace std;

class PhanSo {
    private:
        int tu, mau;
    public:
        PhanSo();
        PhanSo(int a, int b);
        void Nhap(char a);
        void Xuat(string s);
        int UCLN(int a, int b);
        void DoiDau();
        friend PhanSo ToiGian(PhanSo a);
        friend PhanSo Tong(PhanSo a, PhanSo b);
        PhanSo Tong(PhanSo b);
        PhanSo Tong(int b);
        friend PhanSo Hieu(PhanSo a, PhanSo b);
        friend PhanSo Tich(PhanSo a, PhanSo b);
        friend PhanSo Chia(PhanSo a, PhanSo b);

};

PhanSo::PhanSo() {

}

PhanSo::PhanSo(int a, int b) {
    tu = a;
    mau = b;
}

void PhanSo::DoiDau() {
    if (mau < 0 && tu > 0) {
        mau = -mau;
        tu = -tu;
    };
    if (mau < 0 && tu < 0) {
        mau = -mau;
        tu = -tu;
    };
}

int PhanSo::UCLN(int a, int b) {
    if (a == 0 || b == 0)
        return (a+b);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a != b)
        if (a>b)
            a -= b;
        else
            b -= a;
    return a;
};

PhanSo ToiGian(PhanSo a) {
    int b;
    b = a.UCLN(a.tu, a.mau);
    a.tu /= b;
    a.mau /= b;
    return a;
};

PhanSo Tong(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau + b.tu * a.mau;
    c.mau = a.mau * b.mau;
    return ToiGian(c);
};

PhanSo PhanSo::Tong(PhanSo b){
    PhanSo KQ;
    KQ.tu = tu * b.mau + b.tu * mau;
    KQ.mau = mau*b.mau;
    return ToiGian(KQ);
}

PhanSo PhanSo::Tong(int b){
    PhanSo KQ;
    KQ.tu = tu + b*mau;
    KQ.mau = mau;
    return ToiGian(KQ);
}

PhanSo Hieu(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau - b.tu * a.mau;
    c.mau = a.mau * b.mau;
    return ToiGian(c);
};

PhanSo Tich(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu * b.tu;
    c.mau = a.mau * b.mau;
    return ToiGian(c);
}

PhanSo Chia(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu * b.mau;
    c.mau = a.mau * b.tu;
    return ToiGian(c);
}

void PhanSo::Nhap(char a) {
    do{
        cout << "Nhap phan so " << a << " : ";
        cin >> tu >> mau;
    }while(mau == 0); 
    DoiDau();
}

void PhanSo::Xuat(string s) {
    cout << s << " la : " << tu << "/" << mau << endl;
}

int main() {
    PhanSo a, b, c;
    int e=9;
    a.Nhap('1');
    b.Nhap('2');
    // c = Tong(a, b);
    c = a.Tong(e);
    c.Xuat("Ket qua phep cong");
    c = Hieu(a, b);
    c.Xuat("Ket qua phep tru");
    c = Tich(a,b);
    c.Xuat("Ket qua phep nhan");
    c = Chia(a,b);
    c.DoiDau();
    c.Xuat("Ket qua phep chia");
}
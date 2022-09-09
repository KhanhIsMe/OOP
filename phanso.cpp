#include <iostream>

using namespace std;

/*struct phanso
{
    int tu,mau;
};

int ucln(int a,int b)
{
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

void toigian(phanso a[],int n)
{
   int b;
   b = ucln(a[n].tu,a[n].mau);
   a[n].tu /= b;
   a[n].mau /= b;
};

void doidau(phanso a[] , int n){
    if (a[n].tu < 0 && a[n].mau < 0){
        a[n].tu = - a[n].tu;
        a[n].mau = - a[n].mau;
    };
}

void tinhtong(phanso a[]){
    int m,n;
    m = a.tu * b.mau + b.tu * a.mau;
    n = a.mau * b.mau;
    a[3].tu = m;
    a[3].mau = n;
    toigian(a,3);
};

void tinhhieu(phanso a[]){
    int m,n;
    m = a.tu * b.mau - b.tu * a.mau;
    n = a.mau * b.mau;
    a[4].tu = m;
    a[4].mau = n;
    toigian(a,4);
}

int main(){
    phanso a[6];
    cout << "Nhap phan so thu nhat : " ;
    cin >> a.tu >> a.mau;
    cout << "Nhap phan so thu hai : ";
    cin >> b.tu >> b.mau;
    tinhtong(a);
    cout << "Tong hai phan so la : " << a[3].tu << "/" << a[3].mau << endl;
    tinhhieu(a);
    cout << "Hieu hai phan so la : " << a[4].tu << "/" << a[4].mau << endl;
}*/

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo();
    PhanSo(int a, int b);
    void Nhap();
    void Xuat(string s);
    int UCLN(int a, int b);
    void DoiDau();
    friend PhanSo ToiGian(PhanSo a);
    friend PhanSo Tong(PhanSo a, PhanSo b);
    friend PhanSo Hieu(PhanSo a, PhanSo b);

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
    c = ToiGian(c);
    return c;
};

PhanSo Hieu(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau - b.tu * a.mau;
    c.mau = a.mau * b.mau;
    ToiGian(c);
    return c;
};

void PhanSo::Nhap() {
    cout << "Nhap phan so : ";
    cin >> tu >> mau;
    DoiDau();
}

void PhanSo::Xuat(string s) {
    cout << "Phan so " << s << " la : " << tu << "/" << mau << endl;
}

int main() {
    PhanSo a, b, c, d;
    a.Nhap();
    b.Nhap();
    a.Xuat("a");
    c = Tong(a, b);
    c.DoiDau();
    c.Xuat("tong");
    d = Hieu(a, b);
    d.DoiDau();
    d.Xuat("hieu");
}
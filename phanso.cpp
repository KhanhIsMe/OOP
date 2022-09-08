#include <iostream>

using namespace std ;

struct phanso
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
    m = a[1].tu * a[2].mau + a[2].tu * a[1].mau;
    n = a[1].mau * a[2].mau;
    a[3].tu = m;
    a[3].mau = n;
    toigian(a,3);
};

void tinhhieu(phanso a[]){
    int m,n;
    m = a[1].tu * a[2].mau - a[2].tu * a[1].mau;
    n = a[1].mau * a[2].mau;
    a[4].tu = m;
    a[4].mau = n;
    toigian(a,4);
}

int main(){
    phanso a[6];
    cout << "Nhap phan so thu nhat : " ;
    cin >> a[1].tu >> a[1].mau;
    cout << "Nhap phan so thu hai : ";
    cin >> a[2].tu >> a[2].mau;
    tinhtong(a);
    cout << "Tong hai phan so la : " << a[3].tu << "/" << a[3].mau << endl;
    tinhhieu(a);
    cout << "Hieu hai phan so la : " << a[4].tu << "/" << a[4].mau << endl;
}
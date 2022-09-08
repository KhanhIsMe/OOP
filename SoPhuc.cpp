#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double thuc,ao;
public:

    SoPhuc();
    SoPhuc(double a, double b);
    friend SoPhuc Tong(SoPhuc n, SoPhuc m);
    friend SoPhuc Hieu(SoPhuc n, SoPhuc m);
    void Input(int n);
    void Output();
 
};


SoPhuc::SoPhuc(/* args */)
{
}

SoPhuc::SoPhuc(double a, double b){
    thuc = a;
    ao = b;
}

void SoPhuc::Input(int n){
    cout << "Nhap so thuc " << n << " : ";
    cin >> thuc >> ao;
}

void SoPhuc::Output(){
    cout << "So phuc la : " << thuc << " + " << ao << "i" << endl;
}

SoPhuc Tong(SoPhuc n , SoPhuc m){
    SoPhuc c;
    c.thuc = n.thuc + m.thuc;
    c.ao = n.ao + m.ao;
    return c;
}

SoPhuc Hieu(SoPhuc n, SoPhuc m){
    SoPhuc c;
    c.thuc = n.thuc - m.thuc;
    c.ao = n.ao - m.ao;
    return c;
}

int main(){
    SoPhuc a[50];
    a[1].Input(1);
    a[2].Input(2);
    a[3] = Tong(a[1] , a[2]);
    a[3].Output();
    a[4] = Hieu(a[1] , a[2]);
    a[4].Output();
}

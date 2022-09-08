#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class HinhTron
{
private:
    int r;
public:
    void Nhap();
    double DienTich();
    double ChuVi();
    void HienThi();
    HinhTron();
    HinhTron(int b);
};

HinhTron::HinhTron(){

}

HinhTron::HinhTron(int b){
    r = b;
}

void HinhTron::Nhap(){
    cout << "Nhap ban kinh hinh tron : ";
    cin >> r;
};

double HinhTron::DienTich(){
    return 3.14*r*r;
};
double HinhTron::ChuVi(){
    return 2*3.14*r;
};

void HinhTron::HienThi(){
    cout << "Chu vi hinh tron la : " << ChuVi() << endl;
    cout << "Dien tich hinh tron la : " << DienTich() << endl;
};

int main(){
    HinhTron S1,S2(0);
    S1.Nhap();
    S1.HienThi();
    S2.HienThi();
}

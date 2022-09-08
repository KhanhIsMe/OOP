#include <iostream>

using namespace std;

class hinhchunhat{
    public:
        double dai,rong,cao;
        double TheTich(){
            return dai*rong*cao;
        };
        double DienTich(){
            return dai*rong;
        };
        double ChuVi(){
            return (dai+rong)*2;
        };
        void Nhap(){
            cout << "Nhap chieu dai : ";
            cin >> dai;
            cout << "Nhap chieu rong : ";
            cin >> rong;
            cout << "Nhap chiue cao : ";
            cin >> cao;
        };
        void HienThi(){
            cout << "Dien tich : " << DienTich() << endl;
            cout << "Chu vi mat day : " << ChuVi() << endl;
            cout << "The tich : " << TheTich() << endl;
        };
};

int main(){
    hinhchunhat S;
    S.Nhap();
    S.HienThi();
    return 0;
}
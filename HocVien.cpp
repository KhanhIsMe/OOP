#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class HocVien
{
    private:
        int Toan,Ly,Hoa,Tuoi;
        string Ten,DiaChi,GioiTinh,Lop;
    public:
        void Input(){
            cout << "Nhap ten : ";
            cin >> Ten ;
            cin.ignore();
            cout << "Nhap dia chi : ";
            getline(cin,DiaChi);
            // cin.ignore();
            cout << "Nhap lop : ";
            getline(cin,Lop);
            cout << "Nhap gioi tinh : ";
            cin >> GioiTinh ;
            cout << "Nhap tuoi, diem toan ly hoa : ";
            cin >> Tuoi >> Toan >> Ly >> Hoa ; 
        };
        double DiemTB(){
            double TB;
            TB = (Toan + Ly + Hoa)/3.00;
            return TB;
        };
        void HienThi(){
            
            cout << "Ten : " << Ten << endl;
            cout << "Tuoi : " << Tuoi << endl;
            cout << "Gioi tinh : " << GioiTinh << endl;
            cout << "Diem trung binh : " <<  DiemTB() <<endl;
        };
        void HienThiThongTin();
};

void HocVien::HienThiThongTin(){
    cout << "Dia chi : " << DiaChi << endl;
    cout << "Lop : "  << Lop << endl;
    cout << "<------------------------------->\n";
};

int main(){
    HocVien S[10];
     int i,n;
    cout << "Nhap so sinh vien : ";
    cin >> n;
   
    for (int i = 0 ; i < n ; i++){
        cout << "Sinh vien " << i+1 << endl;
        S[i].Input();
        cout << "<------------------------------->\n";
    };
    for (int i = 0 ; i < n ; i++){
        cout << "Sinh vien " << i+1 << endl; 
        S[i].HienThi();
        S[i].HienThiThongTin();
    };
}

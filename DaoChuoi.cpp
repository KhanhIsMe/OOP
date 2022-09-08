#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Chuoi{
    public:
        int n;
        string str ;
        void Nhap(){
            cout << "Nhap chuoi : ";
            getline(cin,str);
        };
        void XuLi(){
            n = str.size();
            cout << "Ham co " << n << " ki tu." << endl;
            for (int i = n - 1  ; i >= 0 ; i --){
                cout << str[i];
            };
        };
};

int main(){
    Chuoi S;
    S.Nhap();
    S.XuLi();
}
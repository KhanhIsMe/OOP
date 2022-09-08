#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Chuoi{
    public :
        string str;
        int n,i;
        void Nhap(){
            cout << "Nhap chuoi : ";
            getline(cin, str);
        };
        void Upper(int m){
            if (str[m] >= 'a' && str[m] <= 'z'){
                str[m] -= 32;
            };
        };
        void XuLi(){
            n = str.size();
            if (str[0] != ' ') Upper(0);
            for ( i = 0 ; i < n-1 ; i++){
                if (str[i] == ' ' && str[i+1] != ' ')
                    Upper(i+1);
            };
        };
        void HienThi(){
            cout << "Chuoi da duoc xu li : ";
            for (i = 0 ; i < n ; i++){
                cout << str[i];
            };
        };
};

int main(){
    Chuoi S;
    S.Nhap();
    S.XuLi();
    S.HienThi();
}
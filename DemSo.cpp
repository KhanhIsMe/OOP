#include <iostream>
#include <string>

using namespace std;

class Chuoi{
    public:
        string str;
        int dem = 0,i;
        void Nhap(){
            cout << "Nhap chuoi : " ;
            getline(cin , str);
        };
        void XuLi(){
            for (i = 0 ; i < str.size() ; i ++){
                if (str[i] >= '0' && str[i] <= '9') dem++;
            };
        };
        void HienThi(){
            XuLi();
            cout << "Trong chuoi co " << dem << " chu so" << endl;
        };
};

int main(){
    Chuoi S;
    S.Nhap();
    S.HienThi();
    return 0;
};
#include <iostream>
#include <string>

using namespace std;


class Chuoi {
    private:
        string str;
        int tong = 0, n, dem, max = 0, dau, cuoi;
    public:
        void Nhap() {
            cout << "Nhap chuoi : ";
            getline(cin, str);
            n = str.size();
        };
        void Xuli() {
            for (int i = 0; i < n ; i++) {
                if (str[i] != ' ') {
                    tong++;
                    int j = i;

                    dem = 0;
                    while (str[j] != ' ' && j < n ) {
                        j++;
                        dem++;
                    };

                    if (dem > max) {
                        max = dem;
                        dau = i;
                        cuoi = j - 1;
                    };
                    i = j;
                };
            };
        }
        void HienThi() {
            if (tong != 0){
                cout << "Trong cau co " << tong << " tu." << endl;
                cout << "Tu dai nhat trong cau la : ";
                for (int i = dau; i <= cuoi; i++)
                    cout << str[i];
            }
            else{
                cout << "Khong co tu nao trong cau !!!";
            };
            
        };

};

int main() {
    Chuoi S;
    S.Nhap();
    S.Xuli();
    S.HienThi();
}
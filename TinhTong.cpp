#include <iostream>
#include <math.h>

using namespace std;

int Mu(int a, int n) {
    int m = 1;
    for (int i = 1; i <= n; i++)
        m *= a;
    return m;
};

double TinhTong(int x, int n) {
    double m = 0, tong = 0;
    for (double i = 0; i <= n; i++) {
        m = Mu(x, i) / (i + 1);
        tong += m;
    }

    return tong;
};

void Nhap(int& x, int& n) {
    cout << "Nhap x va n : ";
    cin >> x >> n;
};

void HienThi(int x, int n) {
    cout << "Tong la : " << TinhTong(x, n);
};

int main() {
    int x, n;
    Nhap(x, n);
    HienThi(x, n);
}
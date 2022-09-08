
#include <iostream>

using namespace std;

struct Toado
{
    int x,y;
};

void kiemtra(Toado a[])
{
    int c, b, n;
    if (a[1].y - a[2].y != 0 || a[1].x - a[2].x != 0){
        c = (a[1].y - a[2].y) / (a[1].x - a[2].x);
        b = a[1].y - c * a[1].x;
        n = c * a[3].x + b - a[3].y;
        if (n == 0)
            cout << "Day khong phai la tam giac !!!" << endl;
        else
            cout << "Day la tam giac." << endl;
    }
    else {
        cout << "Co diem trung nhau !!!" << endl;
    }

    
};

int main()
{
    Toado a[4];
    int b, c;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Nhap toa do diem " << i << " : ";
        cin >> a[i].x;
        cin >> a[i].y;
    };
    kiemtra(a);
    return 0;
}
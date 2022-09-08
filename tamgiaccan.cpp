#include <iostream>
#include <math.h>
using namespace std;

int kiemtra(int a,int b,int c)
{
    if (a + b <= c || a + c <= b || b + c <= a )
    {
        cout << "Day khong phai la tam giac !!!" << endl;
        return 1;
    };
    if (a == b && b == c)
        cout << "Day la tam giac deu." << endl;
    else {
        if (a == b || b == c || c == a)
            cout << "Day la tam gia can." << endl;
        else
            cout << "Day la tam giac thuong." << endl;
    };
    return 0;
};

float dientich(int a,int b,int c)
{
    float p,s;
    p = (a + b + c)/2.00;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
};

int main(){
    int a[10];
    for (int i = 0 ; i <= 2 ; i++){
        do
        {
            cout << "Nhap canh " << i + 1 << " : ";
            cin >> a[i];
        } while (a[i] <= 0);
           
    };
    if (kiemtra(a[0],a[1],a[2]) == 0 )
        cout << "Dien tich cua tam giac la : " << dientich(a[0],a[1],a[2]) << endl;
    return 0;
}
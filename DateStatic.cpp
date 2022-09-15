#include <iostream>

using namespace std;

class Date
{
private:
    int ngay,thang,nam;
public:
    static int NamThuong[13];
    static int NamNhuan[13];
    Date(/* args */);
    ~Date();
    void Nhap();
    void Xuat();
    void Xuli();
    int Nhuan();
};

int Date::NamThuong[13] = {31,28,31,30,31,30,31,31,30,31,30,31};
int Date::NamNhuan[13] = {31,29,31,30,31,30,31,31,30,31,30,31};
Date::Date(/* args */)
{
}

Date::~Date()
{
}

void Date::Nhap(){
    cout << "Nhap thang nam : ";
    cin >> thang >> nam;
};

int Date::Nhuan(){
    if (nam % 100 == 0){
        if (nam % 400 == 0) return 1;
        else    
            return 0;
    } else {
        if (nam % 4 == 0) return 1;
        else 
            return 0;
    }
}

void Date::Xuli(){
    if (this->Nhuan() == 1)
        cout << "Thang " << thang << " nam " << nam << " co " << NamNhuan[thang-1] << " ngay.\n";
    else    
        cout << "Thang " << thang << " nam " << nam << " co " << NamThuong[thang-1] << " ngay.\n";
}

int main(){
    Date d;
    d.Nhap();
    d.Xuli();
    system("pause");
}
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
private:
    int ngay, thang, nam;
public:
    Date(/* args */);
    ~Date();
    void Nhap();
    void HienThi();
    int NamNhuan();
    int KiemTra();
    int Nhom();
    int next();
    int pre();
    int XLNgay();
};

Date::Date(/* args */)
{
}

Date::~Date()
{
}

void Date::Nhap(){
    cout << "Nhap ngay thang nam : ";
    cin >> ngay >> thang >> nam;
};

void Date::HienThi(){
    cout << "Ngay " << ngay << " thang " << thang << " nam " << nam << endl;
}
int Date::Nhom(){
    if (thang == 1 || thang == 3 ||thang == 5 ||thang == 7 ||thang == 8 ||thang == 10 ||thang == 12 ) return 1;
    if (thang == 4 ||thang == 6 ||thang == 9 ||thang == 11 ) return 2;
    return 3;
};

int Date::NamNhuan(){
    if (nam % 100 == 0){
        if (nam % 400 == 0) return 1;
        return 0;
    }
    else {
        if (nam % 4 == 0) return 1;  
        return 0;
    }
    
};

int Date::KiemTra(){
    if ( 1 <= thang  && thang <= 12 && nam >= 0){
        if (this->Nhom() == 1 && ngay >=1 && ngay <= 31) return 1;
        if (this->Nhom() == 2 && ngay >=1 && ngay <= 30) return 1;
        if (this->Nhom() == 3) 
            if (this->NamNhuan() == 1){
                if (ngay >=1 && ngay <= 29) return 1;
            }
            else 
                if (ngay >=1 && ngay <= 28) return 1;
        return 0;
    }
    return 0;  
};

int Date::next(){
    ngay += 1;
    if (this->Nhom() == 1){
        if (ngay > 31){
            thang += ngay / 31;
            ngay %= 31;
        }
        if (thang > 12){
            nam += thang / 12;
            thang %= 12;
        }
    };
    if (this->Nhom() == 2){
        if (ngay > 30){
            thang += ngay / 30;
            ngay %= 30;
        }
        if (thang > 12){
            nam += thang / 12;
            thang %= 12;
        }
    }
    if (this->Nhom() == 3){
        if (this->NamNhuan() == 1){
            if (ngay > 29) {
                thang += ngay / 29;
                ngay %= 29;
            }    
        } else {
            if (ngay > 28){
                thang += ngay / 28;
                ngay %= 28;
            }
        }
        if (thang > 12){
            nam += thang / 12;
            thang %= 12;
        }
    }

}
    
int Date::pre(){
    ngay -= 1;
    if (ngay >= 1 ) return 0;
    if (ngay == 0) 
        thang -= 1;
    if (thang == 0){
        thang = 12;
        nam--;
    }
    if (this->Nhom() == 1) ngay = 31;
    if (this->Nhom() == 2) ngay = 30;
    if (this->Nhom() == 3) 
        if (this->NamNhuan() == 1)
            ngay = 29;
        else    
            ngay = 28;
};

int Xuli(Date &d){
    int n;
    do{
        d.Nhap();
    } while (d.KiemTra() == 0);
    do{
        cout << "----------------------------------\n";
        cout << "- Chon hanh dong muon thuc hien :-\n";
        cout << "-      1 : Tang mot ngay.        -\n";
        cout << "-      2 : Giam mot ngay.        -\n";
        cout << "-      0 : Thoat.                -\n";
        cout << "----------------------------------\n";
        cin >> n;
        switch (n)
        {
        case 1:
            d.next();
            d.HienThi();
            break;
        case 2:
            d.pre();
            d.HienThi();
            break;
        default:
            break;
        }
    }while (n != 0);
}

int main(){
    Date d;
    Xuli(d);
}


#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double thuc,ao;
public:

    SoPhuc();
    SoPhuc(double a, double b);
    friend SoPhuc Tong(SoPhuc n, SoPhuc m);
    friend SoPhuc Hieu(SoPhuc n, SoPhuc m);
    void Input(int n);
    void Output(string s);
 
};


SoPhuc::SoPhuc(/* args */)
{
}

SoPhuc::SoPhuc(double a, double b){
    thuc = a;
    ao = b;
}

void SoPhuc::Input(int n){
    cout << "Nhap so thuc " << n << " : ";
    cin >> thuc >> ao;
}

void SoPhuc::Output(string s){
    if (ao > 0){
        cout << s << " la : " << thuc << " + " << ao << "i" << endl;
    }
    if (ao < 0){
        cout << s << " la : " << thuc << " - " << -ao << "i" << endl;
    }
    if (ao == 0){
        cout << s << " la : " << thuc << endl;
    }
    
}

SoPhuc Tong(SoPhuc n , SoPhuc m){
    SoPhuc c;
    c.thuc = n.thuc + m.thuc;
    c.ao = n.ao + m.ao;
    return c;
}

SoPhuc Hieu(SoPhuc n, SoPhuc m){
    SoPhuc c;
    c.thuc = n.thuc - m.thuc;
    c.ao = n.ao - m.ao;
    return c;
}

int main(){
    SoPhuc a, b, c;
    a.Input(1);
    b.Input(2);
    c = Tong(a , b);
    c.Output("Tong");
    c = Hieu(a , b);
    c.Output("Hieu");
}

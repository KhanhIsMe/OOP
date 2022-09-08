#include <iostream>
#include <math.h>

using namespace std;

void Dao( int &a , int &b ){
    int tg;
    tg = a;
    a = b;
    b = tg;
};

void Sort(int a[] , int l ,int r){
    int i, j , x ;
    x = a[(l+r)/2];
    i = l ; j = r ;
    while (i <= j){
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            Dao(a[i],a[j]);
            i++;j--;
        };
    };
    if (i<r) Sort(a,i,r);
    if (l<j) Sort(a,l,j);
};

void Nhap(int a[100][100] , int &n , int &m){
    int i,j;
    cout << "Nhap so hang : " ;
    cin >> n;
    cout << "Nhap so cot : ";
    cin >> m;
    for (i = 0 ; i < n ; i++)
        for (j = 0 ; j < m ; j++){
            cout << "Nhap hang " << i+1 << " cot " << j+1 << " : ";
            cin >> a[i][j];
        };
};

void ChuyenMang(int a[100][100] , int n , int m , int b[]){
    int k = 0, max = a[0][0];
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++){
            if (a[i][j] >= max) max = a[i][j];
            b[k] = a[i][j];
            k++;
        };
    cout << "<------------------------->\n";
    cout << "Phan tu lon nhat cua mang la : " << max << endl;
};

void HienThi(int b[] , int n , int m){
    int k = 0;
    cout << "<-------------------------->\n";
    cout << "Mang da duoc sap xep : " << endl;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cout << b[k] << "  ";
            k++;
        };
        cout << endl;
        cout << endl;
    };
        
};

int main(){
    int a[100][100] ,n ,m , b[10000];
    Nhap(a,n,m);
    ChuyenMang(a,n,m,b);
    Sort(b,0,n*m - 1);
    HienThi(b,n,m);
}

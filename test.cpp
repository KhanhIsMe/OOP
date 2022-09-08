#include <iostream>
#include<string.h>
using namespace std;
int main(){
   char str[25];
   int i;
   cout<<"Nhập vào một chuỗi: ";
   cin>>str;
   for(i=0;i<=strlen(str);i++){
      if(str[i]>=97&&str[i]<=122)
         str[i]=str[i]-32;
   }
   cout<<"Chuỗi sau khi được chuyển thành chữ hoa là "<<str;
}
#include <iostream>
using namespace std;
void giaiptbac1(int a, int b);
int main()
{
    int a;
    int b;

    cout << "pt ax + b" << endl;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;

    giaiptbac1(a,b);


    return 0;
}

void giaiptbac1(int a, int b)
{
    if (b==0)
    {
        if (a==0) cout <<" Vo so nghiem";
        else cout << "x=0";
    }
    else 
    {
        if (a==0) cout << "Vo nghiem";
        else cout << "x= " << (float)-b/a;
    }

}
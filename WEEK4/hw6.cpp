#include <iostream>
using namespace std;
// tổng các chữ số
void tongchuso(int n);


int main()
{
    int n;
    cout << "Nhap chu so n: "; cin >> n;
    tongchuso(n);




    return 0;
}

void tongchuso(int n)
{
    int sum=0;
    int a;
    if (n<0) n=-n;

    while (n>0)
    {
        a=n%10;
        sum=sum+a;
        n=n/10;
    }
    cout << "tong chu so can tim: " << sum << endl;
}


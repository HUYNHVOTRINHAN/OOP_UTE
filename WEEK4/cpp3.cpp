#include <iostream>
using namespace std;
bool kt_nto(int n);
int main()
{
    int n;
    
    cout << "Nhap so n: ";
    cin >> n;

    if (kt_nto(n)) cout <<" Day la so nguyen to";
    else cout << "Day k la so nguyen to";

    return 0;
}

bool kt_nto(int n)
{

    for (int i=0;i<n;i++)
    {
        if (n%i ==0)
        {
            return false;
        }
    }
    return true;

}
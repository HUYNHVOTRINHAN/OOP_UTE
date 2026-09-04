#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool kt_nto(int n);
int main()
{
    int n;
    
    cout << "Nhap so n: ";
    cin >> n;

    if (n<=1) 
    {
        cout << "day k la so nguyen to";
        return 0;
    }

    if (kt_nto(n)) cout <<" Day la so nguyen to";
    else cout << "Day k la so nguyen to";

    return 0;
}

bool kt_nto(int n)
{

    for (int i=0;i<=sqrt(n);i++)
    {
        if (n%i ==0)
        {
            return false;
        }
    }
    return true;

}
#include <iostream>
using namespace std;
// kiểm tra tính đối xứng
bool ktdoixung(int n);




int main()
{
    int a;
    cout << "Nhap so a: "; cin >> a;
    if (ktdoixung(a)) cout << "Day la so doi xung" << endl;
    else cout << "Day k phai la so doi xung" << endl;

    return 0;
}

bool ktdoixung(int n)
{
    int a[100];
    int b=n;
    if (n<0) return false;
    else if (0<= n && n<=9) return true;
    else if ( n>=10)
    {
        int i=0;
        while(b>0)
        {
            a[i]=b%10;
            b=b/10;
            i++;
        }

        bool doixung =true;

        for (int j=0;j<i/2;j++)
        {
            if (a[j] != a[i-1-j])
            {
                doixung =false;
                break;
            }
        }

        return doixung;
    }

    return false;
}


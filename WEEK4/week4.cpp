// #include <iostream>
// #include <string>
// using namespace std; 
// void inputStudent();

// int main()
// {
//     cout << "Hello, C++!" << endl;
//     inputStudent();
//     return 0;
// }

// void inputStudent() {
//     int n = 0; 
//     string names[20];
//     string ids[20];
//     string phones[20]; 

//     cout << "Input the number of students: " << endl;
//     cin >> n; 
//     cin.ignore();

//     if (n > 0) {
//         for (int i = 0; i < n; i++) {
//             cout << "Enter information of student " << i + 1 << endl;

//             cout << "Name: ";
//             getline(cin, names[i]);

//             cout << "ID: ";
//             getline(cin, ids[i]);

//             cout << "Phone: ";
//             getline(cin, phones[i]);
//         }

//         cout << "Number of inputted students: " << n;
//     }
//     else {
//         cout << "The number of students must be more than 0";
//     }
// }



#include <iostream>
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

    for (int i=0;i<n;i++)
    {
        if (n%i ==0)
        {
            return false;
        }
    }
    return true;

}
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct {
    char name[100];
    char ID[50];
    char phonenumber[20];
} SV;

// Nhập thông tin sinh viên
void nhapSV(int n, SV a[]);
// In thông tin sinh viên
void inSV(int n, SV a[]);


int main()
{
    printf("\033[1;33m");
    printf("==============================\n");
    printf("  MEMBERS In ITPR CLASS       \n");
    printf("==============================\n");
    printf("\033[0m");
    cout << endl;
    
    // code here    
    int n;
    SV a[100];

    do {
        printf("So luong hoc sinh: ");
        scanf("%d", &n);
        cin.ignore();
        if (n<= 0) printf("So luong sinh vien phai >0. Vui long nhap lai 😢 \n");
        if (n>=100) printf("So luong sinh vien qua nhieu. Vui long nhap lai 😭\n");
    } while (n<= 0 || n>=100);

    cout << endl;
    
    nhapSV(n,a);
    inSV(n,a);
     

            





    return 0;
}

void nhapSV(int n, SV a[])
{
    for (int i=0;i<n;i++)
    {
        cout << "\033[1;35m" <<  "xxxxxxx Student " << i << " xxxxxxx" << "\033[0m" << endl;
        cout << "Name      : "; cin.getline(a[i].name,100); 
        cout << "Student ID: "; cin.getline(a[i].ID,50); 
        cout << "Phone     : "; cin.getline(a[i].phonenumber,20); 
        cout << endl;
    }
}

void inSV(int n, SV a[])
{
    printf("\033[1;93m");
    printf("===============================================================\n");
    printf("%-6s%-26s%-16s%-15s\n", "No", "Name", "Student ID", "Phone");
    printf("===============================================================\n");
    printf("\033[0m");

    for (int i = 0; i < n; i++)
    {
        printf("%-6d%-26s%-16s%-15s\n",
            i,
            a[i].name,
            a[i].ID,
            a[i].phonenumber);
    }
}


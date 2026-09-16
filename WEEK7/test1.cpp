#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

struct computer {
  char id[50];
  char name[50];
  char hdh[50];
  char username[50];
  char password[50];
  char model[50];
  int year;
};

struct lab {
  char maphong[10];
  char chucnang[20];
};

int j;
lab a[100];

void getlabinfo(int &j) {

  cout << "Nhap so luong phong: ";
  cin >> j;
  cin.ignore();

  for (int i = 0; i < j; i++) {
    cout << "Ma phong " << i << ":";
    cin.getline(a[i].maphong, 10);
    cout << "Chuc nang: ";
    cin.getline(a[i].chucnang, 20);
  }
}

void showlapinfo() {
  for (int i = 0; i < j; i++) {
    cout << "Ma phong " << i << ":" << a[i].maphong << endl;
    cout << "Chuc nang: " << a[i].chucnang << endl << endl;
  }
}

struct account {
  char username[50];
  char password[50];
};

computer DS[100];
int n;

void nhapcomputer(computer DS[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "May " << i << ":" << endl;
    cout << "ID: ";
    cin.getline(DS[i].id, 50);
    cout << "Name: ";
    cin.getline(DS[i].name, 50);
    cout << "HDH: ";
    cin.getline(DS[i].hdh, 50);
    cout << "username: ";
    cin.getline(DS[i].username, 50);
    cout << "password: ";
    cin.getline(DS[i].password, 50);
    cout << "model: ";
    cin.getline(DS[i].model, 50);
    cout << "year: ";
    cin >> DS[i].year;
    cin.ignore();
    cout << endl;
  }
}

void getcomputer_info1(const char a[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(a, DS[i].id) == 0) {
      cout << "May " << i << ":" << endl;
      cout << "ID: " << DS[i].id << endl;
      cout << "Name: " << DS[i].name << endl;
      cout << "HDH: " << DS[i].hdh << endl;
      cout << "username: " << DS[i].username << endl;
      cout << "password: " << DS[i].password << endl;
      cout << "model: " << DS[i].model << endl;
      cout << "year: " << DS[i].year << endl;
      cout << endl;

      return;
    }
  }

  cout << "Khong tim thay may co ID: " << a << endl;
}

computer getcomputer_info2(const char a[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(a, DS[i].id) == 0) {
      return DS[i];
    }
  }

  computer x = {};
  strcpy(x.id, "-1");

  return x;
}

const computer *getcomputer_info3(const computer DS[]) { return DS; }

void getcomputer_info4(const char a[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(a, DS[i].id) == 0) {
      account x;
      strcpy(x.username, DS[i].username);
      strcpy(x.password, DS[i].password);
      cout << "Username: " << x.username << endl;
      cout << " Password: " << x.password << endl;
      return;
    }
  }
  cout << "Khong tim thay may co ID: " << a;
}

int main() {

  getlabinfo(j);
  showlapinfo();

  cout << "Nhap so luong may tinh: ";
  cin >> n;
  cin.ignore(1000, '\n');
  cout << endl;

  nhapcomputer(DS, n);

  cout << "Nhap id may can tim: ";
  char a[50];
  cin.getline(a, 50);
  cout << endl;

  getcomputer_info1(a);

  cout << "\nTim bang getcomputer_info22:\n";

  computer x = getcomputer_info2(a);

  if (strcmp(x.id, "-1") != 0) {
    cout << "ID: " << x.id << endl;
    cout << "Name: " << x.name << endl;
    cout << "HDH: " << x.hdh << endl;
    cout << "username: " << x.username << endl;
    cout << "password: " << x.password << endl;
    cout << "model: " << x.model << endl;
    cout << "year: " << x.year << endl;
  } else {
    cout << "Khong tim thay!" << endl;
  }

  cout << "\n=== DANH SACH TAT CA MAY TINH ===\n";

  const computer *list = getcomputer_info3(DS);

  for (int i = 0; i < n; i++) {
    cout << "May " << i << ":" << endl;
    cout << "ID: " << list[i].id << endl;
    cout << "Name: " << list[i].name << endl;
    cout << "HDH: " << list[i].hdh << endl;
    cout << "Username: " << list[i].username << endl;
    cout << "Password: " << list[i].password << endl;
    cout << "Model: " << list[i].model << endl;
    cout << "Year: " << list[i].year << endl;
    cout << endl;
  }

  getcomputer_info4(a);
  return 0;
}
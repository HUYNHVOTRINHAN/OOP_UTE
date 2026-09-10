#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

// kiểu cấu trúc
typedef struct {
  int no;
  char name[20];
  float price;
  int quantity;
  char type[20];

} Flower;

void nhapflowers(Flower DS[], int N) {
  printf("====== Nhap thong tin hoa ======\n");

  for (int i = 0; i < N; i++) {
    DS[i].no = i + 1;
    cout << "Nhap thong tin hoa " << i + 1 << ": " << endl;
    cout << "Name: ";
    cin.getline(DS[i].name, 20);
    cout << "Price: ";
    cin >> DS[i].price;
    cin.ignore();
    cout << "Quantity: ";
    cin >> DS[i].quantity;
    cin.ignore();
    cout << "Type: ";
    cin.getline(DS[i].type, 20);
    cout << endl;
  }
  cout << endl << endl;
}

int main() {

  Flower flowers[20];
  int N;
  do {
    cout << "Number of flowers: ";
    cin >> N;
    if (N < 1 || N > 20)
      cout << "please enter the suitable number of flowers from 1 to 20!";
  } while (N < 1 || N > 20);

  cin.ignore();
  nhapflowers(flowers, N);

  return 0;
}
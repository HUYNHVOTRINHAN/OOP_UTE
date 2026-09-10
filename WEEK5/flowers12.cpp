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
// câu 2: display all flowers
void inflowers(Flower DS[], int N) {
  printf("====== BANG THONG TIN HOA ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
           DS[i].quantity, DS[i].type);
  }
  cout << endl << endl;
}
// câu 3: find the most expensive flowers
void max_price(Flower DS[], int N) {
  float max = DS[0].price;

  for (int i = 1; i < N; i++) {
    if (DS[i].price > max) {
      max = DS[i].price;
    }
  }

  printf("====== HOA CO GIA CAO NHAT ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    if (DS[i].price == max) {
      printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
             DS[i].quantity, DS[i].type);
    }
  }
}

// câu 3: find the cheapest flowers
void min_price(Flower DS[], int N) {
  float min = DS[0].price;

  for (int i = 0; i < N; i++) {
    if (min > DS[i].price)
      min = DS[i].price;
  }

  printf("====== HOA CO GIA THAP NHAT ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    if (DS[i].price == min) {
      printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
             DS[i].quantity, DS[i].type);
    }
  }
}

// câu 4: đếm xem mỗi loại có bao nhiêu hoa
void cout_eachtype(Flower DS[], int N) {
  for (int i = 0; i < N; i++) {
    int dadem = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        dadem = 1;
        break;
      }
    }

    if (dadem == 1)
      continue;

    int count = 0;
    for (int j = 0; j < N; j++) {
      if (strcmp(DS[j].type, DS[i].type) == 0) {
        count++;
      }
    }
    printf("%-20s : %d\n", DS[i].type, count);
  }
}

// câu 5: search by name
void search_name(Flower DS[], int N) {

  char a[50];
  int found;

  do {
    cout << "Nhap name cua flower: ";
    cin.getline(a, 50);

    found = 0; // giả sử chưa tìm thấy

    for (int i = 0; i < N; i++) {
      if (strcmp(DS[i].name, a) == 0) {
        found = 1;
        break;
      }
    }

    if (found == 0) {
      cout << "Vui long nhap dung ten hoa can tim!\n";
    }

  } while (found == 0);

  for (int i = 0; i < N; i++) {
    if (strcmp(DS[i].name, a) == 0) {
      cout << "Thong tin ten hoa can tim:\n";
      cout << "No: " << DS[i].no << endl;
      cout << "Name: " << DS[i].name << endl;
      cout << "Price: " << DS[i].price << endl;
      cout << "Quantity: " << DS[i].quantity << endl;
      cout << "Type: " << DS[i].type << endl;
    }
  }
}

// câu 6: Generate a simple report
void simple_report(Flower DS[], int N) {
  int total_quantity = 0;
  float sum_price = 0;

  for (int i = 0; i < N; i++) {
    total_quantity = total_quantity + DS[i].quantity;
    sum_price = sum_price + DS[i].price;
  }

  cout << "====== SIMPLE REPORT ======" << endl;
  cout << "Total number of flowers: " << N << endl;
  cout << "Total quantity: " << total_quantity << endl;
  cout << "Average price: " << sum_price / N << endl;
  cout << "Number of flowers in each type:" << endl;

  for (int i = 0; i < N; i++) {
    int daco = 0;

    for (int j = 0; j < i; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        daco = 1;
        break;
      }
    }

    if (daco == 1)
      continue;

    int count = 0;

    for (int j = 0; j < N; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0)
        count++;
    }

    cout << DS[i].type << ": " << count << endl;
  }
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
  inflowers(flowers, N);
  max_price(flowers, N);
  min_price(flowers, N);
  cout_eachtype(flowers, N);
  search_name(flowers, N);
  simple_report(flowers, N);

  return 0;
}
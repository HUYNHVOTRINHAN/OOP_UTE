#include <iostream>
using namespace std;

void addfive(int &x) { x += 5; }

void swapvalues1(int &x, int &y) {
  int tempt = x;
  x = y;
  y = tempt;
}

void changevalue1(int x) { x = 100; }
void changevalue2(int &x) { x = 200; }

int main() {

  int n = 7;
  int &r = n;
  r = 15;
  cout << n << " " << r << endl;

  addfive(n);
  cout << n << endl;

  int a = 4, b = 9;
  swapvalues1(a, b);
  cout << "Swap 2 gia tri: " << endl;
  cout << a << " " << b << endl;

  changevalue1(n);
  cout << "K co tham chieu: " << n << endl;
  changevalue2(n);
  cout << "Co tham chieu: " << n << endl;

  return 0;
}

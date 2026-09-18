#include <iostream>
using namespace std;

void set_first_to_zero(int a[]) { a[0] = 0; }

void increment_all(int (&arr)[4]) {
  for (int i = 0; i < 4; i++) {
    arr[i] += 1;
  }
}

void set_last_to_ten(int &x) { x = 10; }

int main() {
  int num[4] = {1, 2, 3, 4};
  set_first_to_zero(num);
  increment_all(num);
  cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;

  set_last_to_ten(num[3]);
  for (int i = 0; i < 4; i++) {
    cout << num[i] << " ";
  }
  cout << endl;
  return 0;
}
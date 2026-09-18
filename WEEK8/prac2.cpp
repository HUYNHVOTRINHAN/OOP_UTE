#include <iostream>
using namespace std;

void swapvalues1(int &x, int &y) {
  int tempt = x;
  x = y;
  y = tempt;
}

void swapvalues2(int x, int y) {
  int tempt = x;
  x = y;
  y = tempt;
}

int main() {

  int a = 5, b = 10;
  cout << "Before: a= " << a << ", b= " << b << endl;
  swapvalues2(a, b);
  cout << "K co tham chieu:" << endl;
  cout << "After: a= " << a << ", b=" << b << endl;
  // sau khi chạy thì 2 biến k hề đổi giá trị cho nhau (giốn trước before)
  // nguyên nhân:
  // khi ko truyền tham chiếu thì:
  // bộ nhớ 1: tempt = a =5;
  // bộ nhớ a: k truyền tham chiếu, về bản chất chỉ xử lý giá trị trong hàm, chứ
  // a sau hàm =5 (mặc dù x=10) (x và a khác địa chỉ) bộ nhớ b: k truyền tham
  // chiếu, về bản chất chỉ xử lý giá trị trong hàm, chứ b sau hàm =10 (mặc dù
  // y=5) (y và b khác đia chỉ)
  swapvalues1(a, b);
  cout << "Co tham chieu:" << endl;
  cout << "After: a= " << a << ", b= " << b << endl;
  // sau khi chạy thì 2 biến đổi giá trị cho nhau
  // nguyên nhân:
  // khi truyền tham chiếu thì:
  // bộ nhớ 1: tempt =x=a=5;
  // bộ nhớ a: a=b=10; (giá trị tại địa chỉ chung (x và a chung địa chỉ) bi thay
  // đổi) bộ nhớ b: b=a=5; (giá trị tại địa chỉ chung (y và b chugn địa chỉ) bị
  // thay đổi)
}

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

int main() {

  string s1 = "Hello";
  string s2 = "C++";
  cout << s1 << endl;
  cout << s2 << endl;

  string name;
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Hello, " << name << "!" << endl;

  string first = "Hello";
  string second = "World";
  string message = first + " " + second + "!";
  cout << message << endl;

  string s = "Hello c++";
  cout << "length: " << s.length() << endl;

  cout << "First character : " << s[0] << endl;
  cout << "Second character: " << s[1] << endl;

  string text = "I love c++!";
  size_t pos = s.find("chao");

  if (pos != string::npos) {
    cout << "Tim thay tai vi tri: " << pos; // In ra 4
  } else {
    cout << "Khong tim thay!";
  }

  cout << endl;

  string part = text.substr(6, 3);
  cout << part << endl;

  string b1 = "apple";
  string b2 = "Apple";
  if (b1.compare(b2) == 0) // kết quả ra khác vì có phân bt chữ hoa, thường
    cout << "The strings are equal." << endl;
  else
    cout << "the strings are different." << endl;

  return 0;
}
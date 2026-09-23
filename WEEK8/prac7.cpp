#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void addExclaim(string &str) { str += "!!"; }

void swapStr(string &a, string &b) {
  string temp = a;
  a = b;
  b = temp;
}

void changeFirstChar(string &str) { str[0] = 'J'; }

void toUpperCase(string &str) {
  for (char &c : str) {
    c = toupper(c);
  }
}

int main() {
  string s = "Hello";
  string &r = s;
  r += " World";
  cout << s << endl;
  cout << r << endl;

  string msg = "Good Day";
  addExclaim(msg);
  cout << msg << endl;

  string x = "cat";
  string y = "dog";
  swapStr(x, y);
  cout << x << " " << y << endl;

  string name = "python";
  changeFirstChar(name);
  cout << name << endl;

  string s2 = "Hello";
  string r2 = s2;
  string &ref = s2;
  r2 += "!!!";
  ref += "???";
  cout << "s: " << s2 << endl;
  cout << "r: " << r2 << endl;
  cout << "ref: " << ref << endl;

  string text = "c++ is fun";
  toUpperCase(text);
  cout << text << endl;

  return 0;
}

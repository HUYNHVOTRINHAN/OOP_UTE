#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1 = "";
  string s2 = "Hi";

  cout << s1.empty() << endl;
  cout << s2.empty() << endl;

  string text = "I love c++!";
  size_t pos = text.find("c++");

  if (pos != string::npos) {
    cout << "Tim thay tai vi tri: " << pos << endl;
  } else {
    cout << "Khong tim thay!" << endl;
  }

  string s = "Hello World";
  string part1 = s.substr(0, 5);
  string part2 = s.substr(6, 5);

  cout << part1 << endl;
  cout << part2 << endl;

  s.append(" C++");
  cout << s << endl;

  cout << s.insert(5, ", C++") << endl;

  cout << s.erase(5, 5) << endl;

  cout << s.replace(12, 3, "Java") << endl;

  return 0;
}
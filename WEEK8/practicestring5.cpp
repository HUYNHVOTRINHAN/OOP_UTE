#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, toInsert;
  int pos1;
  getline(cin, s1);
  getline(cin, toInsert);
  cin >> pos1;
  cin.ignore();
  s1.insert(pos1, toInsert);
  cout << s1 << endl;

  string text2, sub2;
  getline(cin, text2);
  getline(cin, sub2);
  size_t pos2 = text2.find(sub2);
  if (pos2 != string::npos) {
    cout << "Position: " << pos2 << endl;
  } else {
    cout << "Not found" << endl;
  }

  string text3;
  getline(cin, text3);
  int countAll = text3.length();
  int countWithoutSpaces = 0;
  for (char c : text3) {
    if (c != ' ') {
      countWithoutSpaces++;
    }
  }
  cout << countAll << " (with spaces)" << endl;
  cout << countWithoutSpaces << " (without spaces)" << endl;

  string text4, oldSub, newSub;
  getline(cin, text4);
  getline(cin, oldSub);
  getline(cin, newSub);
  size_t pos4 = text4.find(oldSub);
  if (pos4 != string::npos) {
    text4.replace(pos4, oldSub.length(), newSub);
  }
  cout << text4 << endl;

  string text5;
  int start5, len5;
  getline(cin, text5);
  cin >> start5 >> len5;
  cout << text5.substr(start5, len5) << endl;

  return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
  string fullName, studentId, email, hometown;
  getline(cin, fullName);
  getline(cin, studentId);
  getline(cin, email);
  getline(cin, hometown);

  cout << "===== STUDENT PROFILE =====" << endl;
  cout << "Full name : " << fullName << endl;
  cout << "Student ID: " << studentId << endl;
  cout << "Email     : " << email << endl;
  cout << "Hometown  : " << hometown << endl;
  cout << "===========================" << endl;

  string name2;
  getline(cin, name2);
  cout << "Hello, " << name2 << "!" << endl;
  cout << "Welcome to C++ programming!" << endl;

  string name3;
  getline(cin, name3);
  string initials = "";
  bool newWord = true;
  for (char c : name3) {
    if (c != ' ') {
      if (newWord) {
        if (!initials.empty()) {
          initials += '.';
        }
        if (c >= 'a' && c <= 'z') {
          c = c - ('a' - 'A');
        }
        initials += c;
        newWord = false;
      }
    } else {
      newWord = true;
    }
  }
  cout << "Initials: " << initials << endl;

  string sentence, word;
  getline(cin, sentence);
  getline(cin, word);
  size_t pos = sentence.find(word);
  if (pos != string::npos) {
    cout << "The word \"" << word << "\" is found at position " << pos << "." << endl;
  } else {
    cout << "The word \"" << word << "\" is not found." << endl;
  }

  string name5;
  int birthYear;
  getline(cin, name5);
  cin >> birthYear;
  string username = "";
  for (char c : name5) {
    if (c != ' ') {
      if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
      }
      username += c;
    }
  }
  username += to_string(birthYear);
  cout << "Username: " << username << endl;

  return 0;
}

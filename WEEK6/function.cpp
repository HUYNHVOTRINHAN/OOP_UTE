#include <iostream>
using namespace std;

// step1
void showWelcome() {
  cout << "=================================" << endl;
  cout << "   WELCOME TO STUDENT MANAGER!   " << endl;
  cout << "=================================" << endl;
}
void showMenu() {
  cout << "======= MENU ========" << endl;
  cout << "1. Display students" << endl
       << "2. Show statistics" << endl
       << "3. Exit" << endl;
  cout << "=====================" << endl;
}
int main() {

  showWelcome();
  cout << "Let's et started!" << endl;

  showMenu();

  return 0;
}
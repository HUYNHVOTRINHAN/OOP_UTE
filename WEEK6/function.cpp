#include <iostream>
#include <string.h>
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
void showStudentName(char name[50]) {
  cout << "Hello, " << name << "!" << endl;
  cout << "Welcome to our class!" << endl;
}
void showStudentID(char ID[50]) {
  cout << "Enter your Student ID: ";
  cin.getline(ID, 50);
  cout << "Student ID: " << ID << endl;
}

int main() {

  showWelcome();
  cout << "Let's get started!" << endl;

  showMenu();

  char name[50];
  cout << "Enter your name: ";
  cin.getline(name, 50);
  showStudentName(name);

  char ID[50];
  showStudentID(ID);

  return 0;
}
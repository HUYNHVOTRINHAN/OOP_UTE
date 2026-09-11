#include <cstdlib>
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
void printStudentInfo(char name[50], int id) {
  cout << "----------------------" << endl;
  cout << "Name: " << name << endl;
  cout << "ID  : " << id << endl;
  cout << "----------------------" << endl;
}
void showScore(char name[50], double &score) {
  cout << "Nhap diem: ";
  cin >> score;
  cin.ignore();

  cout << "Student: " << name << endl;
  cout << "Score  : " << score << endl;
  cout << "Keep going!" << endl;
}
double calculateAverage(double score1, double score2) {
  double sum = score1 + score2;
  double avg = sum / 2.0;
  return avg;
}
int maxValue(int a, int b) {
  if (a < b)
    return b;
  else
    return a;
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

  int id = atoi(ID);
  printStudentInfo(name, id);

  double score;
  showScore(name, score);

  double math, english;
  cout << "Enter math score   : ";
  cin >> math;
  cout << "Enter English score: ";
  cin >> english;
  double avg = calculateAverage(math, english);
  cout << "Avg score = " << avg << endl;

  cout << "Mon co diem lon hon: " << maxValue(math, english) << endl;

  return 0;
}
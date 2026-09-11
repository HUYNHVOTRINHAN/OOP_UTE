#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct ScoreInfo {
  double sum;
  double avg;
  int count;
  double maxScore;
  double minScore;
};

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

// step2
void showStudentName(char name[50]) {
  cout << "Hello, " << name << "!" << endl;
  cout << "Welcome to our class!" << endl;
}
void showStudentID(char ID[50]) {
  cout << "Enter your Student ID: ";
  cin.getline(ID, 50);
  cout << "Student ID: " << ID << endl;
}

// step3
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

// step4
double calculateavg(double score1, double score2) {
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

// step5
ScoreInfo analyzeScores(double scores[], int n) {
  ScoreInfo result;

  result.sum = 0;
  result.count = n;

  if (result.count == 0) {
    result.avg = 0;
    result.maxScore = 0;
    result.minScore = 0;
    return result;
  }

  result.minScore = scores[0];
  result.maxScore = scores[0];

  for (int i = 0; i < n; i++) {
    result.sum += scores[i];

    if (scores[i] > result.maxScore)
      result.maxScore = scores[i];

    if (scores[i] < result.minScore)
      result.minScore = scores[i];
  }

  result.avg = result.sum / result.count;

  return result;
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
  double avg = calculateavg(math, english);
  cout << "Avg score = " << avg << endl;

  cout << "Mon co diem lon hon: " << maxValue(math, english) << endl;

  double scores[5] = {8.5, 7.0, 9.2, 6.5, 10.0};

  ScoreInfo result = analyzeScores(scores, 5);

  cout << "Sum: " << result.sum << endl;
  cout << "avg: " << result.avg << endl;
  cout << "Max: " << result.maxScore << endl;
  cout << "Min: " << result.minScore << endl;

  return 0;
}
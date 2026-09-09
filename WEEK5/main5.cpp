#include <iostream>
#include <stdio.h>
using namespace std;

// tim số lớn/ bé nhất trong mảng dương
float max_mang(float a[], int n);
float min_mang(float a[], int n);
float maxnhi_mang(float a[], int n);

int main() {

  int n;
  do {

    cout << "how many students? ";
    cin >> n;
    cout << endl;

    if (n < 2 || n > 20) {
      cout << "invalid number of students!\n";
      cout << "Please enter a number from 2 to 20\n";
    }

  } while (n < 2 || n > 20);

  float a[100];

  for (int i = 0; i < n; i++) {
    cout << "Enter score for student " << i + 1 << ": ";

    do {
      cin >> a[i];
      if (a[i] < 0 || a[i] > 10)
        cout << "Invalid score! Pleasee enter a value from 0 to 10: ";
    } while (a[i] < 0 || a[i] > 10);
  }

  cout << endl;
  cout << "==== STUDENT SCORES ====\n";
  cout << endl;

  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f\n", i + 1, a[i]);
  }

  cout << endl;
  cout << "==== RESULTS ====\n";
  cout << endl;

  int dem = 0;
  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f ", i + 1, a[i]);
    if (a[i] >= 5) {
      cout << "-----> PASS\n";
      dem++;
    } else
      cout << "-----> FAIL\n";
  }

  cout << endl;
  cout << "==== STATISTICS ====\n";
  cout << endl;

  cout << "Passed : " << dem << " students\n";
  cout << "Failed : " << n - dem << " students\n";
  cout << "Pass rate: " << dem * 100 / n << "%" << endl;

  cout << endl;
  printf("Highest score: %.1f\n", max_mang(a, n));
  printf("Second Highest score: %.1f\n", maxnhi_mang(a, n));
  printf("Lowest score : %.1f\n", min_mang(a, n));

  cout << endl;
  cout << "===== CLASSIFICATION =====\n";
  cout << endl;

  int dem1 = 0;
  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f -> ", i + 1, a[i]);
    if (a[i] >= 9.0) {
      cout << "Excellent\n";
      dem1++;
    } else if (a[i] >= 8.0) {
      cout << "Very Good\n";
    } else if (a[i] >= 6.5) {
      cout << "Good\n";
    } else if (a[i] >= 5.0) {
      cout << "Average\n";
    } else {
      cout << "Fail\n";
    }
  }

  cout << endl;
  cout << "Number of excellent students: " << dem1 << endl << endl;

  int c, d;
  cout << "Enter minium score: ";
  cin >> c;
  cout << "Enter maxium score: ";
  cin >> d;
  cout << endl;

  int dem2 = 0;
  for (int i = 0; i < n; i++) {
    if (c <= a[i] && a[i] <= d)
      dem2++;
  }

  cout << "Students in range: " << dem2++ << endl << endl;

  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  float average = sum / n;

  cout << "Average score: " << average << endl;

  cout << "Student above average: " << endl;
  for (int i = 0; i < n; i++) {
    if (a[i] > average)
      printf("Student %d: %.1f\n", i + 1, a[i]);
  }

  cout << endl << endl;

  float e;
  cout << "Enter score to search: ";
  cin >> e;
  cout << endl;

  cout << "Found at: \n";
  for (int i = 0; i < n; i++) {
    if (a[i] == e)
      cout << "Student " << i + 1 << endl;
  }

  cout << endl << endl;

  float f;
  cout << "Enter score: ";
  cin >> f;
  float dem3 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == f)
      dem3++;
  }
  cout << "Score " << f << " appears " << dem3 << " times" << endl;

  cout << endl << endl;
  cout << "First failing student: " << endl;

  int dem4 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 5) {
      cout << "Student " << i + 1 << " : " << a[i] << endl;
      dem4++;
      break;
    }
  }

  if (dem4 == 0)
    cout << "All students pass!" << endl;

  cout << endl << endl;

  for (int i = 0; i < n; i++) {
    if (a[i + 1] > a[i])
      cout << "Student " << i + 2 << " improved compared to Student " << i + 1
           << endl;
  }

  cout << endl << endl;

  float k[100];
  int dem5;
  int j = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] >= 5)
      dem5++;
    else {
      k[j] = dem5;
      j++;
      dem5 = 0;
    }
  }

  cout << "Longest pass streak: " << (int)max_mang(k, n) << " students" << endl
       << endl;

  int h[10] = {0};
  for (int i = 0; i < n; i++) {
    if (0 <= a[i] && a[i] < 5)
      h[0]++;
    else if (5 <= a[i] && a[i] < 6.5)
      h[1]++;
    else if (6.5 <= a[i] && a[i] < 8)
      h[2]++;
    else if (8 <= a[i] && a[i] < 9)
      h[3]++;
    else if (9 <= a[i] && a[i] <= 10)
      h[4]++;
  }


    cout << "===== SCORE DISTRIBUTION =====\n";
    cout << "0 - <5    : ";
    for (int v = 1; v <= h[0]; v++)
      cout << "*";
    cout << "         " << h[0] << endl;
    cout << "5 - <6.5  : ";
    for (int v = 1; v <= h[1]; v++)
      cout << "*";
    cout << "         " << h[1] << endl;
    cout << "6.5 - <8  : ";
    for (int v = 1; v <= h[2]; v++)
      cout << "*";
    cout << "         " << h[2] << endl;
    cout << "8 - <9    : ";
    for (int v = 1; v <= h[3]; v++)
      cout << "*";
    cout << "         " << h[3] << endl;
    cout << "9 - <10   : ";
    for (int v = 1; v <= h[4]; v++)
      cout << "*";
    cout << "         " << h[4] << endl;

  return 0;
}

// tim số lớn nhất trong mảng
float max_mang(float a[], int n) {
  float max = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

float maxnhi_mang(float a[], int n) {

  float maxnhat = max_mang(a, n);
  float maxnhi = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] > maxnhi && a[i] != maxnhat) {
      maxnhi = a[i];
    }
  }

  return maxnhi;
}

// tim số bé nhất trong mảng
float min_mang(float a[], int n) {
  float min = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
}

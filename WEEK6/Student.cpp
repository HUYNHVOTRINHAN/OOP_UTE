#include <iostream>
#include <stdio.h>
using namespace std;

// các hàm phụ
float max_mang(float a[], int n) {
  float max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}
float min_mang(float a[], int n) {
  float min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
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

int number_students() {
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
  return n;
}
void input_score(float a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Enter score for student " << i + 1 << ": ";
    do {
      cin >> a[i];
      if (a[i] < 0 || a[i] > 10)
        cout << "Invalid score! Please enter a value from 0 to 10: ";
    } while (a[i] < 0 || a[i] > 10);
  }
}
void print_score(float a[], int n) {
  cout << endl;
  cout << "==== STUDENT SCORES ====\n\n";
  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f\n", i + 1, a[i]);
  }
}
void pass_fail(float a[], int n) {
  cout << endl;
  cout << "==== RESULTS ====\n\n";
  int dem = 0;
  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f ", i + 1, a[i]);
    if (a[i] >= 5) {
      cout << "-----> PASS\n";
      dem++;
    } else {
      cout << "-----> FAIL\n";
    }
  }
}
void statistics(float a[], int n) {
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 5)
      dem++;
  }
  cout << endl;
  cout << "==== STATISTICS ====\n\n";
  cout << "Passed : " << dem << " students\n";
  cout << "Failed : " << n - dem << " students\n";
  cout << "Pass rate: " << dem * 100 / n << "%\n\n";
  printf("Highest score: %.1f\n", max_mang(a, n));
  printf("Lowest score : %.1f\n", min_mang(a, n));
}
void classification(float a[], int n) {
  cout << endl;
  cout << "===== CLASSIFICATION =====\n\n";
  for (int i = 0; i < n; i++) {
    printf("Student %d: %.1f -> ", i + 1, a[i]);
    if (a[i] >= 9.0) {
      cout << "Excellent\n";
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
}

// câu 1
void count_excellent(float a[], int n) {
  int dem1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 9.0) {
      dem1++;
    }
  }
  cout << endl;
  cout << "Number of excellent students: " << dem1 << endl << endl;
}
// câu 2
void count_score_range(float a[], int n) {
  float c, d;
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
  cout << "Students in range: " << dem2 << endl << endl;
}
// câu 3
void above_average(float a[], int n) {
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
}
// câu 4
void second_highest(float a[], int n) {
  printf("Second Highest score: %.1f\n", maxnhi_mang(a, n));
  cout << endl << endl;
}
// câu 5
void search_score(float a[], int n) {
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
}

int main() {

  float a[100];
  int n;
  n = number_students();

  input_score(a, n);
  print_score(a, n);
  pass_fail(a, n);
  statistics(a, n);
  classification(a, n);

  count_excellent(a, n);
  count_score_range(a, n);
  above_average(a, n);
  second_highest(a,n);
  search_score(a,n);


  return 0;
}
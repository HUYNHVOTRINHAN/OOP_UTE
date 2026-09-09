#include <iostream>
using namespace std;
int main() {

  int n;
  do {

    cout << "how many students ";
    cin >> n;
    cout << endl;

    if (n < 2 || n > 20) {
      cout << "invalid number of students!\n";
      cout << "Please enter a number from 2 to 20\n";
    }

  } while (n < 2 || n > 20);

  
  float a[100];
  a[0]=0;

    for (int i=1;i<=n;i++)
    {
        cout << "Enter score for student " << i << ": ";
        
        do {
            cin >> a[i];
            if (a[i]<0 ||a[i]>10) cout <<"Invalid score! Pleasee enter a value from 0 to 10: ";
        } while (a[i]<0 || a[i]>10);
    }

    cout << "==== STUDENT SCORES ====\n";

    for (int i=1;i<=n;i++)
    {
        cout << "Student " << i << ": " << a[i];
    }

  return 0;
}
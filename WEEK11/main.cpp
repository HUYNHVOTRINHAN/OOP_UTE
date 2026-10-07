#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string toLower(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:
    Date() {
        year = 2000;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
    }

    Date(int y, int m, int d, int h, int mi, int s) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = mi;
        second = s;
    }

    void input() {
        cout << "Nhap nam: ";
        cin >> year;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap gio: ";
        cin >> hour;
        cout << "Nhap phut: ";
        cin >> minute;
        cout << "Nhap giay: ";
        cin >> second;
        cin.ignore();
    }

    void display() const {
        cout << year << "/"
             << (month < 10 ? "0" : "") << month << "/"
             << (day < 10 ? "0" : "") << day << " "
             << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second;
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    Student(string name, string address) {
        this->name = name;
        this->address = address;
        birthdate = Date();
        cccd = "";
    }

    Student(string name, string address, Date birthdate) {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        cccd = "";
    }

    Student(string name, string address, Date birthdate, string cccd) {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        this->cccd = cccd;
    }

    void setStudentInfo() {
        cout << "Nhap ho ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap ngay gio sinh:\n";
        birthdate.input();
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    void displayStudentInfo() const {
        cout << "Ho ten   : " << name << "\n";
        cout << "Dia chi  : " << address << "\n";
        cout << "Ngay sinh: ";
        birthdate.display();
        cout << "\nCCCD     : " << cccd << "\n";
        cout << "---------------------------------\n";
    }

    string getName() const { return name; }
    string getAddress() const { return address; }
    Date getBirthdate() const { return birthdate; }
    string getCccd() const { return cccd; }

    int getAge(int currentYear = 2026) const {
        return currentYear - birthdate.getYear();
    }
};

Student getStudent(Student list[], int n, string cccd) {
    for (int i = 0; i < n; i++) {
        if (list[i].getCccd() == cccd) {
            return list[i];
        }
    }
    return Student();
}

Student getStudentInfo(Student list[], int n, string cccd) {
    return getStudent(list, n, cccd);
}

Student* getStudents(Student list[], int n, string name, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        if (toLower(list[i].getName()).find(toLower(name)) != string::npos) {
            count++;
        }
    }

    if (count == 0) return nullptr;

    Student* result = new Student[count];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (toLower(list[i].getName()).find(toLower(name)) != string::npos) {
            result[idx++] = list[i];
        }
    }
    return result;
}

Student* getStudentsbyAge(Student list[], int n, int age, int &count, int currentYear = 2026) {
    count = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].getAge(currentYear) == age) {
            count++;
        }
    }

    if (count == 0) return nullptr;

    Student* result = new Student[count];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].getAge(currentYear) == age) {
            result[idx++] = list[i];
        }
    }
    return result;
}

int main() {
    Student student1;
    Student student2("huong");
    Student student3("", "vo van ngan");
    Student student4("Nguyen Van An", "123 Vo Van Ngan", Date(2004, 5, 15, 8, 30, 0), "079204001234");
    Student student5("Tran Thi Huong", "Thu Duc", Date(2004, 9, 20, 14, 0, 0), "079204005678");

    Student students[100];
    int n = 5;
    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    students[3] = student4;
    students[4] = student5;

    cout << "===== DANH SACH SINH VIEN BAN DAU =====\n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        students[i].displayStudentInfo();
    }

    cout << "\n===== TIM SINH VIEN THEO CCCD (079204001234) =====\n";
    Student foundByCccd = getStudent(students, n, "079204001234");
    if (!foundByCccd.getCccd().empty()) {
        foundByCccd.displayStudentInfo();
    } else {
        cout << "Khong tim thay sinh vien!\n";
    }

    cout << "\n===== TIM SINH VIEN THEO TEN (\"huong\") =====\n";
    int countName = 0;
    Student* foundByName = getStudents(students, n, "huong", countName);
    if (foundByName != nullptr) {
        for (int i = 0; i < countName; i++) {
            foundByName[i].displayStudentInfo();
        }
        delete[] foundByName;
    } else {
        cout << "Khong tim thay sinh vien nao!\n";
    }

    cout << "\n===== TIM SINH VIEN THEO TUOI (22 TUOI) =====\n";
    int countAge = 0;
    Student* foundByAge = getStudentsbyAge(students, n, 22, countAge);
    if (foundByAge != nullptr) {
        for (int i = 0; i < countAge; i++) {
            foundByAge[i].displayStudentInfo();
        }
        delete[] foundByAge;
    } else {
        cout << "Khong tim thay sinh vien nao!\n";
    }
//
    return 0;
}
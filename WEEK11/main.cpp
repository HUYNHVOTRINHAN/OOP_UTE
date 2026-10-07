#include <iostream>
#include <string>
#include <vector>
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

    Date(int y, int m, int d, int h = 0, int mi = 0, int s = 0) {
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

    static Student getStudentInfo(const vector<Student>& list, string cccd) {
        for (size_t i = 0; i < list.size(); i++) {
            if (list[i].getCccd() == cccd) {
                return list[i];
            }
        }
        return Student();
    }

    static vector<Student> getStudents(const vector<Student>& list, string name) {
        vector<Student> result;
        for (size_t i = 0; i < list.size(); i++) {
            if (toLower(list[i].getName()).find(toLower(name)) != string::npos) {
                result.push_back(list[i]);
            }
        }
        return result;
    }

    static vector<Student> getStudentsbyAge(const vector<Student>& list, int age, int currentYear = 2026) {
        vector<Student> result;
        for (size_t i = 0; i < list.size(); i++) {
            if (list[i].getAge(currentYear) == age) {
                result.push_back(list[i]);
            }
        }
        return result;
    }
};

Student getStudent(const vector<Student>& list, string cccd) {
    return Student::getStudentInfo(list, cccd);
}

Student getStudentInfo(const vector<Student>& list, string cccd) {
    return Student::getStudentInfo(list, cccd);
}

vector<Student> getStudents(const vector<Student>& list, string name) {
    return Student::getStudents(list, name);
}

vector<Student> getStudentsbyAge(const vector<Student>& list, int age, int currentYear = 2026) {
    return Student::getStudentsbyAge(list, age, currentYear);
}

int main() {
    Student student1;
    Student student2("huong");
    Student student3("", "vo van ngan");
    Student student4("Nguyen Van An", "123 Vo Van Ngan", Date(2004, 5, 15, 8, 30, 0), "079204001234");
    Student student5("Tran Thi Huong", "Thu Duc", Date(2004, 9, 20, 14, 0, 0), "079204005678");

    vector<Student> students;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);

    cout << "===== DANH SACH SINH VIEN BAN DAU =====\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        students[i].displayStudentInfo();
    }

    cout << "\n===== TIM SINH VIEN THEO CCCD (079204001234) =====\n";
    Student foundByCccd = getStudent(students, "079204001234");
    if (!foundByCccd.getCccd().empty()) {
        foundByCccd.displayStudentInfo();
    } else {
        cout << "Khong tim thay sinh vien!\n";
    }

    cout << "\n===== TIM SINH VIEN THEO TEN (\"huong\") =====\n";
    vector<Student> foundByName = getStudents(students, "huong");
    for (size_t i = 0; i < foundByName.size(); i++) {
        foundByName[i].displayStudentInfo();
    }

    cout << "\n===== TIM SINH VIEN THEO TUOI (22 TUOI) =====\n";
    vector<Student> foundByAge = getStudentsbyAge(students, 22);
    for (size_t i = 0; i < foundByAge.size(); i++) {
        foundByAge[i].displayStudentInfo();
    }

    return 0;
}
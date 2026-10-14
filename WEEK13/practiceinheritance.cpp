#include <iostream>
using namespace std;

class people {
    private:
        string cccd;
        string name;
        string address;
    public:

    //constructor k tham số - gán giá trị mặc định
    people() {
        cccd= "000000000000";
        name= "Unknown";
        address= "Unknown";
    }

    //constructor có tham số
    people(string c, string n, string a) {
        cccd=c;
        name=n;
        address=a;
    }

    string getCccd() const {return cccd;}
    string getName() const {return name;}
    string getAddress() const {return address;}
    void setCccd(string c) {cccd=c;}
    void setName(string n) {name=n;}
    void setAddress(string a) {address=a;} 

    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "------------------------" << endl;
    }
};

class student : public people {
    private:
        string mssv;
        int yearEntrance;
    public:
        // constructor k tham số - gán giá trị mặc định
        student() : people () {
            mssv="N/A";
            yearEntrance=0;
        }
        //constructor có tham số
        student(string c, string n, string a, string m, int y) : people(c,n,a) {
            mssv=m;
            yearEntrance=y;
        }

        //getter, setters

        string getMssv() const {return mssv;}
        int getYearEntrance() const {return yearEntrance;}
        void setMssv(string m) {mssv =m;}
        void setYearEntrance(int y) {yearEntrance=y;}

        void displayInfo() const {
            cout << "CCCD: " << getCccd() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "MSSV: " << mssv << endl;
            cout << "Year Entrance: " << yearEntrance << endl;
            cout << "------------------------" << endl;
        }
};

class FIEStudent : public student {
    private:
        int credits;
    public:
        // Constructor không tham số - gán giá trị mặc định
        FIEStudent() : student() {
            credits = 0;
        }

        // Constructor có tham số
        FIEStudent(string c, string n, string a,
                   string m, int y, int cr)
            : student(c, n, a, m, y) {
            credits = cr;
        }

        // getters, setters
        int getCredits() const { return credits; }
        void setCredits(int cr) { credits = cr; }

        // Hàm hiển thị thông tin
        void displayInfo() const {
            cout << "CCCD: " << getCccd() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "MSSV: " << getMssv() << endl;
            cout << "Year Entrance: " << getYearEntrance() << endl;
            cout << "Credits: " << credits << endl;
            cout << "------------------------" << endl;
        }
};


int main() {
    people p1;
    people p2("079123456789", "Nguyen Van A", "Ho Chi Minh");

    student s1;
    student s2("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023);

    FIEStudent f1;
    FIEStudent f2("079987654321", "Le Minh C", "Da Nang",
                  "FIE2023001", 2023, 120);

    cout << "---- Thong tin doi tuong p1 (People - mac dinh) ----" << endl;
    p1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong p2 (People - co tham so) ----" << endl;
    p2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s1 (Student - mac dinh) ----" << endl;
    s1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s2 (Student - co tham so) ----" << endl;
    s2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f1 (FIEStudent - mac dinh) ----" << endl;
    f1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f2 (FIEStudent - co tham so) ----" << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
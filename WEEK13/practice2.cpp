#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
private:
    string cccd;
    string sdt;
    string address;
public:
    Employee() {
        cccd="";
        sdt="";
        address="";
    }

    Employee(string c, string p, string a) {
        cccd=c;
        sdt=p;
        address=a;
    }

    virtual ~Employee() {}

    string getCCCD() const {return cccd;}
    string getSDT() const {return sdt;}
    string getAddress() const {return address;};

    void setCCCD(string c) {cccd =c;}
    void setSDT(string p) {sdt=p;}
    void setAddress(string a) {address=a;}

    virtual double tinhLuong() const {
        return 0.0;
    }

    virtual void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;
public:
    //constructor k tham số
    HourlyEmployee() : Employee() {
        soGioLamViec=0;
        donGia=0.0;
    }

    //constructor có tham số
    HourlyEmployee(string c, string p, string a, int soGio, double dg) : Employee(c, p, a) {
        soGioLamViec=soGio;
        donGia=dg;
    }

    //getters
    int getSoGioLamViec() const {return soGioLamViec;}
    double getDonGia() const {return donGia;}
    //setters
    void setSoGioLamViec(int h) {soGioLamViec=h;}
    void setDonGia(double dg) {donGia=dg;}

    
    double tinhLuong() const {
        return soGioLamViec * donGia;
    }

   
    void displayInfo() const {
        Employee::displayInfo(); // goi ham lop cha
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;
public:
    //constructor k tham số
    MonthlyEmployee() : Employee () {
        luongCoBan=0.0;
        phuCap=0.0;
        heSoThuong=0.0;
    }
    //constructor có tham số
    MonthlyEmployee(string c, string p, string a, double lcb, double pc, double hs) : Employee(c,p,a) {
        luongCoBan =lcb;
        phuCap=pc;
        heSoThuong=hs;
    }

    //getters
    double getLuongCoBan() const {return luongCoBan;}
    double getPhuCap() const {return phuCap;}
    double getHeSoTHuong() const {return heSoThuong;}
    //setters
    void setLuongCoBan(double lcb) {luongCoBan=lcb;}
    void setPhuCap(double pc) {phuCap=pc;}
    void setHeSoThuong(double hs) {heSoThuong=hs;}

   
    double tinhLuong() const {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

   
    void displayInfo() const {
        Employee::displayInfo(); // goi ham lop cha
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so thuong: " << heSoThuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};


int main() {
    Employee e1;
    Employee e2("001122334455", "0912345678", "Ha Noi");

    HourlyEmployee h1;
    HourlyEmployee h2("079123456780", "0901002004", "Hai Phong", 120, 60000);

    MonthlyEmployee m1;
    MonthlyEmployee m2("079987654322", "0903004006", "Can Tho", 20000000, 3000000, 1.5);

    cout << "--- Employee e1 ---" << endl;
    e1.displayInfo();
    cout << endl;

    cout << "--- Employee e2 ---" << endl;
    e2.displayInfo();
    cout << endl;

    cout << "--- HourlyEmployee h1 ---" << endl;
    h1.displayInfo();
    cout << endl;

    cout << "--- HourlyEmployee h2 ---" << endl;
    h2.displayInfo();
    cout << endl;

    cout << "--- MonthlyEmployee m1 ---" << endl;
    m1.displayInfo();
    cout << endl;

    cout << "--- MonthlyEmployee m2 ---" << endl;
    m2.displayInfo();
    cout << endl;

    vector<Employee*> danhSach;
    danhSach.push_back(&h1);
    danhSach.push_back(&h2);
    danhSach.push_back(&m1);
    danhSach.push_back(&m2);

    double tongLuong = 0;
    for (Employee* emp : danhSach) {
        tongLuong += emp->tinhLuong();
    }
    cout << "=== TONG QUY LUONG ===" << endl;
    cout << "Tong luong: " << tongLuong << endl << endl;

    Employee* maxEmp = danhSach[0];
    Employee* minEmp = danhSach[0];
    for (Employee* emp : danhSach) {
        if (emp->tinhLuong() > maxEmp->tinhLuong()) {
            maxEmp = emp;
        }
        if (emp->tinhLuong() < minEmp->tinhLuong()) {
            minEmp = emp;
        }
    }
    cout << "=== NHAN VIEN CO LUONG CAO NHAT ===" << endl;
    maxEmp->displayInfo();
    cout << endl;

    cout << "=== NHAN VIEN CO LUONG THAP NHAT ===" << endl;
    minEmp->displayInfo();
    cout << endl;

    int demHourly = 0;
    int demMonthly = 0;
    for (Employee* emp : danhSach) {
        if (dynamic_cast<HourlyEmployee*>(emp) != nullptr) {
            demHourly++;
        } else if (dynamic_cast<MonthlyEmployee*>(emp) != nullptr) {
            demMonthly++;
        }
    }
    cout << "=== SO LUONG NHAN VIEN TUNG LOAI ===" << endl;
    cout << "HourlyEmployee: " << demHourly << endl;
    cout << "MonthlyEmployee: " << demMonthly << endl << endl;

    double mucLuong;
    cout << "Nhap muc luong can tim: ";
    if (cin >> mucLuong) {
        cout << "=== DANH SACH NHAN VIEN CO LUONG LON HON " << mucLuong << " ===" << endl;
        for (Employee* emp : danhSach) {
            if (emp->tinhLuong() > mucLuong) {
                emp->displayInfo();
                cout << endl;
            }
        }
    }

    sort(danhSach.begin(), danhSach.end(), [](Employee* a, Employee* b) {
        return a->tinhLuong() > b->tinhLuong();
    });

    cout << "=== DANH SACH NHAN VIEN THEO LUONG GIAM DAN ===" << endl;
    for (Employee* emp : danhSach) {
        emp->displayInfo();
        cout << endl;
    }

    return 0;
}
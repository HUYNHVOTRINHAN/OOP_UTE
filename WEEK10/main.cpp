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

class Food {
private:
    string id;
    string name;
    double price;
    int quantity;

public:
    Food() {
        id = "";
        name = "";
        price = 0;
        quantity = 0;
    }

    Food(string id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    void input() {
        cout << "Nhap ma mon: ";
        getline(cin, id);

        cout << "Nhap ten mon: ";
        getline(cin, name);

        do {
            cout << "Nhap gia: ";
            cin >> price;
            if (price <= 0) {
                cout << "Gia phai lon hon 0. Vui long nhap lai!\n";
            }
        } while (price <= 0);

        do {
            cout << "Nhap so luong: ";
            cin >> quantity;
            if (quantity < 0) {
                cout << "So luong khong the am. Vui long nhap lai!\n";
            }
        } while (quantity < 0);
        cin.ignore();
    }

    void display() const {
        cout << "Ma mon  : " << id << "\n";
        cout << "Ten mon : " << name << "\n";
        cout << "Gia     : " << price << "\n";
        cout << "So luong: " << quantity << "\n";
        cout << "---------------------------------\n";
    }

    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setPrice(double newPrice) { price = newPrice; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    bool isAvailable() const { return quantity > 0; }
    double totalValue() const { return price * quantity; }
};

int findFoodIndexById(const vector<Food>& foods, string id) {
    for (int i = 0; i < (int)foods.size(); i++) {
        if (toLower(foods[i].getId()) == toLower(id)) {
            return i;
        }
    }
    return -1;
}

void printFoods(const vector<Food>& foods) {
    if (foods.empty()) {
        cout << "Danh sach mon an dang trong!\n";
        return;
    }
    cout << "\n===== DANH SACH MON AN =====\n";
    for (int i = 0; i < (int)foods.size(); i++) {
        cout << "Mon an " << i + 1 << ":\n";
        foods[i].display();
    }
}

void foodProgram() {
    vector<Food> foods;
    int choice;

    do {
        cout << "\n===== QUAN LY MON AN =====\n";
        cout << "1. Nhap danh sach mon an\n";
        cout << "2. Hien thi danh sach mon an\n";
        cout << "3. Tim mon an theo ma\n";
        cout << "4. Tim mon an theo ten\n";
        cout << "5. Cap nhat gia mon an\n";
        cout << "6. Cap nhat so luong mon an\n";
        cout << "7. Kiem tra mon an con hang\n";
        cout << "8. Sap xep theo ten\n";
        cout << "9. Sap xep theo gia\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int n;
            cout << "Nhap so luong mon an muon them: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++) {
                cout << "\n--- Nhap mon an thu " << i + 1 << " ---\n";
                Food food;
                food.input();

                if (findFoodIndexById(foods, food.getId()) != -1) {
                    cout << "Ma mon da ton tai, khong them mon nay!\n";
                } else {
                    foods.push_back(food);
                    cout << "Them mon an thanh cong!\n";
                }
            }
        } else if (choice == 2) {
            printFoods(foods);
        } else if (choice == 3) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            string id;
            cout << "Nhap ma mon can tim: ";
            getline(cin, id);

            int idx = findFoodIndexById(foods, id);
            if (idx != -1) {
                cout << "\nThong tin mon an:\n";
                foods[idx].display();
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        } else if (choice == 4) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            string name;
            cout << "Nhap ten mon can tim: ";
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < (int)foods.size(); i++) {
                if (toLower(foods[i].getName()).find(toLower(name)) != string::npos) {
                    if (!found) {
                        cout << "\nKet qua tim kiem:\n";
                        found = true;
                    }
                    foods[i].display();
                }
            }
            if (!found) {
                cout << "Khong tim thay mon an nao phu hop!\n";
            }
        } else if (choice == 5) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            string id;
            cout << "Nhap ma mon can cap nhat gia: ";
            getline(cin, id);

            int idx = findFoodIndexById(foods, id);
            if (idx != -1) {
                double newPrice;
                do {
                    cout << "Nhap gia moi: ";
                    cin >> newPrice;
                    if (newPrice <= 0) cout << "Gia phai lon hon 0!\n";
                } while (newPrice <= 0);
                cin.ignore();

                foods[idx].setPrice(newPrice);
                cout << "Da cap nhat gia thanh cong!\n";
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        } else if (choice == 6) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            string id;
            cout << "Nhap ma mon can cap nhat so luong: ";
            getline(cin, id);

            int idx = findFoodIndexById(foods, id);
            if (idx != -1) {
                int newQuantity;
                do {
                    cout << "Nhap so luong moi: ";
                    cin >> newQuantity;
                    if (newQuantity < 0) cout << "So luong khong the am!\n";
                } while (newQuantity < 0);
                cin.ignore();

                foods[idx].setQuantity(newQuantity);
                cout << "Da cap nhat so luong thanh cong!\n";
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        } else if (choice == 7) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            string id;
            cout << "Nhap ma mon can kiem tra: ";
            getline(cin, id);

            int idx = findFoodIndexById(foods, id);
            if (idx != -1) {
                if (foods[idx].isAvailable()) {
                    cout << "Mon \"" << foods[idx].getName() << "\" CON HANG (So luong: " 
                         << foods[idx].getQuantity() << ")\n";
                } else {
                    cout << "Mon \"" << foods[idx].getName() << "\" DA HET HANG!\n";
                }
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        } else if (choice == 8) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            int total = foods.size();
            for (int i = 0; i < total - 1; i++) {
                for (int j = i + 1; j < total; j++) {
                    if (foods[i].getName() > foods[j].getName()) {
                        Food temp = foods[i];
                        foods[i] = foods[j];
                        foods[j] = temp;
                    }
                }
            }
            cout << "Da sap xep danh sach theo ten!\n";
            printFoods(foods);
        } else if (choice == 9) {
            if (foods.empty()) {
                cout << "Danh sach mon an dang trong!\n";
                continue;
            }
            int total = foods.size();
            for (int i = 0; i < total - 1; i++) {
                for (int j = i + 1; j < total; j++) {
                    if (foods[i].getPrice() > foods[j].getPrice()) {
                        Food temp = foods[i];
                        foods[i] = foods[j];
                        foods[j] = temp;
                    }
                }
            }
            cout << "Da sap xep danh sach theo gia!\n";
            printFoods(foods);
        } else if (choice != 0) {
            cout << "Chuc nang khong hop le, vui long chon lai!\n";
        }
    } while (choice != 0);
}

class Book {
private:
    string bookId;
    string title;
    string author;
    int year;

public:
    Book() {
        bookId = "";
        title = "";
        author = "";
        year = 0;
    }

    Book(string id, string bookTitle, string bookAuthor, int publishYear) {
        bookId = id;
        title = bookTitle;
        author = bookAuthor;
        year = publishYear;
    }

    void input() {
        cout << "Nhap ma sach: ";
        getline(cin, bookId);

        cout << "Nhap ten sach: ";
        getline(cin, title);

        cout << "Nhap tac gia: ";
        getline(cin, author);

        cout << "Nhap nam xuat ban: ";
        cin >> year;
        cin.ignore();
    }

    void display() const {
        cout << "Ma sach  : " << bookId << "\n";
        cout << "Ten sach : " << title << "\n";
        cout << "Tac gia  : " << author << "\n";
        cout << "Nam XB   : " << year << "\n";
        cout << "---------------------------------\n";
    }

    string getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
};

int findBookIndexById(const vector<Book>& books, string id) {
    for (int i = 0; i < (int)books.size(); i++) {
        if (toLower(books[i].getBookId()) == toLower(id)) {
            return i;
        }
    }
    return -1;
}

void printBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "Danh sach sach dang trong!\n";
        return;
    }
    cout << "\n===== DANH SACH SACH THU VIEN =====\n";
    for (int i = 0; i < (int)books.size(); i++) {
        cout << "Quyen sach " << i + 1 << ":\n";
        books[i].display();
    }
}

void libraryProgram() {
    vector<Book> books;
    int choice;

    do {
        cout << "\n===== QUAN LY SACH THU VIEN =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach sach\n";
        cout << "3. Tim sach theo ma sach\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id;
            cout << "Nhap ma sach: ";
            getline(cin, id);

            if (findBookIndexById(books, id) != -1) {
                cout << "Ma sach da ton tai, khong the them!\n";
                continue;
            }

            string title, author;
            int year;

            cout << "Nhap ten sach: ";
            getline(cin, title);

            cout << "Nhap tac gia: ";
            getline(cin, author);

            cout << "Nhap nam xuat ban: ";
            cin >> year;
            cin.ignore();

            Book book(id, title, author, year);
            books.push_back(book);
            cout << "Da them sach thanh cong!\n";
        } else if (choice == 2) {
            printBooks(books);
        } else if (choice == 3) {
            if (books.empty()) {
                cout << "Danh sach sach dang trong!\n";
                continue;
            }
            string id;
            cout << "Nhap ma sach can tim: ";
            getline(cin, id);

            int idx = findBookIndexById(books, id);
            if (idx != -1) {
                cout << "\nThong tin sach tim thay:\n";
                books[idx].display();
            } else {
                cout << "Khong tim thay sach voi ma tren!\n";
            }
        } else if (choice != 0) {
            cout << "Chuc nang khong hop le, vui long chon lai!\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        cout << "\n========== BAI TAP C++ OOP ==========\n";
        cout << "1. Bai Food - Quan ly mon an\n";
        cout << "2. Bai Book - Quan ly sach thu vien\n";
        cout << "0. Thoat\n";
        cout << "Chon bai: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            foodProgram();
        } else if (choice == 2) {
            libraryProgram();
        } else if (choice == 0) {
            cout << "Tam biet!\n";
        } else {
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (choice != 0);

    return 0;
}

#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string toLower(string s) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
  }
  return s;
}

struct Food {
  string id;
  string name;
  double price;
  int quantity;
};

struct Order {
  string id;
  string customerName;
  string address;
  Food food;
  int quantity;
  string status;
};

struct Restaurant {
  string name;
  string address;
  string phone;
  Food foods[100];
  int foodCount = 0;
  Order orders[100];
  int orderCount = 0;

  void input() {
    cout << "Nhap ten cua hang: ";
    getline(cin, name);

    cout << "Nhap dia chi: ";
    getline(cin, address);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
  }

  void output() {
    cout << "Ten cua hang: " << name << endl;
    cout << "Dia chi: " << address << endl;
    cout << "SDT: " << phone << endl;
  };

  void addfood(Food new_mon) {
    if (foodCount < 100) {
      foods[foodCount] = new_mon;
      foodCount++;
    } else
      cout << "Menu day roi!!" << endl;
  }

  void Ds_monan() {
    for (int i = 0; i < foodCount; i++) {
      cout << "Ma mon: " << foods[i].id << endl;
      cout << "Ten mon: " << foods[i].name << endl;
      printf("Price: %.1f\n", foods[i].price);
      cout << "So luong: " << foods[i].quantity << endl;
      cout << "-------------------" << endl;
    }
  }

  void find_food_by_name_or_id() {
    string find;
    cout << "Nhap ma or ten can tim: ";
    getline(cin, find);

    find = toLower(find);

    for (int i = 0; i < foodCount; i++) {
      if (toLower(foods[i].id) == find || toLower(foods[i].name) == find) {
        cout << "Ma mon: " << foods[i].id << endl;
        cout << "Ten mon: " << foods[i].name << endl;
        cout << "Gia: " << foods[i].price << endl;
        cout << "So luong: " << foods[i].quantity << endl;
        return;
      }
    }

    cout << "Khong tim thay mon an!" << endl;
  }

  void update_food() {
    string find;
    int chon;

    cout << "Nhap ma or ten mon can cap nhat: ";
    getline(cin, find);

    find = toLower(find);

    for (int i = 0; i < foodCount; i++) {
      if (toLower(foods[i].id) == find || toLower(foods[i].name) == find) {

        cout << "1. Cap nhat gia" << endl;
        cout << "2. Cap nhat so luong" << endl;
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1) {
          cout << "Nhap gia moi: ";
          cin >> foods[i].price;
        } else if (chon == 2) {
          cout << "Nhap so luong moi: ";
          cin >> foods[i].quantity;
        } else {
          cout << "Lua chon khong hop le!" << endl;
        }

        cin.ignore();
        return;
      }
    }

    cout << "Khong tim thay mon an!" << endl;
  }

  bool check_food(string ma_mon, int so_luong) {
    for (int i = 0; i < foodCount; i++) {
      if (toLower(foods[i].id) == toLower(ma_mon)) {
        if (foods[i].quantity >= so_luong) {
          return true;
        } else {
          cout << "Mon an khong du so luong!" << endl;
          return false;
        }
      }
    }

    cout << "Mon an khong ton tai!" << endl;
    return false;
  }

  void create_order() {
    if (orderCount >= 100) {
      cout << "Danh sach don hang day!" << endl;
      return;
    }

    Order new_order;
    string ma_mon;

    cout << "Nhap ma don hang: ";
    getline(cin, new_order.id);

    cout << "Nhap ten khach hang: ";
    getline(cin, new_order.customerName);

    cout << "Nhap dia chi giao hang: ";
    getline(cin, new_order.address);

    cout << "Nhap ma mon: ";
    getline(cin, ma_mon);

    cout << "Nhap so luong: ";
    cin >> new_order.quantity;
    cin.ignore();

    if (check_food(ma_mon, new_order.quantity) == false) {
      return;
    }

    for (int i = 0; i < foodCount; i++) {
      if (toLower(foods[i].id) == toLower(ma_mon)) {
        new_order.food = foods[i];
        foods[i].quantity -= new_order.quantity;
        break;
      }
    }

    new_order.status = "dang xu ly";

    orders[orderCount] = new_order;
    orderCount++;

    cout << "Tao don hang thanh cong!" << endl;
  }

  double total_order(Order don) { return don.food.price * don.quantity; }

  void Ds_donhang() {
    if (orderCount == 0) {
      cout << "Chua co don hang!" << endl;
      return;
    }

    for (int i = 0; i < orderCount; i++) {
      cout << "Ma don hang: " << orders[i].id << endl;
      cout << "Ten khach hang: " << orders[i].customerName << endl;
      cout << "Dia chi: " << orders[i].address << endl;
      cout << "Mon an: " << orders[i].food.name << endl;
      cout << "So luong: " << orders[i].quantity << endl;
      cout << "Trang thai: " << orders[i].status << endl;
      cout << "Tong tien: " << total_order(orders[i]) << endl;
      cout << "-------------------" << endl;
    }
  }

  void find_order() {
    string find;

    cout << "Nhap ma don hang can tim: ";
    getline(cin, find);

    find = toLower(find);

    for (int i = 0; i < orderCount; i++) {
      if (toLower(orders[i].id) == find) {
        cout << "Ma don hang: " << orders[i].id << endl;
        cout << "Ten khach hang: " << orders[i].customerName << endl;
        cout << "Dia chi: " << orders[i].address << endl;
        cout << "Mon an: " << orders[i].food.name << endl;
        cout << "So luong: " << orders[i].quantity << endl;
        cout << "Trang thai: " << orders[i].status << endl;
        cout << "Tong tien: " << total_order(orders[i]) << endl;
        return;
      }
    }

    cout << "Khong tim thay don hang!" << endl;
  }

  void update_status() {
    string find;
    string new_status;

    cout << "Nhap ma don hang: ";
    getline(cin, find);

    find = toLower(find);

    for (int i = 0; i < orderCount; i++) {
      if (toLower(orders[i].id) == find) {

        cout << "Nhap trang thai moi: ";
        getline(cin, new_status);

        orders[i].status = new_status;

        cout << "Cap nhat thanh cong!" << endl;
        return;
      }
    }

    cout << "Khong tim thay don hang!" << endl;
  }

  double total_revenue() {
    double tong = 0;

    for (int i = 0; i < orderCount; i++) {
      if (toLower(orders[i].status) == "hoan thanh") {
        tong += total_order(orders[i]);
      }
    }

    return tong;
  }
};

int main() {

  Restaurant restaurant;

  int chon;

  do {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Nhap thong tin cua hang" << endl;
    cout << "2. Them mon an moi" << endl;
    cout << "3. Hien thi danh sach mon an" << endl;
    cout << "4. Tim mon an theo ma hoac ten" << endl;
    cout << "5. Cap nhat gia hoac so luong mon an" << endl;
    cout << "6. Tao don hang moi" << endl;
    cout << "7. Kiem tra mon an va so luong" << endl;
    cout << "8. Tinh tong tien don hang" << endl;
    cout << "9. Hien thi danh sach don hang" << endl;
    cout << "10. Tim don hang theo ma" << endl;
    cout << "11. Cap nhat trang thai don hang" << endl;
    cout << "12. Thong ke tong doanh thu" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon: ";

    cin >> chon;
    cin.ignore();

    if (chon == 1) {
      restaurant.input();
    }

    else if (chon == 2) {
      Food new_mon;

      cout << "Nhap ma mon: ";
      getline(cin, new_mon.id);

      cout << "Nhap ten mon: ";
      getline(cin, new_mon.name);

      cout << "Nhap gia: ";
      cin >> new_mon.price;

      cout << "Nhap so luong: ";
      cin >> new_mon.quantity;
      cin.ignore();

      restaurant.addfood(new_mon);
    }

    else if (chon == 3) {
      restaurant.Ds_monan();
    }

    else if (chon == 4) {
      restaurant.find_food_by_name_or_id();
    }

    else if (chon == 5) {
      restaurant.update_food();
    }

    else if (chon == 6) {
      restaurant.create_order();
    }

    else if (chon == 7) {
      string ma_mon;
      int so_luong;

      cout << "Nhap ma mon: ";
      getline(cin, ma_mon);

      cout << "Nhap so luong can kiem tra: ";
      cin >> so_luong;
      cin.ignore();

      if (restaurant.check_food(ma_mon, so_luong)) {
        cout << "Mon an ton tai va du so luong!" << endl;
      }
    }

    else if (chon == 8) {
      string ma_don;

      cout << "Nhap ma don hang: ";
      getline(cin, ma_don);

      bool found = false;

      for (int i = 0; i < restaurant.orderCount; i++) {
        if (toLower(restaurant.orders[i].id) == toLower(ma_don)) {
          cout << "Tong tien: " << restaurant.total_order(restaurant.orders[i])
               << endl;

          found = true;
          break;
        }
      }

      if (found == false) {
        cout << "Khong tim thay don hang!" << endl;
      }
    }

    else if (chon == 9) {
      restaurant.Ds_donhang();
    }

    else if (chon == 10) {
      restaurant.find_order();
    }

    else if (chon == 11) {
      restaurant.update_status();
    }

    else if (chon == 12) {
      cout << "Tong doanh thu: " << restaurant.total_revenue() << endl;
    }

  } while (chon != 0);

  return 0;
}
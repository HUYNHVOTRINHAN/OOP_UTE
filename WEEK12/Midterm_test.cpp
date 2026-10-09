#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date() {
    day = 1;
    month = 1;
    year = 2024;
  }

  Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

  int getDay() const {
    return day;
  }

  void setDay(int d) {
    day = d;
  }

  int getMonth() const {
    return month;
  }

  void setMonth(int m) {
    month = m;
  }

  int getYear() const {
    return year;
  }

  void setYear(int y) {
    year = y;
  }

  void displayDate() const {
    cout << (day < 10 ? "0" : "") << day << "/"
         << (month < 10 ? "0" : "") << month << "/"
         << year << endl;
  }
};

class Category {
private:
  int category_id;
  string category_name;
  string description;

public:
  Category() {
    category_id = 0;
    category_name = "";
    description = "";
  }

  Category(int c_id, string c_name, string desc) {
    category_id = c_id;
    category_name = c_name;
    description = desc;
  }

  int getCategoryId() const {
    return category_id;
  }

  void setCategoryId(int c_id) {
    category_id = c_id;
  }

  string getCategoryName() const {
    return category_name;
  }

  void setCategoryName(string c_name) {
    category_name = c_name;
  }

  string getDescription() const {
    return description;
  }

  void setDescription(string desc) {
    description = desc;
  }

  void displayCategoryInfo() const {
    cout << "Category ID  : " << category_id << endl;
    cout << "Category Name: " << category_name << endl;
    cout << "Description  : " << description << endl;
    cout << "---------------------------------\n";
  }
};

class Fish {
private:
  int id;
  string name;
  string color;
  string characteristic;
  int category_id;

public:
  Fish() {
    id = 0;
    name = "";
    color = "";
    characteristic = "";
    category_id = 0;
  }

  Fish(int i) {
    id = i;
    name = "";
    color = "";
    characteristic = "";
    category_id = 0;
  }

  Fish(int i, string n) {
    id = i;
    name = n;
    color = "";
    characteristic = "";
    category_id = 0;
  }

  Fish(int i, string n, string c) {
    id = i;
    name = n;
    color = c;
    characteristic = "";
    category_id = 0;
  }

  Fish(int i, string n, string c, string ch) {
    id = i;
    name = n;
    color = c;
    characteristic = ch;
    category_id = 0;
  }

  Fish(int i, string n, string c, string ch, int cat_id) {
    id = i;
    name = n;
    color = c;
    characteristic = ch;
    category_id = cat_id;
  }

  int getId() const {
    return id;
  }

  void setId(int i) {
    id = i;
  }

  string getName() const {
    return name;
  }

  void setName(string n) {
    name = n;
  }

  string getColor() const {
    return color;
  }

  void setColor(string c) {
    color = c;
  }

  string getCharacteristic() const {
    return characteristic;
  }

  void setCharacteristic(string ch) {
    characteristic = ch;
  }

  int getCategoryId() const {
    return category_id;
  }

  void setCategoryId(int cat_id) {
    category_id = cat_id;
  }

  void displayFishInfo() const {
    cout << "ID            : " << id << endl;
    cout << "Name          : " << name << endl;
    cout << "Color         : " << color << "\n";
    cout << "Characteristic: " << characteristic << endl;
    cout << "Category ID   : " << category_id << endl;
    cout << "---------------------------------\n";
  }
};

vector<Fish> getFishByColor(string c, const vector<Fish>& fish_list) {
  vector<Fish> result;
  for (size_t i = 0; i < fish_list.size(); i++) {
    if (fish_list[i].getColor() == c) {
      result.push_back(fish_list[i]);
    }
  }
  return result;
}

vector<Fish> getFishByCategory(int cat_id, const vector<Fish>& fish_list) {
  vector<Fish> result;
  for (size_t i = 0; i < fish_list.size(); i++) {
    if (fish_list[i].getCategoryId() == cat_id) {
      result.push_back(fish_list[i]);
    }
  }
  return result;
}

vector<string> getDistinctColors(const vector<Fish>& fish_list) {
  vector<string> colors;
  for (size_t i = 0; i < fish_list.size(); i++) {
    string c = fish_list[i].getColor();
    if (c == "") continue;
    bool found = false;
    for (size_t j = 0; j < colors.size(); j++) {
      if (colors[j] == c) {
        found = true;
        break;
      }
    }
    if (!found) {
      colors.push_back(c);
    }
  }
  return colors;
}

class FishShop {
private:
  int id;
  string name;
  string address;
  string owner;
  Date startdate;
  vector<Category> categories;
  vector<Fish> fishes;

public:
  FishShop() {
    id = 0;
    name = "";
    address = "";
    owner = "";
    startdate = Date();
  }

  FishShop(int i, string n, string addr, string o, Date d) {
    id = i;
    name = n;
    address = addr;
    owner = o;
    startdate = d;
  }

  int getId() const {
    return id;
  }

  void setId(int i) {
    id = i;
  }

  string getName() const {
    return name;
  }

  void setName(string n) {
    name = n;
  }

  string getAddress() const {
    return address;
  }

  void setAddress(string addr) {
    address = addr;
  }

  string getOwner() const {
    return owner;
  }

  void setOwner(string o) {
    owner = o;
  }

  Date getStartdate() const {
    return startdate;
  }

  void setStartdate(Date d) {
    startdate = d;
  }

  vector<Category> getCategories() const {
    return categories;
  }

  void setCategories(const vector<Category>& cats) {
    categories = cats;
  }

  vector<Fish> getFishes() const {
    return fishes;
  }

  void setFishes(const vector<Fish>& f_list) {
    fishes = f_list;
  }

  void addCategory(const Category& c) {
    categories.push_back(c);
  }

  void addFish(const Fish& f) {
    fishes.push_back(f);
  }

  void displayShopInfo() const {
    cout << "\n================ FISH SHOP ================\n";
    cout << "Shop ID   : " << id << endl;
    cout << "Shop Name : " << name << endl;
    cout << "Address   : " << address << endl;
    cout << "Owner     : " << owner << endl;
    cout << "Start Date: ";
    startdate.displayDate();
    cout << "-------------------------------------------\n";
    cout << "Total Categories: " << categories.size() << endl;
    for (size_t i = 0; i < categories.size(); i++) {
      cout << "\n[Category " << i + 1 << "]\n";
      categories[i].displayCategoryInfo();
    }
    cout << "-------------------------------------------\n";
    cout << "Total Fishes    : " << fishes.size() << endl;
    for (size_t i = 0; i < fishes.size(); i++) {
      cout << "\n[Fish " << i + 1 << "]\n";
      fishes[i].displayFishInfo();
    }
    cout << "===========================================\n";
  }
};

int main() {
  Fish fish1;
  Fish fish2(101);
  Fish fish3(102, "Betta");
  Fish fish4(103, "Guppy", "Do");
  Fish fish5(104, "Koi", "Trang do", "Boi nhanh, than thien, dep trai");

  fish1.displayFishInfo();
  fish2.displayFishInfo();
  fish3.displayFishInfo();
  fish4.displayFishInfo();
  fish5.displayFishInfo();

  fish1.setName("Ca Rong");
  fish1.setColor("Vang anh kim");
  fish1.setCharacteristic("Hung du, may man");

  cout << "Updated fish id            : " << fish1.getId() << endl;
  cout << "Updated fish name          : " << fish1.getName() << endl;
  cout << "Updated fish color         : " << fish1.getColor() << endl;
  cout << "Updated fish characteristic: " << fish1.getCharacteristic() << endl;
  cout << "---------------------------------\n";

  fish1.displayFishInfo();

  vector<Fish> fish_list;
  fish_list.push_back(fish1);
  fish_list.push_back(fish2);
  fish_list.push_back(fish3);
  fish_list.push_back(fish4);
  fish_list.push_back(fish5);

  fish_list.push_back(Fish(201, "Ca Bay Mau Full Red", "Do", "De nuoi, sinh san nhanh", 1));
  fish_list.push_back(Fish(202, "Ca Neon Xanh", "Xanh duong", "Boi theo dan, nho con", 2));
  fish_list.push_back(Fish(203, "Ca Dia Da Ran", "Do", "Dang tron, hoa tiet doc dao", 2));
  fish_list.push_back(Fish(204, "Ca Thuy Tinh", "Trong suot", "Than hinh trong suot", 2));
  fish_list.push_back(Fish(205, "Ca La Han", "Do", "Dau gu, mau sac ruc ro", 3));
  fish_list.push_back(Fish(206, "Ca Sam", "Den cham bi", "Song tang day, hoa van dep", 3));
  fish_list.push_back(Fish(207, "Ca He Nemo", "Cam trang", "Song cong sinh hai quy", 1));
  fish_list.push_back(Fish(208, "Ca Tang Vang", "Vang", "Mau vang ruc, khoe manh", 1));
  fish_list.push_back(Fish(209, "Ca Chuot My", "Cam den", "An thuc an thua, boi tang day", 2));
  fish_list.push_back(Fish(210, "Ca Phat Tai", "Hong phan", "Thong minh, biet nhan chu", 3));

  fish_list[0].setCategoryId(3);
  fish_list[1].setCategoryId(1);
  fish_list[2].setCategoryId(1);
  fish_list[3].setCategoryId(1);
  fish_list[4].setCategoryId(3);

  cout << "\n=== DANH SACH CA THEO MAU SAC ===\n";
  vector<string> all_colors = getDistinctColors(fish_list);
  for (size_t i = 0; i < all_colors.size(); i++) {
    string current_color = all_colors[i];
    cout << "\n--- Mau: " << current_color << " ---\n";
    vector<Fish> same_color_fish = getFishByColor(current_color, fish_list);
    for (size_t j = 0; j < same_color_fish.size(); j++) {
      same_color_fish[j].displayFishInfo();
    }
  }

  vector<Category> category_list;
  category_list.push_back(Category(1, "Ca Canh Co Nho", "Cac loai ca bay mau, ca betta, ca thuy sinh nho de cham soc"));
  category_list.push_back(Category(2, "Ca Thuy Sinh", "Cac dong ca boi dan, ca tang day phu hop be thuy sinh"));
  category_list.push_back(Category(3, "Ca San Moi Va Phong Thuy", "Cac dong ca kich thuoc lon nhu ca rong, ca la han, ca sam"));

  cout << "\n=== DANH SACH TAT CA CATEGORY ===\n";
  for (size_t i = 0; i < category_list.size(); i++) {
    category_list[i].displayCategoryInfo();
  }

  int selected_category_id = 1;
  cout << "\n=== DANH SACH CA THUOC CATEGORY ID " << selected_category_id << " ===\n";
  vector<Fish> selected_fish = getFishByCategory(selected_category_id, fish_list);
  for (size_t i = 0; i < selected_fish.size(); i++) {
    selected_fish[i].displayFishInfo();
  }

  FishShop fish_shop(1, "Thuy Cung Sai Gon", "123 Nguyen Trai, Q1, TP.HCM", "Huynh Vo Tri Nhan", Date(15, 8, 2020));

  Category cat1(1, "Ca Canh Co Nho", "Cac loai ca bay mau, ca neon, de cham soc");
  Category cat2(2, "Ca Thuy Sinh", "Cac loai ca phu hop ho cay thuy sinh, ho cong dong");
  Category cat3(3, "Ca San Moi Va Phong Thuy", "Cac loai ca lon, mang lai tai loc phong thuy");
  Category cat4(4, "Ca Bien", "Cac loai ca nuoc man, mau sac ruc ro");

  fish_shop.addCategory(cat1);
  fish_shop.addCategory(cat2);
  fish_shop.addCategory(cat3);
  fish_shop.addCategory(cat4);

  fish_shop.addFish(Fish(1001, "Ca Bay Mau Rong Do", "Do", "Vay duoi to, boi linh hoat", 1));
  fish_shop.addFish(Fish(1002, "Ca Bay Mau Blue Topaz", "Xanh duong", "Than phan anh sang xanh", 1));
  fish_shop.addFish(Fish(1003, "Ca Bay Mau Full Gold", "Vang", "Mau vang anh kim toan than", 1));
  fish_shop.addFish(Fish(1004, "Ca Bay Mau Dumbo Mosaic", "Nhieu mau", "Tai bboi to mau tim xanh", 1));
  fish_shop.addFish(Fish(1005, "Ca Betta Halfmoon", "Do xanh", "Duoi xoe tron 180 do", 1));
  fish_shop.addFish(Fish(1006, "Ca Betta Plakat", "Xanh duong", "Duoi ngan, boi nhanh, khoe", 1));
  fish_shop.addFish(Fish(1007, "Ca Betta Koi Galaxy", "Nhieu mau", "Hoa tiet galaxy lap lanh", 1));
  fish_shop.addFish(Fish(1008, "Ca Tram Do", "Do", "Kich thuoc ti hon, boi dan", 1));
  fish_shop.addFish(Fish(1009, "Ca Soc Soc Tim", "Tim", "Than hinh phat sang duoi den", 1));
  fish_shop.addFish(Fish(1010, "Ca Moly Trang", "Trang", "Dang tron de thuong, de de", 1));

  fish_shop.addFish(Fish(2001, "Ca Neon Kim Cuong", "Bac", "Vach xanh phan quang lap lanh", 2));
  fish_shop.addFish(Fish(2002, "Ca Neon Vua", "Do xanh", "Bung do toan phan, boi theo dan", 2));
  fish_shop.addFish(Fish(2003, "Ca Neon Den", "Den", "Vach trang den noi bat", 2));
  fish_shop.addFish(Fish(2004, "Ca Tam Giac", "Cam den", "Hinh tam giac mau den tren than", 2));
  fish_shop.addFish(Fish(2005, "Ca Chuot Panda", "Trang den", "Hoa van mat giong gau truc", 2));
  fish_shop.addFish(Fish(2006, "Ca Chuot Pygmy", "Xam", "Kich thuoc sieu nho, dang yeu", 2));
  fish_shop.addFish(Fish(2007, "Ca Thuy Tinh Chot", "Trong suot", "Nhin thay ro xuong va noi tang", 2));
  fish_shop.addFish(Fish(2008, "Ca Dia Bo Cau", "Trang do", "Hinh dang dia tron, hoa van dep", 2));
  fish_shop.addFish(Fish(2009, "Ca Dia Lam", "Xanh lam", "Mau xanh lam toan than quy phai", 2));
  fish_shop.addFish(Fish(2010, "Ca But Chi Do", "Do den", "Boi nhanh, don dep reu hai", 2));

  fish_shop.addFish(Fish(3001, "Ca Rong Huyet Long", "Do", "Mang lai may man va quyen luc", 3));
  fish_shop.addFish(Fish(3002, "Ca Rong Boi Dau", "Vang kim", "Vay vang lap lanh anh kim", 3));
  fish_shop.addFish(Fish(3003, "Ca Rong Ngan Long", "Bac", "Than hinh dai mau bac uyen chuyen", 3));
  fish_shop.addFish(Fish(3004, "Ca La Han Thai Silk", "Xanh bac", "Dau gu to, anh kim lap lanh", 3));
  fish_shop.addFish(Fish(3005, "Ca La Han Kamfa", "Do vang", "Mat trang hoac vang, hoa van chu hoa", 3));
  fish_shop.addFish(Fish(3006, "Ca Sam Black Diamond", "Den trang", "Cham bi trang tren nen den", 3));
  fish_shop.addFish(Fish(3007, "Ca Sam Motoro", "Nau vang", "Hoa tiet hoa dong tien doc dao", 3));
  fish_shop.addFish(Fish(3008, "Ca Ho Indo", "Vang den", "Soc vang den giong ho hung dung", 3));
  fish_shop.addFish(Fish(3009, "Ca Tai Tuong Chau Phi", "Den do", "Thong minh, hoa tiet da cam", 3));
  fish_shop.addFish(Fish(3010, "Ca Hong Ket King Kong", "Do", "Mau do ruc, mieng hinh trai tim", 3));

  fish_shop.addFish(Fish(4001, "Ca He Nemo Ocellaris", "Cam trang", "Song cong sinh cung hai quy", 4));
  fish_shop.addFish(Fish(4002, "Ca He Den Black Storm", "Den trang", "Hoa van tia chop trang den", 4));
  fish_shop.addFish(Fish(4003, "Ca Blue Tang", "Xanh duong", "Ca Dory than hinh xanh duong noi bat", 4));
  fish_shop.addFish(Fish(4004, "Ca Yellow Tang", "Vang", "Mau vang tuoi ruc ro toan than", 4));
  fish_shop.addFish(Fish(4005, "Ca Banggai Cardinal", "Bac den", "Vay dai thanh thoat, cham bi trang", 4));
  fish_shop.addFish(Fish(4006, "Ca Su Tu Bien", "Nau do", "Cac tia vay tua tia set doc dao", 4));
  fish_shop.addFish(Fish(4007, "Ca Than Tien Hoang Gia", "Xanh vang", "Hoa van sang trong quy toc", 4));
  fish_shop.addFish(Fish(4008, "Ca Bip Lua", "Do den", "Mau do cam ruc nhu ngon lua", 4));
  fish_shop.addFish(Fish(4009, "Ca Bo Hom Vang", "Vang cham den", "Than hinh vuong vuc sieu dang yeu", 4));
  fish_shop.addFish(Fish(4010, "Ca Cao Xanh Bien", "Xanh ngoc", "Mau xanh bien dam, boi nhanh", 4));

  fish_shop.displayShopInfo();

  return 0;
}

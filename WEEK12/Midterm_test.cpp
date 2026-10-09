#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

  return 0;
}

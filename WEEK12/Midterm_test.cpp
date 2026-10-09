#include <iostream>
#include <string>

using namespace std;

class Fish {
private:
  int id;
  string name;
  string color;
  string characteristic;

public:
  Fish() {
    id = 0;
    name = "";
    color = "";
    characteristic = "";
  }

  Fish(int i) {
    id = i;
    name = "";
    color = "";
    characteristic = "";
  }

  Fish(int i, string n) {
    id = i;
    name = n;
    color = "";
    characteristic = "";
  }

  Fish(int i, string n, string c) {
    id = i;
    name = n;
    color = c;
    characteristic = "";
  }

  Fish(int i, string n, string c, string ch) {
    id = i;
    name = n;
    color = c;
    characteristic = ch;
  }

  int getId() {
    return id;
  }

  void setId(int i) {
    id = i;
  }

  string getName() {
    return name;
  }

  void setName(string n) {
    name = n;
  }

  string getColor() {
    return color;
  }

  void setColor(string c) {
    color = c;
  }

  string getCharacteristic() {
    return characteristic;
  }

  void setCharacteristic(string ch) {
    characteristic = ch;
  }
  //
  void displayFishInfo() {
    cout << "ID            : " << id << endl;
    cout << "Name          : " << name << endl;
    cout << "Color         : " << color << "\n";
    cout << "Characteristic: " << characteristic << endl;
    cout << "---------------------------------\n";
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

  return 0;
}

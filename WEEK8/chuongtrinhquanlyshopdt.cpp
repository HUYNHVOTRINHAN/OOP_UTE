#include <iostream>
#include <string>

using namespace std;

struct dienthoai {
  string id;
  string brand;
  string version;
  string seriesId;
  int year;
  double gia;

  void nhapdienthoai() {
    cout << "Nhap ma DT (id): ";
    getline(cin, id);
    cout << "Nhap hang (brand): ";
    getline(cin, brand);
    cout << "Nhap phien ban (version): ";
    getline(cin, version);
    cout << "Nhap ma series (seriesId): ";
    getline(cin, seriesId);
    cout << "Nhap nam san xuat (year): ";
    cin >> year;
    cout << "Nhap gia ban: ";
    cin >> gia;
    cin.ignore();
  }

  void xuatdienthoai() {
    cout << "Ma DT: " << id << " | Hang: " << brand << " | Version: " << version
         << " | Series: " << seriesId << " | Nam SX: " << year
         << " | Gia: " << gia << endl;
  }
};

struct donhang {
  string madonhang;
  string makhachhang;
  string diachikhachhang;
  string ngaydat;
  bool trangthaithanhtoan;
  int soluongsanpham;
  dienthoai danhsachsanpham[50];

  void nhapdonhang() {
    cout << "Nhap ma don hang (id order): ";
    getline(cin, madonhang);
    cout << "Nhap ma khach hang (id customer): ";
    getline(cin, makhachhang);
    cout << "Nhap dia chi khach hang: ";
    getline(cin, diachikhachhang);
    cout << "Nhap ngay dat hang (date): ";
    getline(cin, ngaydat);
    cout << "Trang thai thanh toan (1: Da thanh toan, 0: Chua): ";
    int tt;
    cin >> tt;
    trangthaithanhtoan = (tt == 1);
    cout << "Nhap so luong dien thoai trong don: ";
    cin >> soluongsanpham;
    cin.ignore();

    for (int i = 0; i < soluongsanpham; i++) {
      cout << "--- Nhap dien thoai thu " << i + 1 << " trong don ---\n";
      danhsachsanpham[i].nhapdienthoai();
    }
  }

  void xuatdonhang() {
    cout << "Ma don hang: " << madonhang << " | Ma KH: " << makhachhang
         << " | Dia chi: " << diachikhachhang << " | Ngay: " << ngaydat
         << " | Thanh toan: " << (trangthaithanhtoan ? "True" : "False")
         << endl;
    cout << "Danh sach dien thoai trong don:\n";
    for (int i = 0; i < soluongsanpham; i++) {
      cout << "  + ";
      danhsachsanpham[i].xuatdienthoai();
    }
  }
};

struct shop {
  string tenshop;
  string diachi;
  string sdt;

  int soluongdt;
  dienthoai danhsachdt[100];

  int soluongdonhang;
  donhang danhsachdonhang[100];

  void nhapthongtinshop() {
    cout << "Nhap ten cua hang: ";
    getline(cin, tenshop);
    cout << "Nhap dia chi cua hang: ";
    getline(cin, diachi);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    soluongdt = 0;
    soluongdonhang = 0;
  }

  void xuatthongtinshop() {
    cout << "\n================ THONG TIN SHOP ================\n";
    cout << "Ten shop : " << tenshop << endl;
    cout << "Dia chi  : " << diachi << endl;
    cout << "SDT      : " << sdt << endl;
    cout << "So luong DT hien co: " << soluongdt << endl;
    cout << "So luong don hang  : " << soluongdonhang << endl;
    cout << "================================================\n";
  }

  void themdienthoai(const dienthoai &dt) {
    if (soluongdt < 100) {
      danhsachdt[soluongdt] = dt;
      soluongdt++;
      cout << "Them dien thoai thanh cong!\n";
    } else {
      cout << "Cua hang da day danh sach dien thoai!\n";
    }
  }

  void xoadienthoai(string madt) {
    int vitri = -1;
    for (int i = 0; i < soluongdt; i++) {
      if (danhsachdt[i].id == madt) {
        vitri = i;
        break;
      }
    }
    if (vitri != -1) {
      for (int i = vitri; i < soluongdt - 1; i++) {
        danhsachdt[i] = danhsachdt[i + 1];
      }
      soluongdt--;
      cout << "Xoa thanh cong dien thoai co ma: " << madt << endl;
    } else {
      cout << "Khong tim thay dien thoai co ma: " << madt << endl;
    }
  }

  void xuatdanhsachdienthoai() {
    cout << "\n--- DANH SACH DIEN THOAI TAI CUA HANG ---\n";
    if (soluongdt == 0) {
      cout << "Chua co dien thoai nao.\n";
      return;
    }
    for (int i = 0; i < soluongdt; i++) {
      cout << i + 1 << ". ";
      danhsachdt[i].xuatdienthoai();
    }
  }

  void themdonhang(const donhang &dh) {
    if (soluongdonhang < 100) {
      danhsachdonhang[soluongdonhang] = dh;
      soluongdonhang++;
      cout << "Them don hang thanh cong!\n";
    } else {
      cout << "Danh sach don hang da day!\n";
    }
  }

  void xuatdanhsachdonhang() {
    cout << "\n--- DANH SACH CAC DON HANG ---\n";
    if (soluongdonhang == 0) {
      cout << "Chua co don hang nao.\n";
      return;
    }
    for (int i = 0; i < soluongdonhang; i++) {
      cout << "[" << i + 1 << "] ";
      danhsachdonhang[i].xuatdonhang();
      cout << "------------------------------------\n";
    }
  }

  void thongketheothang(string thangnam) {
    cout << "\n--- THONG KE DON HANG THEO THOI GIAN (" << thangnam << ") ---\n";
    int dem = 0;
    for (int i = 0; i < soluongdonhang; i++) {
      if (danhsachdonhang[i].ngaydat.find(thangnam) != string::npos) {
        danhsachdonhang[i].xuatdonhang();
        cout << "------------------------------------\n";
        dem++;
      }
    }
    if (dem == 0) {
      cout << "Khong co don hang nao trong khoang thoi gian nay.\n";
    } else {
      cout << "Tong so don hang tim thay: " << dem << endl;
    }
  }
};

int main() {
  shop cuahang;
  cuahang.nhapthongtinshop();

  int luachon;
  do {
    cout << "\n============= MENU QUAN LY SHOP DIEN THOAI =============\n";
    cout << "1. Xem thong tin shop\n";
    cout << "2. Them dong dien thoai moi\n";
    cout << "3. Xoa dong dien thoai\n";
    cout << "4. Xem danh sach tat ca dien thoai\n";
    cout << "5. Them don hang moi\n";
    cout << "6. Xem danh sach tat ca don hang\n";
    cout << "7. Thong ke don hang theo thang / ngay\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "Lua chon cua ban: ";
    cin >> luachon;
    cin.ignore();

    switch (luachon) {
    case 1: {
      cuahang.xuatthongtinshop();
      break;
    }
    case 2: {
      dienthoai dt;
      cout << "\n--- Nhap thong tin dien thoai moi ---\n";
      dt.nhapdienthoai();
      cuahang.themdienthoai(dt);
      break;
    }
    case 3: {
      string madt;
      cout << "Nhap ma dien thoai can xoa: ";
      getline(cin, madt);
      cuahang.xoadienthoai(madt);
      break;
    }
    case 4: {
      cuahang.xuatdanhsachdienthoai();
      break;
    }
    case 5: {
      donhang dh;
      cout << "\n--- Nhap don hang moi ---\n";
      dh.nhapdonhang();
      cuahang.themdonhang(dh);
      break;
    }
    case 6: {
      cuahang.xuatdanhsachdonhang();
      break;
    }
    case 7: {
      string thangnam;
      cout << "Nhap thang/nam can thong ke (vi du: 09/2026 hoac 2026): ";
      getline(cin, thangnam);
      cuahang.thongketheothang(thangnam);
      break;
    }
    case 0:
      cout << "Tam biet!\n";
      break;
    default:
      cout << "Lua chon khong hop le, vui long chon lai!\n";
      break;
    }
  } while (luachon != 0);

  return 0;
}

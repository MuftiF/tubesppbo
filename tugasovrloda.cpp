#include <iostream>
#include <string>
#include <cmath>
#define PI 3.14159

using namespace std;

// Kelas dasar untuk semua bangun ruang
class BangunRuang {
protected:
    string nama;
public:
    BangunRuang(string n) : nama(n) {}
    virtual double hitungLuas() const = 0; // Method virtual pure untuk menghitung luas
    string getNama() const { return nama; }
};

// Kelas untuk Persegi
class Persegi : public BangunRuang {
private:
    double sisi;
public:
    Persegi(string n, double s) : BangunRuang(n), sisi(s) {}
    
    double hitungLuas() const override {
        return sisi * sisi;
    }
    
    void tampilInfo() const {
        cout << "Persegi " << nama << " dengan sisi " << sisi << " cm" << endl;
        cout << "Luas: " << hitungLuas() << " cm^2" << endl;
    }
};

// Kelas untuk Persegi Panjang
class PersegiPanjang : public BangunRuang {
private:
    double panjang;
    double lebar;
public:
    PersegiPanjang(string n, double p, double l) : BangunRuang(n), panjang(p), lebar(l) {}
    
    double hitungLuas() const override {
        return panjang * lebar;
    }
    
    void tampilInfo() const {
        cout << "Persegi Panjang " << nama << " dengan panjang " << panjang << " cm dan lebar " << lebar << " cm" << endl;
        cout << "Luas: " << hitungLuas() << " cm^2" << endl;
    }
};

// Kelas untuk Segitiga
class Segitiga : public BangunRuang {
private:
    double alas;
    double tinggi;
public:
    Segitiga(string n, double a, double t) : BangunRuang(n), alas(a), tinggi(t) {}
    
    double hitungLuas() const override {
        return 0.5 * alas * tinggi;
    }
    
    void tampilInfo() const {
        cout << "Segitiga " << nama << " dengan alas " << alas << " cm dan tinggi " << tinggi << " cm" << endl;
        cout << "Luas: " << hitungLuas() << " cm^2" << endl;
    }
};

// Kelas untuk Lingkaran
class Lingkaran : public BangunRuang {
private:
    double jariJari;
public:
    Lingkaran(string n, double r) : BangunRuang(n), jariJari(r) {}
    
    double hitungLuas() const override {
        return PI * jariJari * jariJari;
    }
    
    void tampilInfo() const {
        cout << "Lingkaran " << nama << " dengan jari-jari " << jariJari << " cm" << endl;
        cout << "Luas: " << hitungLuas() << " cm^2" << endl;
    }
};

// Function overloading untuk menggabungkan luas permukaan
double hitungTotalLuas(const BangunRuang& b1, const BangunRuang& b2) {
    return b1.hitungLuas() + b2.hitungLuas();
}

double hitungTotalLuas(const BangunRuang& b1, const BangunRuang& b2, const BangunRuang& b3) {
    return b1.hitungLuas() + b2.hitungLuas() + b3.hitungLuas();
}

double hitungTotalLuas(const BangunRuang& b1, const BangunRuang& b2, const BangunRuang& b3, const BangunRuang& b4) {
    return b1.hitungLuas() + b2.hitungLuas() + b3.hitungLuas() + b4.hitungLuas();
}

int main() {
    // Membuat objek bangun ruang
    Persegi p1("A", 5);
    PersegiPanjang p2("B", 4, 6);
    Segitiga s1("C", 3, 8);
    Lingkaran l1("D", 7);
    
    // Menampilkan informasi masing-masing bangun ruang
    cout << "=== INFORMASI BANGUN RUANG ===" << endl;
    p1.tampilInfo();
    cout << endl;
    p2.tampilInfo();
    cout << endl;
    s1.tampilInfo();
    cout << endl;
    l1.tampilInfo();
    cout << endl;
    
    // Menggunakan function overloading untuk menghitung total luas
    cout << "=== TOTAL LUAS PERMUKAAN ===" << endl;
    cout << "Total luas " << p1.getNama() << " dan " << p2.getNama() 
         << " adalah " << hitungTotalLuas(p1, p2) << " cm^2" << endl;
    
    cout << "Total luas " << p1.getNama() << ", " << p2.getNama() << ", dan " << s1.getNama()
         << " adalah " << hitungTotalLuas(p1, p2, s1) << " cm^2" << endl;
    
    cout << "Total luas " << p1.getNama() << ", " << p2.getNama() << ", " << s1.getNama() << ", dan " << l1.getNama()
         << " adalah " << hitungTotalLuas(p1, p2, s1, l1) << " cm^2" << endl;
    
    return 0;
}
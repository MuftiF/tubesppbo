#include <iostream>

using namespace std;

class BangunRuang {
public:
    virtual double hitungVolume() = 0;
};

class Kubus : public BangunRuang {
private:
    double sisi;
public:
    Kubus(double s) : sisi(s) {}
    double hitungVolume() override {
        return sisi * sisi * sisi;
    }
};

class Balok : public BangunRuang {
private:
    double panjang, lebar, tinggi;
public:
    Balok(double p, double l, double t) : panjang(p), lebar(l), tinggi(t) {}
    double hitungVolume() override {
        return panjang * lebar * tinggi;
    }
};

class Bola : public BangunRuang {
private:
    double jariJari;
public:
    Bola(double r) : jariJari(r) {}
    double hitungVolume() override {
        return (4.0 / 3.0) * 3.14159 * jariJari * jariJari * jariJari;
    }
};

int main() {
    Kubus kubus(5);
    Balok balok(4, 6, 8);
    Bola bola(3);

    double volumeKubus = kubus.hitungVolume();
    double volumeBalok = balok.hitungVolume();
    double volumeBola = bola.hitungVolume();

    double maxVolume = max(volumeKubus, max(volumeBalok, volumeBola));
    double minVolume = min(volumeKubus, min(volumeBalok, volumeBola));

    cout << "Volume Kubus: " << volumeKubus << " satuan kubik\n";
    cout << "Volume Balok: " << volumeBalok << " satuan kubik\n";
    cout << "Volume Bola: " << volumeBola << " satuan kubik\n";
    cout << "Volume terbesar: " << maxVolume << " satuan kubik\n";
    cout << "Volume terkecil: " << minVolume << " satuan kubik\n";

    return 0;
}

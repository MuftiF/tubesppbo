#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <cctype>
using namespace std;

int Saldo = 0;

class DataNasabah {
public:
    string nama, nim, alamat, no_hp;

    bool validangka(const string& input) {
        if (input.empty()) return false;
        for (char c : input) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    bool validhuruf(const string& input) {
        if (input.empty()) return false;
        for (char c : input) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    void inputData() {
        system("cls");
        cout << "=== REGISTRASI NASABAH ===\n";
        
        do {
            cout << "Nama      : ";
            getline(cin, nama);
            if (!validhuruf(nama)) {
                cout << "Nama harus berupa huruf saja! Silakan masukkan kembali.\n";
            }
        } while (!validhuruf(nama));
        
        do {
            cout << "NIM       : ";
            getline(cin, nim);
            if (!validangka(nim)) {
                cout << "NIM harus berupa angka saja! Silakan masukkan kembali.\n";
            }
        } while (!validangka(nim));
        
        do {
            cout << "Alamat    : ";
            getline(cin, alamat);
            if (!validhuruf(alamat)) {
                cout << "Alamat harus berupa huruf saja! Silakan masukkan kembali.\n";
            }
        } while (!validhuruf(alamat));
        
        do {
            cout << "No. HP    : ";
            getline(cin, no_hp);
            if (!validangka(no_hp)) {
                cout << "No. HP harus berupa angka saja! Silakan masukkan kembali.\n";
            }
        } while (!validangka(no_hp));
        
        cout << "\nRegistrasi berhasil!\n";
        system("pause");
        system("cls");
    }

    void tampilkanData() {
        system("cls");
        cout << "\n=== DATA NASABAH ===\n";
        cout << "Nama      : " << nama << "\n";
        cout << "NIM       : " << nim << "\n";
        cout << "Alamat    : " << alamat << "\n";
        cout << "No. HP    : " << no_hp << "\n";
        system("pause");
    }
};

class TransferUang {
public:
    void Transfer(int &Saldo, ofstream &statusFile) {
        system("cls");
        int Rekening, JumlahUang;
        cout << "\n=== TRANSFER UANG ===\n";
        cout << "Saldo Saat Ini: Rp. " << Saldo << "\n\n";
        cout << "Masukkan No Rekening Tujuan: ";
        while (!(cin >> Rekening)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Masukkan Nominal Transfer: Rp. ";
        while (!(cin >> JumlahUang) || JumlahUang < 0) {
            cout << "Input tidak valid! Masukkan nominal yang benar: Rp. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (JumlahUang > Saldo) {
            cout << "\nSALDO TIDAK MENCUKUPI\n";
            cout << "Sisa Saldo: Rp. " << Saldo << "\n";
            statusFile << "TRANSFER GAGAL - Saldo tidak mencukupi, Nominal: Rp. " << JumlahUang << ", Saldo: Rp. " << Saldo << "\n";
        } else {
            Saldo -= JumlahUang;
            cout << "\nTRANSFER BERHASIL\n";
            cout << "No Rekening Tujuan: " << Rekening << "\n";
            cout << "Nominal: Rp. " << JumlahUang << "\n";
            cout << "Sisa Saldo: Rp. " << Saldo << "\n";
            statusFile << "TRANSFER BERHASIL - Rekening Tujuan: " << Rekening << ", Nominal: Rp. " << JumlahUang << ", Sisa Saldo: Rp. " << Saldo << "\n";
        }
        system("pause");
    }
};

class SetorTunai {
public:
    void Setor(int &Saldo, ofstream &statusFile) {
        system("cls");
        int JumlahSetor;
        cout << "\n=== SETOR TUNAI ===\n";
        cout << "Saldo Saat Ini: Rp. " << Saldo << "\n\n";
        cout << "Masukkan Nominal Setor: Rp. ";
        while (!(cin >> JumlahSetor) || JumlahSetor <= 0) {
            cout << "Nominal tidak valid! Masukkan nominal yang benar: Rp. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Saldo += JumlahSetor;
        cout << "\nSETOR TUNAI BERHASIL\n";
        cout << "Nominal Setor: Rp. " << JumlahSetor << "\n";
        cout << "Saldo Saat Ini: Rp. " << Saldo << "\n";
        statusFile << "SETOR TUNAI BERHASIL - Nominal: Rp. " << JumlahSetor << ", Saldo Saat Ini: Rp. " << Saldo << "\n";
        system("pause");
    }
};

class CekSaldo {
public:
    void TampilkanSaldo(int Saldo, ofstream &statusFile) {
        system("cls");
        cout << "\n=== CEK SALDO ===\n";
        cout << "Saldo Saat Ini: Rp. " << Saldo << "\n";
        statusFile << "CEK SALDO - Saldo Saat Ini: Rp. " << Saldo << "\n";
        system("pause");
    }
};

class TarikTunai {
public:
    void Tarik(int &Saldo, ofstream &statusFile) {
        system("cls");
        int JumlahTarik;
        cout << "\n=== TARIK TUNAI ===\n";
        cout << "Saldo Saat Ini: Rp. " << Saldo << "\n\n";
        cout << "Masukkan Nominal Tarik: Rp. ";
        while (!(cin >> JumlahTarik) || JumlahTarik <= 0) {
            cout << "Nominal tidak valid! Masukkan nominal yang benar: Rp. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (JumlahTarik > Saldo) {
            cout << "\nSALDO TIDAK MENCUKUPI\n";
            cout << "Sisa Saldo: Rp. " << Saldo << "\n";
            statusFile << "TARIK TUNAI GAGAL - Saldo tidak mencukupi, Nominal: Rp. " << JumlahTarik << ", Saldo: Rp. " << Saldo << "\n";
        } else {
            Saldo -= JumlahTarik;
            cout << "\nTARIK TUNAI BERHASIL\n";
            cout << "Nominal Tarik: Rp. " << JumlahTarik << "\n";
            cout << "Sisa Saldo: Rp. " << Saldo << "\n";
            statusFile << "TARIK TUNAI BERHASIL - Nominal: Rp. " << JumlahTarik << ", Sisa Saldo: Rp. " << Saldo << "\n";
        }
        system("pause");
    }
};

class LaporanKeuangan {
public:
    void BuatLaporan(const DataNasabah &nasabah, int Saldo, ofstream &statusfile) {
        system("cls");
        cout << "\n=== MEMBUAT LAPORAN KEUANGAN ===\n";
        ofstream laporan("LaporanKeuangan.txt");
        if (laporan.is_open()) {
            laporan << "=== LAPORAN KEUANGAN ===\n";
            laporan << "Tanggal Pembuatan: Tidak tersedia\n\n";
            laporan << "=== DATA NASABAH ===\n";
            laporan << "Nama      : " << nasabah.nama << "\n";
            laporan << "NIM       : " << nasabah.nim << "\n";
            laporan << "Alamat    : " << nasabah.alamat << "\n";
            laporan << "No. HP    : " << nasabah.no_hp << "\n\n";
            laporan << "=== STATUS KEUANGAN ===\n";
            laporan << "Saldo Saat Ini: Rp. " << Saldo << "\n";
            laporan << "=======================\n";
            laporan.close();
            cout << "LAPORAN KEUANGAN BERHASIL DIBUAT!\n";
            cout << "File tersimpan sebagai 'LaporanKeuangan.txt'\n";
            statusfile << "LAPORAN KEUANGAN DIBUAT\n";
        } else {
            cout << "GAGAL MEMBUAT LAPORAN KEUANGAN\n";
            statusfile << "GAGAL MEMBUAT LAPORAN KEUANGAN\n";
        }
        system("pause");
    }
};

int main() {
    DataNasabah nasabah;
    TransferUang transferUang;
    SetorTunai setorTunai;
    CekSaldo cekSaldo;
    TarikTunai tarikTunai;
    LaporanKeuangan laporan;

    ofstream statusFile("LogTransaksi.txt", ios::app);
    if (!statusFile.is_open()) {
        cout << "Gagal membuka file log transaksi!\n";
        return 1;
    }

    nasabah.inputData();
    statusFile << "REGISTRASI NASABAH - Nama: " << nasabah.nama << ", NIM: " << nasabah.nim << "\n";

    int pilihan;
    while (true) {
        system("cls");
        cout << "===============================\n";
        cout << "        ATM BNI DIGITAL        \n";
        cout << "===============================\n";
        cout << "1. TRANSFER UANG\n";
        cout << "2. SETOR UANG\n";
        cout << "3. CEK SALDO\n";
        cout << "4. TARIK TUNAI\n";
        cout << "5. TAMPILKAN DATA NASABAH\n";
        cout << "6. BUAT LAPORAN KEUANGAN\n";
        cout << "7. KELUAR\n";
        cout << "===============================\n";
        cout << "PILIH MENU : ";
        
        while (!(cin >> pilihan)) {
            cout << "Input tidak valid! Pilih menu (1-7): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
            case 1:
                transferUang.Transfer(Saldo, statusFile);
                break;
            case 2:
                setorTunai.Setor(Saldo, statusFile);
                break;
            case 3:
                cekSaldo.TampilkanSaldo(Saldo, statusFile);
                break;
            case 4:
                tarikTunai.Tarik(Saldo, statusFile);
                break;
            case 5:
                nasabah.tampilkanData();
                statusFile << "TAMPILKAN DATA NASABAH\n";
                break;
            case 6:
                laporan.BuatLaporan(nasabah, Saldo, statusFile);
                break;
            case 7:
                system("cls");
                cout << "===============================\n";
                cout << "  TERIMA KASIH TELAH MENGGUNAKAN\n";
                cout << "       ATM BNI DIGITAL!\n";
                cout << "===============================\n";
                statusFile << "KELUAR DARI SISTEM\n";
                statusFile.close();
                return 0;
            default:
                system("cls");
                cout << "PILIHAN TIDAK VALID!\n";
                cout << "Silakan pilih menu 1-7.\n";
                system("pause");
                statusFile << "PILIHAN TIDAK VALID\n";
        }
    }
}
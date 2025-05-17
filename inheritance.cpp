#include <iostream>
using namespace std;

class Hewan {
    private:
    void makan() {
        cout << "Hewan makan" << endl;
    }

    public:
    void bersuara() {
        cout << "Hewan bersuara" << endl;
    }

    void setmakan() {
        makan();
    }
};

class Kucing : public Hewan {
    public:
    void suara() {
        cout << "Kucing mengeong" << endl;
    }
};

int main() {
    Hewan hewan;
    Kucing kucing;

    hewan.setmakan();
    hewan.bersuara();

    kucing.bersuara();
    kucing.suara();
}
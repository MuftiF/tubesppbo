#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}

    void setValue(T val) {
        value = val;
    }

    T getValue() {
        return value;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10);
    Box<string> strBox("Hello");

    intBox.display();      // Output: Value: 10
    strBox.display();      // Output: Value: Hello

    intBox.setValue(42);
    cout << "Updated value: " << intBox.getValue() << endl;  // Output: 42

    return 0;
}
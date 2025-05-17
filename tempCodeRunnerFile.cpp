
template <typename T1, typename T2>
void printData(T1 data1, T2 data2){
    cout << "Data pertama: " << data1 << "; Data kedua: " << data2 << endl;
}

int main(){
    int Integer = 100;
    double Double = 3.5;
    string String = "Praktikum PBO KOM B 24";

    printData(Integer, Double);
    printData(Integer, String);
    printData(Double, String);

    return 0;
}
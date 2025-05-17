

// class Jarak{
//     public:
//     int km, m, cm;

//     Jarak(int kilo = 0, int meter = 0, int centi = 0){
//         km = kilo;
//         m = meter;
//         cm = centi;
//     }

//     void operator++(){
//         km++;
//         m++;
//         cm++;
//     }

//     void display(){
//         cout << "Kilometer: " << km << " km" << endl;
//         cout << "Meter: " << m << " m" << endl;
//         cout << "Centimeter: " << cm << " cm" << endl;
//     }
// };

// int main() {
//     Jarak jarak1;
//     jarak1.display();
//     cout<<endl;
//     cout<<"sesudah"<<endl;
//     cout<<endl;
//     ++jarak1;
//     jarak1.display();

//     return 0;
// }


// class Jarak{
//     public:
//     string namaKota;
//     int jarak;

//     Jarak(string kota = "", int jarak = 0){
//         namaKota = kota;
//         this->jarak = jarak;
//     }

//     Jarak operator+(const Jarak& dist) const{

//         Jarak result;
//         result.namaKota = namaKota + " dan " + dist.namaKota;
//         result.jarak = jarak + dist.jarak;
//         return result;
//     }

//     void print(){
//         cout << "Jarak kota " << namaKota << " adalah " << jarak << " km" << endl;
//     }
// };

// int main() {
//     Jarak jarak1("Medan", 2);
//     Jarak jarak2 = Jarak("Binjai", 10);
//     Jarak jarak3 = jarak1 + jarak2;
//     Jarak jarak4 = jarak3 + jarak1;
//     Jarak jarak[4] = { jarak1, jarak2, jarak3,jarak4 };
//  for (int i = 0; i<4 ; i++){
//     jarak[i].print();
//  }


//     return 0;
// }


// class Jarak{
//     public:
//     int dist1, dist2, dist3;
		
//     int tambah(int x, int y){
// 	    dist1 = x;
// 	    dist2 = y;
// 	    return dist1 + dist2;
//     }
    
//     int tambah(int x, int y, int z){
// 	    dist1 = x;
// 	    dist2 = y;
// 	    dist3 = z;
// 	    return dist1 + dist2 + dist3;
//     }


//     //   int tambah(int x, double y){
// 	//     dist1 = x;
// 	//     dist2 = y;
// 	//     return dist1 + dist2 ;
//     // }


//     // int tambah(int z, int y, int x){
// 	//     dist1 = x;
// 	//     dist2 = y;
// 	//     dist3 = z;
// 	//     return dist1 + dist2 + dist3;
//     // }



    

// };

// int main() {
//     Jarak jarak1;
// 		cout << jarak1.tambah(1, 3) << endl;
// 		cout << jarak1.tambah(1, 3, 5) << endl;

//     return 0;
// }



// Template Function single


// template <typename T>
// T getMax(T x, T y){
//     return (x > y) ? x : y;
// }

// int main(){
//     int a = 20;
//     int b = 10;
//     cout << "Nilai max antara " << a << " dan " << b << " adalah " << getMax(a, b) << endl;

//     float c = 5.4;
//     float d = 4.9;
//     cout << "Nilai max antara " << c << " dan " << d << " adalah " << getMax(c, d) << endl;

//     char e = 'z';
//     char f = 'b';
//     cout << "Nilai max antara " << e << " dan " << f << " adalah " << getMax(e, f) << endl;

//     return 0;
// }



// Template Function multitype


// template <typename T1, typename T2>
// void printData(T1 data1, T2 data2){
//     cout << "Data pertama: " << data1 << "; Data kedua: " << data2 << endl;
// }

// int main(){
//     int Integer = 100;
//     double Double = 3.5;
//     string String = "Praktikum PBO KOM B 24";

//     printData(Integer, Double);
//     printData(Integer, String);
//     printData(Double, String);

//     return 0;
// }


template <typename T1, typename T2>
void tmapilkan(T1 data1, T2 data2){
    cout << "Data pertama: " << data1 << " ; Data kedua: " << data2<<endl;

}

int main(){
    int Integer = 100;
    double Double = 3.5;
    string String = "Praktikum PBO KOM B 24";
    string Nama = " San Jossye Sitanggang";
    int kelas = 1;

    tmapilkan(Nama,kelas);
    tmapilkan(Integer, Double);
    tmapilkan(Integer, String);
    tmapilkan(Double, String);

}
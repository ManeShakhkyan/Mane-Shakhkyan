#include <iostream>
//#pragma pack 4
struct Car{
//    char* model;
//    int year[3];
  //  short a;
    //char* color;
    double a;
    int k;
    int b[5];

//    char k;
int print_year() {
//        std::cout << year << "\n";
    }
};

int main(){
    Car obj;

//    obj.year = 2020;
  //  obj.model = "BMW";
//    std::cout << obj.year << "\n";
    obj.print_year();
    std::cout << sizeof(Car) << "\n";
    return 0;
}

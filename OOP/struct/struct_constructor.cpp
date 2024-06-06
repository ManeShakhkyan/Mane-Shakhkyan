#include <iostream>

struct Car{
    char* model;
    int year;
    char* color;

    Car () {
        std::cout << "Done!\n";
    }

    ~Car(){
        std::cout << "Destroyed\n";
    }

};

int main(){
    Car obj;
    obj.year = 2020;

    return 0;
}

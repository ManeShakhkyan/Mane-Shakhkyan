#include <iostream>

struct Student {
    char* name;
    unsigned int id;
    int grade;

    Student() : name(nullptr), id(0), grade(0) {}

    Student(char* name, unsigned int id, int grade) {
        if(!isValidGrade(grade)){
            std::cout << "Grade must be in the range of 0-100.\n";
            grade = 0;
        }

        this->grade = grade;
        this->id = id;

        if (!isValidName(name)) {
            std::cout << "Name must contain only letters!\n";
            this->name = nullptr;
            return;
        }
        
        int length = 0;

        while (name[length] != '\0') {
            ++length;
        }

        this->name = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            this->name[i] = name[i];
        }
    }

    ~Student() {
        delete[] name;
    }

    bool setName(char* name) {
        if (!isValidName(name)) {
            std::cout << "Name must contain only letters!\n";
            return false;
        }

        int length = 0;
        while (name[length] != '\0') {
            ++length;
        }
        delete[] this->name;
        this->name = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            this->name[i] = name[i];
        }
        return true;
    }    

    bool setGrade(int grade) {
        if (!isValidGrade(grade)) {
            std::cout << "Grade must be in the range of 0-100.\n";
            return false;
        }

        this->grade = grade;
        return true;
    }

    bool setId(unsigned int id) {
        this->id = id;
        return true;
    }

    char* getName() {
        return name;
    }

    unsigned int getId() {
        return id;
    }

    int getGrade()  {
        return grade;
    }

    void displayInfo()  {
        if (!name) {
            std::cout << "Information is not complete!";
            return;
        } 
        std::cout << "Name: " << name << "\n";
        std::cout << "Grade: " << grade << "\n";
        std::cout << "Id: " << id << "\n";
    }

private:
    bool isValidName(char* name){
        for (int i = 0; name[i] != '\0'; ++i) {
            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))) {
                return false;
            }
        }
        return true;
    }

    bool isValidGrade(int grade){
        return grade <= 100 && grade >= 0;
    }
};

int main() {
    char name1[] = "Jim Carrey"; 
    char name2[] = "Tom Cruise";

    Student student(name1, 12345, -90);

    std::cout << "Initial Information:\n";
    student.displayInfo();
    student.setName(name2);
    student.setGrade(95);
    student.setId(54321);

    std::cout << "\nModified Information:\n";
    student.displayInfo();

    return 0;
}

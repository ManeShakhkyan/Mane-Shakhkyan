#include <iostream>

struct Student {
    char* name;
    unsigned int id;
    unsigned int grade;

    Student() : name(nullptr), id(0), grade(0) {}

    Student(char* name, unsigned int id, unsigned int grade) {
        int length = 0;

        while (name[length] != '\0') {
            ++length;
        }

        this->name = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            this->name[i] = name[i];
        }

        if (!isValidName(this->name)) {
            std::cout << "Name must contain only letters!\n";
            delete[] this->name;
            this->name = nullptr;
        }
        
        this->id = id;
        this->grade = grade;
    }

    ~Student() {
        delete[] name;
    }

    void setName(char* name) {
        if (!isValidName(name)) {
            std::cout << "Name must contain only letters!\n";
            return;
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
    }

    void setGrade(unsigned int grade) {
        if (grade > 100) {
            std::cout << "Grade must be in the range of 0-100.\n";
            return;
        }

        this->grade = grade;
    }

    void setId(unsigned int id) {
        this->id = id;
    }

    char* getName()  {
        return name;
    }

    unsigned int getId() {
        return id;
    }

    unsigned int getGrade()  {
        return grade;
    }

    void displayInfo()  {
        if (name == nullptr) {
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
};

int main() {
    char name1[] = "Jim Carrey"; 
    char name2[] = "Tom Cruise";

    Student student(name1, 12345, 90);

    std::cout << "Initial Information:\n";
    student.displayInfo();
    student.setName(name2);
    student.setGrade(95);
    student.setId(54321);

    std::cout << "\nModified Information:\n";
    student.displayInfo();

    return 0;
}

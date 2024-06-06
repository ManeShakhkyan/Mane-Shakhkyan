#include <iostream>

class Person{
	public:
	
	Person();
	Person(char*; int){
		this->name = new char[strlen(name)];
		// TODO validation
		this->age = age;
	}
	~Person();

	bool setAge(int);
	int getAge;


	private:
		char* name = nullptr;
		int age = 0;

};

int main(){

	return 0;
}

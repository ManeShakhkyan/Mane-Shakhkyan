#include <iostream>
#include "myContainer.cpp"

int main() {
	MyContainer<int> container;

	container.push(10);
	container.push(20);
	container.push(30);

	std::cout << "Container size: " << container.getSize() << "\n";

	for (int i = 0; i < container.getSize(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";

	container.insert(1, 15);

	std::cout << "After insert at index 1: ";
	for (int i = 0; i < container.getSize(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";

	container.update(2, 25);

	std::cout << "After update at index 2: ";
	for (int i = 0; i < container.getSize(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";

	container.reset(3);

	std::cout << "After delete at index 3: ";
	for (int i = 0; i < container.getSize(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";

	container.pop();

	std::cout << "After pop: ";
	for (int i = 0; i < container.getSize(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";

	container.clear();

	std::cout << "After clear, container size: " << container.getSize() << "\n";

	return 0;
}

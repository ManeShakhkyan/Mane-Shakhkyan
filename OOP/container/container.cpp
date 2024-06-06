#include <iostream>

template <typname T>
class MyContainer{
	private:
		T* data;
		int capacity;
		int size;
	
	void resize(int capacity){
		T* newData = new T[capacity];

		for(int i = 0; i < size; ++i){
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		this->capacity = capacity;
	}

	public:
		MyContainer() : data(nullptr), capacity(0), size(0) {}
		
		MyContainer(const MyContainer& other){
			T* data = new T[other.capacity]
			
			for(int i = 0; i < other.size; ++i){
				data[i] = other.data[i];
			}

			size = other.size;
			capacity = other.capacity;	
		}

		~MyContainer() {
			delete [] data;
		}
		
		MyContainer& operator= (const MyContainer& other){
			if(this == &other){
				return *this;
			}
			
			if(data != nullptr){
				delete[] data;
			}

			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];			
			for(int i = 0; i < size; ++i){
				data[i] = other.data[i];
			}
		
			return *this;
		}		

		MyContainer& operator= (MyContainer&& other){
			if(this == &other){
				return *this;
			}
			
			if(data != nullptr){
				delete[] data;
			}

			size = other.size;
			capacity = other.capacity;
			data = other.data;

			other.size = 0;
			other.capacity = 0;
			other.data = nullptr;

			return *this;
		}
		 
		T& operator[](int index) {
			if(index > size || index < 0){
				std::cout << "Index out of range!\n";
				return nullptr;
			}

			return data[index];
		}

		bool insert(int index, const T& value){
			if(index > size || index < 0){
				return false;
			}

			if(size == capacity){
				resize(capacity == 0 ? 1 : capacity*2)
			}

			for(int i = size; i > index; --i){
				data[i] = data[i - 1];
			}

			data[index] = value;
			++size;

			return true;
		}

		void push(const T& element){
			if(size == capacity){
				resize(capacity == 0 ? 1 : capacity*2)
			}

			data[size++] = value;
		}

		void pop(){
			newData = T[capacity-1];

			for(int i = 0; i < size)
		}
}

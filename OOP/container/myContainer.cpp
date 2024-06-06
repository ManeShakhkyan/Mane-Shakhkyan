#include <iostream>

template <typename T>
class MyContainer{
	private:
		T* data;
		int size;

		bool resize(int size){
			if(size < 0){
				return false;
			}

			T* newData = new T[size];

			for(int i = 0; i < (this->size > size ? size : this->size); ++i){
				newData[i] = data[i];
			}

			delete[] data;
			data = newData;
			this->size = size;

			return true;
		}

	public:
		MyContainer() : data(nullptr),size(0) {}

		MyContainer(const MyContainer& other){
			data = new T[other.size];

			for(int i = 0; i < other.size; ++i){
				data[i] = other.data[i];
			}

			size = other.size;
		}

		MyContainer(MyContainer&& other)  : data(other.data), size(other.size) {
			other.data = nullptr;
			other.size = 0;
		}

		~MyContainer() {
			clear();
		}

		MyContainer& operator= (const MyContainer& other){
			if(this == &other){
				return *this;
			}

			delete[] data;

			size = other.size;
			data = new T[size];	

			for(int i = 0; i < size; ++i){
				data[i] = other.data[i];
			}

			return *this;
		}

		MyContainer& operator= (MyContainer&& other){
			if(this == &other){
				return *this;
			}

			delete[] data;

			size = other.size;
			data = other.data;

			other.data = nullptr;
			other.size = 0;
			
			return *this;
		}

		T& operator[](int index) {
			if(index > size || index < 0){
				std::cout << "Index out of range!\n";
			}

			return data[index];
		}

		bool insert(int index, const T& value){
			if(index > size || index < 0){
				return false;
			}

			if(!resize(size + 1)){
				return false;
			}

			for (int i = size - 1; i > index; --i) {
				data[i] = data[i - 1];
			}   

			data[index] = value;            
			
			return true;
		}

		void push(const T& element){
			resize(size + 1);
			data[size - 1] = element;
		}

		void pop(){
			if(resize(size - 1)){
				--size;
			}
		}

		bool update(int index, const T& value){
			if(index > size || index < 0){
				return false;
			}

			data[index] = value;
			return true;
		}

		bool reset(int index) { 
			if(index > size || index < 0){
				return false;
			}

			for (int i = index; i < size - 1; ++i) {
				data[i] = data[i + 1];
			}

			resize(--size);
			return true;
		}

		void clear() {
			delete[] data;
			data = nullptr;
			size = 0;
		}

		int getSize() const{
			return size;
		}

};


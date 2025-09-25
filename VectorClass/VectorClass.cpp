#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class VectorClass
{
	T* arr;
	int size;
public:
	VectorClass() {}
	~VectorClass() {
		delete[] arr;
	}
	void push_back(T value) {
		T* newArr = new T[size + 1];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		newArr[size] = value;
		delete[] arr;
		arr = newArr;
		size++;
	}
	void pop_back() {
		if (!size == 0) {
			T* newArr = new T[size - 1];
			for (int i = 0; i < size - 1; i++) {
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			size--;
		}
		else {
			cout << "Vector is empty" << endl;
		}
	}
	void swap(int index1, int index2) {
		if (index1 < size && index2 < size) {
			T temp = arr[index1];
			arr[index1] = arr[index2];
			arr[index2] = temp;
		}
		else {
			cout << "Index out of bounds" << endl;
		}
	}
	void begin() {
		if (size > 0) {
			cout << arr[0] << endl;
		}
		else {
			cout << "Vector is empty" << endl;
		}
	}
	void end() {
		if (size > 0) {
			cout << arr[size - 1] << endl;
		}
		else {
			cout << "Vector is empty" << endl;
		}
	}
	void insert(int index, T value) {
		if (index < size) {
			T* newArr = new T[size + 1];
			for (int i = 0; i < index; i++) {
				newArr[i] = arr[i];
			}
			newArr[index] = value;
			for (int i = index; i < size; i++) {
				newArr[i + 1] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			size++;
		}
		else {
			cout << "Index out of bounds" << endl;
		}
	}

	void SHow() {
		for (int i = 0; i < size; i++) {
			if (i != size - 1) {
				cout << arr[i] << ", ";
			}
			else {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}

	void setSize(int size) {
		this->size = size;
		arr = new T[size];
	}
	int getSize() {
		return size;
	}
};

class myException : public exception {
private:
	string message;
public:
	myException(string message) { this->message = message; }
	const char* what() const noexcept override {
		return message.c_str();
	}
};

int main()
{
	try {
		VectorClass<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.SHow();
		vec.pop_back();
		vec.SHow();
		vec.insert(1, 4);
		vec.SHow();
		vec.swap(0, 1);
		vec.SHow();
		vec.begin();
		vec.end();
		int serch_index;
		cout << "Enter index of number to search: ";
		cin >> serch_index;
		bool founded = false;
		for (int i = 0; i < vec.getSize(); i++) {
			if (i == serch_index) {
				cout << "Number found: " << i << endl;
				founded = true;
				break;
			}
		}
		if (!founded) {
			throw myException("Number not found");
		}
	}
	catch (myException e) {
		cout << e.what() << endl;
	}
}

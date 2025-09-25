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
};

int main()
{
	VectorClass<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.SHow();
	vec.pop_back();
	vec.SHow();
	vec.swap(0, 3);
	vec.SHow();
	vec.begin();
	vec.end();
	vec.insert(2, 10);
	vec.SHow();
}

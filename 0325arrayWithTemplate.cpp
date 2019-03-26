/* vector 직접 구현해봄 template 함수로 */
#include <iostream>
#include <string>
using namespace std;
class Complex {
	double real;
	double image;
public:
	Complex(double real = 0, double image = 0) : real(real), image(image) {}
	double getReal() { return real; }
	double getImage() { return image; }
	void setReal(double real) { this->real = real; }
	void setImage(double image) { this->image = image; }
	friend ostream& operator << (ostream& os, Complex &cp);
};
ostream& operator << (ostream& os, Complex &cp) {
	os << "(" << cp.real << "+" << cp.image << "i" << ")";
	return os;
}
template <class T>
class ArrayList {
	int capacity;
	int size;
	T *arrayLink;
public:
	ArrayList() {
		this->size = 0;
		this->capacity = 4;
		arrayLink = new T[capacity];
	}
	int getSize() { return size; }
	int getCapacity() { return capacity; }
	void insertLast(const T newItem);
	void reSize(const int newSize);
	void print() const;
	bool isEmpty() const { return size == 0; }
	void insertItem(const T newItem, const int k);
	T deleteItem(const int k); //인덱스 k인 곳 삭제
	T peek(const int k);//인덱스 k인 배열 읽기
};
template <class T>
T ArrayList<T>::peek(int k) {
	if (k == size) {
		string str = "배열의 크기에 벗어난 인덱스";
		str += to_string(k);
		str += "입니다.";
		throw str;
	}
	if (isEmpty()) cout << "배열이 비어있음" << endl;
	return arrayLink[k];
}
template <class T>
void ArrayList<T>::reSize(const int newSize) {
	//크기가 newSize의동적배열 만들고 데이터 이동하는 프로그램 작성
	T *temp = new T[newSize];
	for (int i = 0; i < size; i++) temp[i] = arrayLink[i];
	arrayLink = temp; //이제는 이 temp가 새로운 arrayLink가 되었다는 식으로 이해하면 될듯..
}
template <class T>
void ArrayList<T>::insertLast(const T newItem) {
	if (size == capacity) {
		//크기를 2배로 들린 변수를 resize()로 송부하는 프로그램 작성
		capacity *= 2;
		reSize(capacity);
	}
	arrayLink[size++] = newItem;
}
template <class T>
void ArrayList<T>::print() const {
	if (isEmpty())
		cout << "배열이 비어있음";
	else
		for (int i = 0; i < size; i++) cout << arrayLink[i] << "\t";
	cout << endl;
}
template <class T>
void ArrayList<T>::insertItem(const T newItem, const int k) {
	if (k > size) {
		string str = "배열의 크기에 벗어난 인덱스";
		str += to_string(k);
		str += "입니다.";
		throw str; //허걱
	}
	if (size == capacity) {
		capacity *= 2;
		reSize(capacity);
	}
	for (int i = size - 1; i >= k; i--)
		arrayLink[i + 1] = arrayLink[i];
	arrayLink[k] = newItem;
	size++;
}
template <class T>
T ArrayList<T>::deleteItem(int k) {
	if (k >= size) {
		string str = "배열의 크기에 벗어난 인덱스";
		str += to_string(k);
		str += "입니다.";
		throw str;
		/*cout << "배열의 크기에 벗어난 인덱스 입니다." << endl;
		return T();*/
	}
	if (isEmpty()) cout << "배열이 비었음" << endl;
	T item = arrayLink[k];
	for (int i = k; i < size; i++) arrayLink[i] = arrayLink[i + 1];
	size--;
	if (size > 0 && size == capacity/4) {
		capacity /= 4;
		reSize(capacity);
	}
	return item;
}
template <class T>
int main() {
	try {
		ArrayList<string> arrColor;
		arrColor.insertLast("green");	arrColor.insertLast("red");
		arrColor.insertLast("blue");	arrColor.insertLast("pink");
		arrColor.insertLast("yellow"); arrColor.insertLast("black");
		arrColor.print();
		arrColor.insertItem("white", 2);
		arrColor.print();
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.capacity() << endl;

		cout << "검색한 값:" << arrColor.peek(6) << endl;
		arrColor.deleteItem(5); arrColor.print();
		arrColor.deleteItem(2);	arrColor.print();
		arrColor.deleteItem(1);	arrColor.print();
		arrColor.deleteItem(0);	arrColor.print();
		arrColor.deleteItem(0);	arrColor.print();
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.capacity() << endl;

		ArrayList<Complex> arrCpx;
		arrCpx.insertLast(Complex(2, 3));	arrCpx.insertItem(Complex(2, 3), 1);
		arrCpx.insertItem(Complex(2, 3),2);	arrCpx.insertLast(Complex(2, 3));
		arrCpx.insertLast(Complex(2, 3));	arrCpx.insertLast(Complex(2, 3));
		arrCpx.insertItem(100, 3);
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.capacity() << endl;
		arrCpx.print();

		arrCpx.deleteItem(5); arrCpx.print();
		arrCpx.deleteItem(2); arrCpx.print();
		arrCpx.deleteItem(1); arrCpx.print();
		arrCpx.deleteItem(0); arrCpx.print();
		arrCpx.deleteItem(0); arrCpx.print();
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.capacity() << endl;
	}
	catch (string str) { cout << str << endl; }
}

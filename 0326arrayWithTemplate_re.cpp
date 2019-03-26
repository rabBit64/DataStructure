#include <iostream>
#include <string>
using namespace std;
//complex class 만들어보기
class Complex {
	double real, image;
public:
	Complex(double real=0, double image=0): real(real), image(image) {}
	void setReal(double real) { this->real = real; }
	void setImage(double image) { this->image = image; }
	double getReal() { return real; }
	double getImage() { return image; }
	friend ostream& operator<<(ostream& os, Complex &cp);
};
ostream& operator << (ostream& os, Complex &cp) {
	os << "(" << cp.real << "+" << cp.image << "i" << ")";
	return os;
}
//ArrayList class 만들어보기 - template 으로!
template <class T>
class ArrayList {
	int capacity;	
	int size;
	T *arrayLink;
public:
	ArrayList() {// 생성자. 입력값 없고
		this->capacity = 4;
		this->size = 0;
		arrayLink = new T[capacity]; //크기 4인 동적배열 생성
	}
	//필요한 함수들 정의
	int getSize() { return size; }
	int getCapacity() { return capacity; }
	//insertLast, reSize, print, isEmpty, insertItem, deleteItem, peek 만들어보기
	void insertLast(const T newItem);
	void reSize(const int newSize);
	void print() const; //뭔가 이렇게 찍어보는건 const를 붙이는듯(함수에 의해 값 변경되면 안되니까??)
	bool isEmpty() const { return size ==0; };
	void insertItem(const T newItem, const int k);
	T deleteItem(const int k);
	T peek(const int k);
};
//define 해야하는 함수: insertLast, reSize, print, insertItem, deleteItem, peek
template <class T>
void ArrayList<T>::insertLast(const T newItem) {
	//뭐부터 해야할까... 인스턴스 생성? no(메인함수에서) 일단 넣을곳 있는지부터 확인
	if(size == capacity) { //꽉 찼으면
		capacity *=2;
		reSize(capacity);
	}
	//어떻게 넣지...마지막에
	arrayLink[size++] = newItem;
}
template <class T>
void ArrayList<T>::reSize(const int newSize) {
	//newSize의 동적배열 하나 새로 만들기!
	T *temp = new T[newSize];
	//하나씩 옮기기!
	for(int i=0; i<size; i++) temp[i] = arrayLink[i];
	delete [] arrayLink; //이거 해줘야하지 않나?
	arrayLink = temp;
}
template <class T>
void ArrayList<T>::print() const{
	//프린트... 포문 해야하나
	if(isEmpty()) cout<< "비어있음"; 
	for(int i=0; i<size; i++) cout<<arrayLink[i]<<"\t";
}
template <class T>
void ArrayList<T>::insertItem(const T newItem, const int k) {
	if(size==capacity) {
		capacity *= 2;
		reSize(capacity);
	}
	//크기 벗어난 인덱스도 해주기
	if(size<k) {
		cout<<"크기를 벗어난 인덱스입니다.";
	}
	for(int i=size-1; i>=k; i--) { //size-1 해줘야함
		arrayLink[i+1] = arrayLink[i];
	}
	arrayLink[k] = newItem;
	size++;
}
template <class T>
T ArrayList<T>::deleteItem(const int k){
	if(k>=size) cout<<"크기를 벗어난 인덱스"; return T();
	//비었을때도 해주기
	if(isEmpty()) cout<<"배열이 비어있음"; return T();
	//어떤 item이 삭제되었는지 알려면 일단 담는다
	T item = arrayLink[k];
	for(int i=k; i<size-1; i++) {
		arrayLink[k] = arrayLink[k+1];
		size--;
	}
	//사이즈도 동적으로 줄여주기
	if(size>0 && size == capacity / 4) {
		capacity /= 2;
		reSize(capacity);
	}
	return item;
}
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
int main() {
	try {
		ArrayList<string> arrColor; //main함수에서 인스턴스 생성
		arrColor.insertLast("green");	arrColor.insertLast("red");
		arrColor.insertLast("blue");	arrColor.insertLast("pink");
		arrColor.insertLast("yellow"); arrColor.insertLast("black");
		arrColor.print();
		arrColor.insertItem("white", 2);
		arrColor.print();
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;

		cout << "검색한 값:" << arrColor.peek(6) << endl;
		arrColor.deleteItem(5); arrColor.print();
		arrColor.deleteItem(2);	arrColor.print();
		arrColor.deleteItem(1);	arrColor.print();
		arrColor.deleteItem(0);	arrColor.print();
		arrColor.deleteItem(0);	arrColor.print();
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;
		cout << "크기: " << arrColor.getSize() << "용량:" << arrColor.getCapacity() << endl;

		ArrayList<Complex> arrCpx;
		arrCpx.insertLast(Complex(2, 3));	arrCpx.insertItem(Complex(2, 3), 1);
		arrCpx.insertItem(Complex(2, 3),2);	arrCpx.insertLast(Complex(2, 3));
		arrCpx.insertLast(Complex(2, 3));	arrCpx.insertLast(Complex(2, 3));
		arrCpx.insertItem(100, 3);
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
		arrCpx.print();

		arrCpx.deleteItem(5); arrCpx.print();
		arrCpx.deleteItem(2); arrCpx.print();
		arrCpx.deleteItem(1); arrCpx.print();
		arrCpx.deleteItem(0); arrCpx.print();
		arrCpx.deleteItem(0); arrCpx.print();
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
		cout << "크기: " << arrCpx.getSize() << "용량:" << arrCpx.getCapacity() << endl;
	}
	catch (string str) { cout << str << endl; }
}

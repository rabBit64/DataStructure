/* 정답. + 동적배열로 확장시키기*/

#include <iostream>
using namespace std;
class ArrayList {
	int capacity;
	int size;
	int *arrayLink;
public:
	ArrayList() {
		this->size = 0;
		this->capacity = 4;
		arrayLink = new int[capacity];
	}
	int getSize() { return size; }
	int isEmpty() { return size == 0; }
	int getCapacity() { return capacity; }
	void insertItem(int newItem, int k);
	int deleteItem(int k); //인덱스 k인 곳 삭제
	void insertLast(int newItem);
	int peek(int k);//인덱스 k인 배열 읽기
	void reSize(int newSize);
	void print();
};
int ArrayList::peek(int k) {
	if (k == size) {
		cout << "배열의 크기에 벗어난 인덱스 입니다." << endl;
	}
	if (isEmpty()) cout << "배열이 비어있음" << endl;
	return arrayLink[k];

}

void ArrayList::reSize(int newSize) {
	//크기가 newSize의동적배열 만들고 데이터 이동하는 프로그램 작성
	int *temp = new int[newSize];
	for (int i = 0; i < size; i++) temp[i] = arrayLink[i];
	arrayLink = temp; 
}
void ArrayList::insertLast(int newItem) {
	if (size == capacity) {
		//크기를 2배로 들린 변수를 resize()로 송부하는 프로그램 작성
		capacity *= 2;
		reSize(capacity);
	}
	arrayLink[size++] = newItem;
}
void ArrayList::print() {
	if (isEmpty())
		cout << "배열이 비어있음";
	else
		for (int i = 0; i < size; i++) cout << arrayLink[i] << "\t";
	cout << endl;
}
void ArrayList::insertItem(int newItem, int k) {
	if (k > size) {
		cout << "배열의 크기에 벗어난 인덱스 입니다." << endl;
		return;
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
int ArrayList::deleteItem(int k) {
	if (k >= size) {
		cout << "배열의 크기에 벗어난 인덱스 입니다." << endl;
		return 0;
	}
	if (isEmpty()) cout << "배열이 비었음" << endl;
	int item = arrayLink[k];
	for (int i = k; i < size; i++) arrayLink[i] = arrayLink[i + 1];
	size--;
	if (size > 0 && size == capacity/4) {
		capacity /= 4;
		reSize(capacity);
	}
	return item;
}
int main() {
	ArrayList arr;
	arr.insertLast(10);	arr.insertItem(20, 1);	arr.insertItem(30, 2);
	arr.insertLast(40);	arr.insertLast(50);	arr.insertLast(60);
	arr.print();
	arr.insertItem(100, 4); arr.print();
	cout << "크기: " << arr.getSize() << "용량: " << arr.getCapacity() << endl;
	cout << "선택한 값: " << arr.peek(5) << endl;
	cout << endl;
	arr.deleteItem(5);	arr.print();
	arr.deleteItem(2);	arr.print();
	arr.deleteItem(1); 	arr.print();	arr.deleteItem(0);	arr.print();
	arr.deleteItem(0);	arr.print();
	cout << "크기: " << arr.getSize() << "용량: " << arr.getCapacity() << endl;
}

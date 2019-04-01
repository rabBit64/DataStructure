/*멤버변수 초기화하는거 이해하기. 사이즈 줄이는것도!*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue {
private:
	T *queue;
	int front, rear, capacity;
public:
	Queue(int queueCapacity = 5);
	bool IsEmpty();
	bool IsFull();
	T& Front();
	T& Rear();
	void Push(const T& item);
	void Pop();
	void Print();
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

//size 멤버변수 만들어서
template <class T>
void Queue<T>::Pop() {
	if(IsEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front+1)%capacity;
	queue[front].~T();
}
template <class T>
inline bool Queue<T>::IsEmpty() { return front == rear; }
template <class T>
inline bool Queue<T>::IsFull() { return front == (rear + 1) % capacity; }
template <class T>
inline T& Queue<T>::Front() {
	if(IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}
template <class T>
inline T& Queue<T>::Rear() {
	if(IsEmpty()) throw "Queue is empty. No front element";
	return queue[rear];
}
template <class T>
void Queue<T>::Push(const T& x) {
	if (IsFull()) {
		T *newQueue = new T[capacity*2];
		int start = (front + 1) % capacity;
		int j = 0;
		for (int i =start; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
			newQueue[j] = queue[i];
			j++;
		}
		//멤버변수 변화시켜주기
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}
	rear = (rear + 1) % capacity; queue[rear] = x;
}

template <class T>
void Queue<T>::Print() {
	cout << "capacity=" << capacity << " " << "front=" << front <<" "<<"rear=" << rear << " " << endl;
	for (int i = (front + 1) % capacity; i != (rear + 1) % capacity; i = (i + 1) % capacity)
		cout << " " << "queue[" << i << "]=" << queue[i] << endl;
	cout << endl;
}
/*
int main() {
	try {
		Queue<int> Q_queue(5);
		Q_queue.Push(5); Q_queue.Push(40);
		Q_queue.Print();
		Q_queue.Push(3);
		Q_queue.Pop(); Q_queue.Pop();
		Q_queue.Push(43);
		Q_queue.Push(49);
		Q_queue.Push(490);
		Q_queue.Print();
	}
	catch (char* str) { cout << str << endl; }
}
*/

int main() {
	try {
		Queue<int> Q_queue(4);
		Q_queue.Push(5); Q_queue.Push(40);
		Q_queue.Push(3); //Q_queue.Pop(); Q_queue.Pop();
		Q_queue.Push(43); Q_queue.Push(49);
		Q_queue.Push(490); Q_queue.Print();
		
		Q_queue.Push(55); Q_queue.Push(45);
		Q_queue.Pop(); Q_queue.Pop();
		Q_queue.Pop(); Q_queue.Pop();
		Q_queue.Push(55); Q_queue.Push(45);
		Q_queue.Print();
		
		Queue<string> aqueue(10);
		aqueue.Push("sky"); aqueue.Push("sky1");
		aqueue.Push("sky2");
		aqueue.Print();
	}
	catch (char* str) { cout << str << endl; }
}

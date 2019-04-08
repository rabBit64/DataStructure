#include <iostream>
#include <string>
using namespace std;
template <class T>
class Queue {
private:
	T *queue;
	int front,
		size,
		rear,
		capacity;
public:
	Queue(int queueCapacity = 4 );
	bool IsEmpty() { return front == rear; }
	bool IsFull() { return front == (rear + 1) % capacity; }
	T& Front() { 
		if(IsEmpty()) {
			cout<<"Queue is empty. No front element"<<endl;
			return T();
		}
		return queue[(front+1) % capacity];
	}
	T& Rear() {
		if(IsEmpty()) {
			cout<<"Queue is empty. No front element"<<endl;
			return T();
		}
		return queue[rear];
	}
	void Push(const T& item);
	void Pop();
	void reSize(int newSize);
	void Print();
};
template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
	queue = new T[capacity];
	front = rear = size =  0;
}
template <class T>
void Queue<T>::Push(const T& item) {
	if (IsFull()) {
		reSize(capacity * 2);
	}
	rear = (rear + 1) % capacity; queue[rear] = item;
	size++;
}
template <class T>
void Queue<T>::Pop() {
	front = (front + 1) % capacity;
	queue[front].~T();
	size --;
	cout<<"size:"<<size;
}
template <class T>
void Queue<T>::reSize(int newSize) {
	if(IsFull()){
		T* newQueue = new T[newSize];
		int start = (front + 1) % capacity;
		int j = 0;
		for(int i = start; i != (rear+1)%capacity; i = (i+1)%capacity) {
			newQueue[j] =  queue[i];
			j++;
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue; queue = newQueue;
	}
	if(size == capacity / 4){
		T* newQueue = new T[newSize];
		int start = (front + 1) % capacity;
		int j = 0;
		for(int i = start; i != (rear+1)%capacity; i = (i+1)%capacity) {
			newQueue[j] = queue[i];
			j++;
		}
		front = capacity / 2 - 1;
		rear = capacity - 2;
		capacity /=2;
		delete[] queue; queue = newQueue;
	}
}
template <class T>
void Queue<T>::Print() {
	cout << "capacity=" << capacity << " " << "front=" << front <<" "<<"rear=" << rear << " " <<"size=" << size<< endl;
	for (int i = (front + 1) % capacity; i != (rear + 1) % capacity; i = (i + 1) % capacity)
		cout << " " << "queue[" << i << "]=" << queue[i] << endl;
	cout << endl;
}
int main() {	
	try {
		Queue<int> Q_queue(4);
		Q_queue.Push(5); Q_queue.Push(40);
		Q_queue.Push(3); Q_queue.Pop(); Q_queue.Pop();
		Q_queue.Push(43); Q_queue.Push(49);
		Q_queue.Push(490); Q_queue.Print();
		Q_queue.Push(55); Q_queue.Push(45);
		Q_queue.Push(30); Q_queue.Push(45);
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

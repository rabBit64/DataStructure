#include <iostream>
#include <string>
using namespace std;
template <class T>
class Queue {
private:
	T *queue; //array for queue elements
	int front, // one counterclockwise from front
		size, //number of element
		rear, //array position of rear element
		capacity; //capacity of queue array
public:
	Queue(int queueCapacity = 4 );
	bool IsEmpty() { return front == rear; }
	bool IsFull() { return front == (rear + 1) % capacity; }
	T& Front() { //return the element at the front of the queue
		if(IsEmpty()) {
			cout<<"Queue is empty. No front element"<<endl;
			return T();
		}
		return queue[(front+1) % capacity];
	}
	T& Rear() { //return the element at the rear of the queue
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
void Queue<T>::Push(const T& item) { //add x at rear of queue
	if (IsFull()) {
		T * newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		int j = 0;
		for(int i=start; i != (rear+1)%capacity; i=(i+1)%capacity) {
			newQueue[i] = queue[i];
			j++;
		} //switch to newQueue
		front = 2 * capacity - 1; //front 위치 조정
		rear = capacity - 2; //rear 위치 조정
		capacity *= 2; //capacity 크기 2배 조정
		delete[] queue;	queue = newQueue;
	}
	rear = (rear+1) % capacity;	queue[rear] = item;
}
template <class T>
void Queue<T>::Pop() { //delete front element fron queue
	front = (front + 1) % capacity;
	queue[front].~T(); //destructor for T
}
template <class T>
void Queue<T>::reSize(int newSize) {
		T* newQueue = new T[newSize];
		int start = (front + 1) % capacity;
		int j = 0;
		for(int i = start; i != (rear+1)%capacity; i = (i+1)%capacity) {
			newQueue[j] =  queue[i];
			j++;
		}
		front = newSize-1;
		rear = size - 1;
		capacity = newSize;
		delete[] queue;
		queue = newQueue;
}
template <class T>
void Queue<T>::Print() {
	cout << "capacity=" << capacity << " " << "front=" << front <<" "<<"rear=" << rear << " " << endl;
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
		Q_queue.Push(490); 
		Q_queue.Print();
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

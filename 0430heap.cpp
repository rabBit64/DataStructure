#include <iostream>
using namespace std;
template <class T>
class MaxHeap{
private:
	T *heap;
	int heapSize;
	int capacity;
public:
	MaxHeap(int theCapacity=7);	~MaxHeap() {};
	bool IsEmpty() const {
		if(heapSize ==0) return true;
		else return false;
	}
	const T& Top() const;
	void Push(const T&);
	void Pop();	void Print();
};
template <class T>
MaxHeap<T>::MaxHeap(int theCapacity): capacity(theCapacity){
	if(theCapacity < 1) cout<<"Capacity must be >=1."<<endl;
	heapSize=0;
	heap = new T[capacity+1];
}
template <class T>
void MaxHeap<T>::Push(const T& e){
	if(heapSize == capacity) {
		capacity *= 2;
		T *newHeap = new T[capacity+1];
		for(int i=1; i<=heapSize; i++)
			newHeap[i] = heap[i];
		delete heap;
		heap = newHeap;
	}
	int currentIndex = ++heapSize;
	//삽입함수
	while(currentIndex!=1 && heap[currentIndex/2] < e){
		heap[currentIndex] = heap[currentIndex/2];
		currentIndex /= 2;
	}
	heap[currentIndex] = e;
}
template <class T>
void MaxHeap<T>::Pop() {
	if(IsEmpty()) cout<<"Heap is empty. Cannot delete"<<endl;
	cout<<"최대히프에서 삭제값:"<<heap[1]<<"입니다"<<endl;
	heap[1].~T();
	//히프의 마지막 원소 제거
	T lastE = heap[heapSize--];
	int currentIndex = 1;
	int child = 2;
	while(child <= heapSize) {
		//child를 currentNode의 큰 자식으로 설정
		if(child < heapSize && heap[child]<heap[child+1]) child++;
		if(lastE >= heap[child]) break;
		heap[currentIndex] = heap[child];
		currentIndex = child;
		child *= 2;
	}
	heap[currentIndex] = lastE;
}
int main() {
	MaxHeap<int> *maxHeap = new MaxHeap<int>(3);
	maxHeap->Push(4);
	maxHeap->Push(55);
	maxHeap->Push(5);
	maxHeap->Push(40);
	maxHeap->Push(10);
	for(int i=1; i<11; i++)
		maxHeap->Push(i);
//	maxHeap->Print();
//	maxHeap->Top();
	
	for(int i=0; i<4; i++)
		maxHeap->Pop();
//	maxHeap->Print();
//	maxHeap->Top();
}

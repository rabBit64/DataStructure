#include<iostream>
#include<string>
using namespace std;
template <class T> 
class Stack  { // A finite ordered list with zero or more elements. 
private:   
	T *stack;    // array for stack elements   
	int top;    // array position of top element   
	int capacity;  // capacity of stack array
public:   
	Stack (int stackCapacity);   // Create an empty stack.
	~Stack();
	bool IsEmpty() const;   // return true else return false.      
	T& Top() const;   // Return top element of stack.      
	void Push (const T& item);  // Insert item into the top of the stack  
	void Pop();   // Delete the top element of the stack. 
	void showStack();
}; 
template <class T>
Stack<T>::Stack (int stackCapacity): capacity(stackCapacity) {
	if(capacity<1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}
template <class T>
Stack<T>::~Stack() {
	delete[] stack;
}
template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }
template <class T>
inline T& Stack<T>::Top() const {
	if(IsEmpty()) throw "Stack is empty";
	return stack[top];
}
template <class T>
void Stack<T>::Push(const T& x){
	if(top==capacity-1){
		//Stack 용량 늘리는 프로그램
		capacity += 4;
		T *start = new T[capacity];
		for(int i=0; i<top+1; i++) 
			*(start+i) = *(stack+i);
		delete[] stack;
		stack = start;
	}
	stack[++top]=x;
}
template <class T>
void Stack<T>::Pop() {
	if(IsEmpty()) throw "Stack is empty. Cannot delete";
	if(top <= capacity/4) {
		capacity /=2;
		T *start = new T[capacity];
		for(int i=0; i<top+1; i++)
			start[i] = stack[i];
		delete[] stack;
		stack = start;
	}
	stack[top--].~T();
}
template <class T> 
void Stack<T>::showStack() {
	cout<<"capacity="<<capacity<<" top="<<top<<" "<<endl;
	for(int i=0; i<top+1; i++) {
		cout<<"Stack["<<i<<"]="<<stack[i]<<" ";
	}
	cout<<endl;
}
int main() {
	try{
		Stack<int> stack1(2);
		Stack<double> stack2(10);
		Stack<string> stack3(2);
		stack1.Push(50); stack1.Push(70);
		stack1.Push(40); stack1.Push(80);
		stack1.showStack();
		stack1.Pop(); stack1.showStack();
		stack2.Push(231.44); stack2.Push(10.22);
		stack2.Pop(); stack2.showStack();
		stack3.Push("good"); stack3.Push("morning");
		stack3.showStack();
	}
	catch (char* str) {
		cout<<str<<endl;
	}
}

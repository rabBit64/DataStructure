/* 임의의 클래스를 만든 후 그 객체를 스택에 입력/삭제하고 출력하는 프로그램*/
#include<iostream>
#include<string>
using namespace std;

class reportCard { //성적표 클래스
private:
	string name;
	int classNumber;
	double percentage;
public:
	reportCard(string name="", int classNumber=0, double percentage=0):name(name), classNumber(classNumber), percentage(percentage) {}
	string getName() { return name; }
	int getClassNumber() { return classNumber; }
	double getPercentage() { return percentage; }
	void setName(string name) { this->name = name; }
	void setClassNumber(int classNumber) { this->classNumber = classNumber; }
	void setPercentage(double percentage) { this->percentage = percentage; }
	void showReportCard(); 
	friend ostream& operator <<(ostream& os, reportCard &rp);
};

ostream& operator<<(ostream& os, reportCard &rp) {
	os<<"이름: "<<rp.name<<" | 과목번호(1:자구 2:프언 3:컴구): "<<rp.classNumber<<" | 백분율: "<<rp.percentage<<"%";
	return os;
}
template <class T>
class Stack  {  
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
		cout<<"Stack["<<i<<"]= "<<stack[i]<<" "<<endl;		
	}
	cout<<endl;
}
int main() {
	reportCard student1("김지현",2, 89.0), student2("김백호", 1, 77.9), student3("이혜정", 3, 55.4);
	try{
		Stack<reportCard> stack1(5);
		stack1.Push(student1); stack1. Push(student2); 
		stack1.Push(student3); 
		stack1.showStack();
		stack1.Pop();
		stack1.showStack();
	}
	catch (char* str) {
		cout<<str<<endl;
	}
}

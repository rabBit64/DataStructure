#include <iostream>
using namespace std;

template <class T> class Chain;

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;
public:
	ChainNode(const T& e, ChainNode<T> *next=NULL) : data(e), link(next) {};
};

template <class T>
class Chain{
private:
	ChainNode<T> *first;	
	ChainNode<T> *last;
public:
	Chain(ChainNode<T> *fst=NULL, ChainNode<T> *lst=NULL):first(fst), last(lst) {};
	void Insert(const T & istData);
	void Delete(T delNum);
	void Print();
	void Concat(Chain<T> *b);
	int Length();
};
template <class T>
void Chain<T>::Insert(const T & istData) {
	ChainNode<T> *insertNode = new ChainNode<T>(istData, 0);
	ChainNode<T> *current = first;
	ChainNode<T> *beforeNode = NULL;
	if(current==NULL || current->data < istData) {
		insertNode->link = first;
		first = insertNode;
		if(current==NULL) last = insertNode;
	}
	else {
		while(current && current->data > istData) {
			beforeNode = current;
			current = current->link;
		}
		insertNode->link = current;
		beforeNode->link = insertNode;
		if(current==NULL) last = insertNode;
	}
}
template <class T>
int Chain<T>::Length() {
	int length=0;
	ChainNode<T> *current = first;
	while(current != NULL) {
		current = current->link;
		length++;
	}
	return length;
}
template <class T>
void Chain<T>::Print() {
	ChainNode<T> *current = first;
	cout<<"=====크기"<<Length()<<"인 chain 객체의 리스트====="<<endl;
	while(current != NULL) {
		cout<<"->"<<current->link;
	}
	cout<<endl<<endl;
}
template <class T>
void Chain<T>::Delete(T delData) {
	ChainNode<T> *current = first;
	ChainNode<T> *beforeNode = NULL;

	if(current==NULL || current->data==delData) {
		if(current==NULL) { cout<<"빈 리스트입니다."<<endl; return; }
		first = current->link;
		delete current; return;
	}
	else {
		beforeNode = current;
		for(current = first->link; current !=NULL; beforeNode = current, current = current->link) {
			if(current->data==delData) {
				if(current->link==NULL) last = beforeNode;
				beforeNode->link = current->link; delete current; return;
			}
		}
		cout<<"찾고자 하는 값이 리스트에 없습니다."<<endl;
	}
}
template <class T>
void Chain<T>::Concat(Chain<T> *b) {
	ChainNode<T> *current = b->first;
	if(first==NULL) {
		if(b->first==NULL) return;
		first = b->first; last = b->last;
	}
	else {
		if(b->first==NULL) return;
		while(current != NULL) {
			T dataItem = current->data;
			Insert(dataItem);
			current = current->link;
		}
	}
	b->first = b->last = NULL;
}
int main() {
	Chain<double> *chainA = new Chain<double>();
	Chain<double> *chain = new Chain<double>();
	double insertData;
	for(int i=0; i<5; i++) {
		insertData = (double)i + 50.5;
		chain->Insert(insertData);
	}
	chain->Print();
	
	double delNum;
	cout<<"삭제하고자 하는 값을 입력하세요.";
	cin>>delNum; cout<<endl;
	chain->Delete(delNum);	chain->Print();
	chainA->Insert(54.3);	chainA->Insert(54.5);	chainA->Insert(53.2);
	chainA->Insert(59.3);	chainA->Print();

	chain->Concat(chainA);	chain->Print();
	return 0;
}

#include <iostream>
using namespace std;

class Chain;
class ChainNode {
	friend class Chain; //Chain - ChainNode에 의한 class 선언(friend 선언)
private:
	double data;
	ChainNode *link;
public:
	ChainNode(double element, ChainNode* next = NULL) :data(element), link(next) {}
};

class Chain {
private:
	ChainNode * first; //chain의 첫번째 노드를 지시하고 있는 접근 포인터 first. Chain의 전용 데이터 멤버
	ChainNode * last;
public:
	Chain(ChainNode* fst = NULL, ChainNode * lst = NULL) :first(fst), last(lst) {};
	void Insert(ChainNode *insertNode);
	void Delete(double deNum);
	void Print();
	int Length();
	void Reverse();
	void Concat(Chain *b);
};

void Chain::Insert(ChainNode *insertNode) {
	if (first == NULL) {
		first = insertNode; //처음으로 넣을때
		last = first;
	}
	else {
		last->link = insertNode; //맨 뒤에 계속 집어넣어줌
		last = last->link;
	}
}
void Chain::Print() {
	ChainNode *current = first; //current 포인터 하나 만들기
	cout << "first";
	while (current != NULL) {
		cout << "->" << current->data;
		current = current->link;//current가 가리키고 있는 link를 다시 current 에 집어넣어줌!!!!!
	}
	cout << endl;
}
int Chain::Length() {
	int length = 0;
	ChainNode *current = first;
	while (current != NULL) {
		current = current->link;
		length++;
	}
	return length;
}
void Chain::Delete(double delData) {
	ChainNode *current = first;
	ChainNode *beforeNode = NULL;
	if (current == NULL || current->data == delData) {
		if (current == NULL) { cout << "빈 리스트입니다." << endl; return; }
		first = current->link;
		delete current; return;
	}
	else {
		beforeNode = current;
		for (current = first->link; current != NULL; beforeNode = current; current = current->link;) {
			if (current->data == delData) {
				if (current->link == NULL) last = beforeNode;
				beforeNode->link = current->link;
				delete current; return;
			}
		}
		cout << "찾고자 하는 값이 리스트에 없습니다." << endl;
	}
}
void Chain::Reverse() {
	ChainNode *current = first;
	ChainNode *prev = NULL;
	ChainNode *rever = NULL;
	while (current) {
		rever = prev;
		prev = current;
		current = current->link;
		prev->link = rever;
	}
	last = first;
	first = prev;
}
void Chain::Concat(Chain *b) {
	ChainNode *current = b->first;
	if (first==NULL) {
		if (b->first==NULL) return;
		first = b->first;
		last = b->last;
	}
	else {
		if(b->first=NULL) return;
		while(current != NULL) {
			double dataItem = current ->data;
			Insert(dataItem);
			current = current->link;
		}
	}
	b->first = b->last = NULL;
}

int main() {
	Chain *chain = new Chain();
	Chain *chainA = new Chain();
	double insertData;
	for(int i=0; i<10; i++){
		insertData = (double)i+50.5;
		chain->Insert(insertData);
	}
	chain->Print();
	cout<<"Node length:"<<chain->Length()<<endl;
	
	double delNum;
	cout<<"삭제하고자 하는 값 입력하세요:";
	cin>>delNum;
	chain->Delete(delNum);
	chain->Print();
	cout<<"Node length:"<<chain->Length()<<endl;
	
	chain->Reverse();
	chain->Print();
	cout<<"Node length:"<<chain->Length()<<endl;
	
	chainA->Insert(54.3); chainA->Insert(54.5); chainA->Insert(53.2);
	chainA->Print();
	cout<<"Node length:"<<chain->Length()<<endl;
	
	chain->Concat(chainA);
	chain->Print();
	cout<<"Node length"<<chain->Length()<<endl;
	return 0;
}
/*
int main() {
	Chain *chain = new Chain();
	int chainLeng;
	double insertData;
	for(int i=0; i<10; i++) {
		insertData = (double)i+50.5;
		chain->Insert(insertData);
	}
	chain->Print();
	chainLeng=chain->Length();
	cout<<"Node의 크기:"<<chainLeng<<endl;
	double delNum;
	cout<<"삭제하고자 하는 값을 입력하세요.";
	cin>>delNum;
	chain->Delete(delNum);
	chain->Print();
	
	chainLeng=chain->Length();
	cout<<"Node의 크기:"<<chainLeng<<endl;
	return 0;
}
*/
/*
int main() {
	Chain *chain = new Chain();
	double insertData;
	for(int i=0; i<10; i++) {
		insertData = (double)i + 50.5;
		ChainNode *inputchain = new ChainNode(insertData);
		chain->Insert(inputchain);
	}
	chain->Print();
	return 0;
}
int main() {
	Chain chain; double insertData;
	insertData = 45.4;
	ChainNode *inputchain = new ChainNode(insertData);
	chain.Insert(inputchain);
}
*/

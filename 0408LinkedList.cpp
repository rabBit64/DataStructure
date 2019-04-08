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
	void Insert(ChainNode *x);
	void Delete(double deNum);
	void Print();
	int Length();
	void Reverse();
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
		for (current = first->link; current != NULL; beforeNode = current, current = current->link) {
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
/*
template <class T>
void Chain<T>::Concat(Chain<T>& b) {
	//chain연결 프로그램 작성
	if (first) {
		if (!= b->first) return;
		last->link = b->first; last = b->last;
	}
	else {
	first = b->first; last = b->last;
	}
	b->first = b->last = 0;
}
*/

int main() {
	Chain *chain = new Chain();
	Chain *chainA = new Chain();
	double insertData;
	for (int i = 0; i < 10; i++) {//data값 집어넣는것
		insertData = (double)i + 50.5;
		ChainNode *inputchain = new ChainNode(insertData);
		chain->Insert(inputchain);//?
	}

	chain->Print();
	cout << "Node의 크기:" << chain->Length() << endl;

	double delNum;
	cout << "삭제하고자 하는 값을 입력하세요";
	cin >> delNum;
	chain->Delete(delNum);
	chain->Print();
	cout << "Node의 크기:" << chain->Length() << endl;
	
	chain->Reverse();
	chain->Print();
	cout << "Node의 크기:" << chain->Length() << endl;
	return 0;
}

/*동적 Chain 객체 생성
int main() {
	Chain *chain = new Chain();
	double insertData;
	insertData = 45.4;
	ChainNode *inputchain = new ChainNode(insertData);
	chain->Insert(inputchain);
}
*/

/*
int main() {
	Chain chain; double insertData;
	insertData = 45.4;
	ChainNode *inputchain = new ChainNode(insertData);
	chain.Insert(inputchain);
}
*/

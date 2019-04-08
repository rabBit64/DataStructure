#include <iostream>
class Chain;
class ChainNode {
	friend class Chain; //Chain - ChainNode에 의한 class 선언(friend 선언)
private:
	double data;
	ChainNode *link;
public:
	ChainNode(double element, ChainNode* next = NULL)
		:data(element), link(next) {}
};
class Chain {
private:
	ChainNode * first; //chain의 첫번째 노드를 지시하고 있는 접근 포인터 first. Chain의 전용 데이터 멤버
	ChainNode * last; 
public:
	Chain(ChainNode* fst = NULL, ChainNode * lst = NULL):first(fst), last(lst) {};
	void Insert(ChainNode *x);
	void Delete(double deNum);
	void Print();
};
void Chain::Insert(ChainNode *insertNode) {
	if(first == NULL) {
		first = insertNode;
		last = first;
	}
	else {
		last->link = insertNode;
		last = last->link;
	}
}
//동적 Chain 객체 생성
int main() {
	Chain *chain = new Chain();
	double insertData;
	insertData = 45.4;
	ChainNode *inputchain = new ChainNode(insertData);
	chain->Insert(inputchain);
}

/*
int main() {
	Chain chain; double insertData;
	insertData = 45.4;
	ChainNode *inputchain = new ChainNode(insertData);
	chain.Insert(inputchain);
}
*/

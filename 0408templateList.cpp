//순서가 있는 템플릿 리스트 클래스
//reverse 대신 concat
#include <iostream>
using namespace std;
template <class T> class Chain;
template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data; ChainNode<T> *link;
public: chainNode(const T&e.ChainNode *next = NULL) :data(e), link(next) {};
};
template <class T>
class Chain {
private:
	ChainNode<T> *first; ChainNode<T> *last;
public:
	Chain(ChainNode<T> *fst = NULL, ChainNode<T> *lst = NULL) : first(fst), last(lst) {};
	void Insert(const T & istData);
	void Delete(T delNum);
	void Print();
	int Length();
	void Concat();
};

int main() {
	Chain<double> *chainA = new Chain<double>();
	Chain<double> *chain = new Chain<double>();

	double insertData;
	for (int i = 0; i < 5; i++) {
		insertData = (double)i + 50.5;
		chain->Insert(insertData);
	}
	chain->Print();

	double delNum;
	cout << "삭제하고자 하는 값을 입력하세요. ";
	cin >> delNum; cout << endl;
	chain->Delete(delNum);
	chain->Print();

	chainA->Insert(54.3);	chainA->Insert(54.5);
	chainA->Insert(53.2);	chainA->Insert(59.4);
	chainA->Print();

	chain->Concat(chainA);
	chain->Print();
	return 0;

}

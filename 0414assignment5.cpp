#include <iostream>
using namespace std;
template <class T> class Polynomial;
template <class T>
class PolyTerm {
	friend class Polynomial<T>;
private:
	int coef;
	int exp;
	PolyTerm<T> *link;
public:
	PolyTerm(int c, int e, PolyTerm<T> *l=NULL):coef(c), exp(e), link(l) {}
};
template <class T>
class Polynomial {
private:
	PolyTerm<T> *first;
	PolyTerm<T> *last;
public:
	Polynomial(PolyTerm<T> *a=NULL, PolyTerm<T> *b=NULL):first(a), last(b) {}
	Polynomial addpoly(const Polynomial &poly1, const Polynomial &poly2, const Polynomial &poly3); //두 방정식 더하는 함수(추가)
	Polynomial operator+(const Polynomial & b) const;
	void DelPolyTerm(int delExp);
	void InsertPolyTerm(int coefValue, int expValue);
	void Print();
	int Length;
};
template <class T>
Polynomial Polynomial<T>::addpoly(const PolyTerm<T> &poly1, const PolyTerm<T> &poly2, const PolyTerm<T> &poly) { 
	while(poly1->next && poly2->next) { 
    	if(poly1->exp > poly2->exp)	{ 
            	poly->exp = poly1->exp; 
            	poly->coef = poly1->coef; 
            	poly1 = poly1->next; 
        	} 
        else if(poly1->exp < poly2->exp) { 
            	poly->exp = poly2->exp; 
            	poly->coef = poly2->coef; 
            	poly2 = poly2->next; 
        	} 
        else { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
	while(poly1->next || poly2->next) { 
    	if(poly1->next) { 
            poly->exp = poly1->exp; 
            poly->coef = poly1->coef; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) { 
            poly->exp = poly2->exp; 
            poly->coef = poly2->coef; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
} 
template <class T> class Chain;
template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;	ChainNode<T> *link;
public:
	ChainNode(const T& e, ChainNode *next=NULL):data(e), link(next) {};
};
template <class T>
class Chain {
private:
	ChainNode<T> *first;	ChainNode<T> *last;
public:
	Chain(ChainNode<T> *fst=NULL, ChainNode<T> *lst=NULL) : first(fst), last(lst) {};
	void Insert(const T & istData);
	void Delete(T delData);
	void Print();
	int Length();
	void Reverse();
};
template <class T>
void Chain<T>::Insert(const T & istData) {
	if(first == NULL) {
		first = istData;
		last = first;
	}
	else {
		last->link=istData;
		last=last->link;
	}
}
template <class T>
void Chain<T>::Delete(T delData) {
	ChainNode<T> *current = first;
	ChainNode<T> *beforeNode = NULL;
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
template <class T>
void Chain<T>::Print() {
	ChainNode<T> *current = first; 
	cout << "first";
	while (current != NULL) {
		cout << "->" << current->data;
		current = current->link;
	}
	cout << endl;
}
template <class T>
int Chain<T>::Length() {
	int length = 0;
	ChainNode<T> *current = first;
	while (current != NULL) {
		current = current->link;
		length++;
	}
	return length;
}
template <class T>
void Chain<T>::Reverse() {
	ChainNode<T> *current = first;
	ChainNode<T> *prev = NULL;
	ChainNode<T> *rever = NULL;
	while (current) {
		rever = prev;
		prev = current;
		current = current->link;
		prev->link = rever;
	}
	last = first;
	first = prev;
}
int main() {
}

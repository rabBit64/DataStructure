#include <iostream>
using namespace std;
template <class T> class Polynomial;
template <class T>
class PolyTerm{ //all member of term are public by default
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
	PolyTerm<T> * first;
	PolyTerm<T> * last;
public:
	Polynomial(PolyTerm<T> *a=NULL, PolyTerm<T> * b=NULL): first(a), last(b) {}
	Polynomial operator+(const Polynomial & b) const;	
	void InsertPolyTerm(int coefValue, int expValue);
	void InsertPolyTerm(int coefValue, int expValue);
	void DelPolyTerm(int delExp);
	void InsertBack(int coefValue, int expValue);
	void Print();
	int Length();
};
template <class T>
Polynomial Polynomial<T>::operator+(const Polynomial& b) const {
//다항식 *this(a)와 b를 더해서 그 합을 반환한다
	Term temp;
	Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
	Polynomial c;
	while(ai && bi) { //현재 노드들은 NULL이 아님
		if(ai->exp == b->exp) {
			int sum = ai->coef+bi->coef;
			if(sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			a++; b++; //다음 항으로 이동
		}
		else if(ai->exp<b->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			b++; //b의 다음 항
		}
		else {
			c.poly.InsertBack(temp.Set(ai->coef, bi->exp));
			a++; //a의 다음 항
		}
	}
	while(ai) { //a의 나머지를 복사
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		a++;
	}	
	while(bi) { //b의 나머지를 복사
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		b++;
	}
}

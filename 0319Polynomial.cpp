#include <iostream>
using namespace std;
class Polynomial;

class Term {
friend class Polynomial;
private:
	float coef; int exp;
public:
	Term(float coef=0, int exp=0): coef(coef), exp(exp) {}
};

class Polynomial {
private:
	Term *termArray;// why array?
	int capacity;
	int terms;
public:
	Polynomial(Term termArray=NULL,int cap=0,int term=0): termArray(NULL), capacity(cap), terms(term) {}
	Polynomial Add(Polynomial poly);
	void NewTerm(const float theCoeff, const int theExp);
	void print();
};

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	if(terms==capacity)
	{
	capacity += 4;
	Term *start = new Term[capacity]; //new array!
	//copy(termArray, termArray+terms. start);
	for(int i=0; i<terms; i++) {
		start[i] = termArray[i];
		delete[] termArray; //dellocate old memory!
		termArray = start;
	}
	termArray[terms].coef=theCoeff;
	termArray[terms++].exp=theExp; //why?
	}
}

Polynomial Polynomial::Add(Polynomial b) {
	Polynomial c;
	int aPos=0, bPos=0; //aPos, bPos?
	while((aPos<terms)&&(bPos<b.terms))
		if((termArray[aPos].exp = b.termArray[bPos].exp)) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			aPos++; bPos++;
		}
		else if((termArray[aPos].exp < b.termArray[bPos].exp)) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	for(int aPos=0; aPos<terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for(int bPos=0; bPos<b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return c;
}

void Polynomial::print() {
	for(int i=0; i<terms; i++) {
		if(termArray[i].coef==0) continue;
		if(termArray[i].exp==0) cout<<termArray[i].coef;
		else if(i==terms-1) cout<<termArray[i].coef<<"x^"<<termArray[i].exp;
		else cout<<termArray[i].coef<<"x^"<<termArray[i].exp<<"+";
	}
	cout<<endl;
}
int main() {
	Polynomial a, b, c;
	a.NewTerm(5,5);
	a.NewTerm(4,4);
	a.print();

	b.NewTerm(3,3);
	b.NewTerm(2,2);
	b.NewTerm(1,1);
	b.print();

	c=a.Add(b);
	c.print();
}

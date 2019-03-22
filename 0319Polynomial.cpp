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
	Polynomial(termArray=NULL, capacity=0, term=0): termArray(NULL), capacity(cap), terms(term) {}
	Polynomial Add(Polynomial poly);
	void NewTerm(const float theCoeff, const int theExp);
	void print()
};

Polynmial Polynomial::Add(Polynomial b) {
	Polynomial c;
	

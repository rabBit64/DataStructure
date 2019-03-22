/* solution for quadratic equation: using two classes */
#include <iostream>
#include <math.h>
#include <ostream>
using namespace std;
class Complex {
	double real, image;
public:
	Complex(double real=0, double image=0): real(real), image(image) {} //Comstructor
	double getReal() { return real; } 
	double getImage() { return image; } 
	void setReal(double real) { this->real = real; }
	void setImage(double image) { this->image = image; }
	friend ostream& operator<<(ostream& os, Complex &cp);
};
ostream& operator<<(ostream& os, Complex &cp) {
	os<<"("<<cp.real<<" + "<<cp.image<<"i"<<")";
	return os;
}
class Polynomial {
	double a, b, c;
public:
	Polynomial(int c0=0, int c1=0, int c2=0): a(c0), b(c1), c(c2) {}
	Polynomial operator+(const Polynomial& s);
	double eval(double x) { return a*x*x + b*x + c; }
	void roots();
	friend ostream& operator<<(ostream& os, Polynomial& p);	
	friend istream& operator>>(istream& is, Polynomial& p);
};
Polynomial Polynomial::operator+(const Polynomial& s) {
	Polynomial sum;
	sum.a += s.a;
	sum.b += s.b;
	sum.c += s.c;
	return sum;
}
void Polynomial::roots() {
	double d = b*b - 4.0*a*c;
	if(d>=0) {
		double root1 = (-b+sqrt(d))/(2.0*a);
		double root2 = (-b-sqrt(d))/(2.0*a);
		cout<<"Roots are "<<root1<<" and "<<root2<<endl;
	}
	else {
		Complex c1((-b)/(2.0*a), sqrt(abs(d))/(2.0*a));
		Complex c2((-b)/(2.0*a), -sqrt(abs(d))/(2.0*a));
		cout<<"Roots are "<<c1<<" and "<<c2<<endl;
	}
} 
ostream& operator<<(ostream& os, Polynomial& p){
	os<<"Polynomial is: "<<p.a<<"x^2 +"<<p.b<<"x +"<<p.c<<endl;
	return os;
}
istream& operator>>(istream& is, Polynomial& p){
	cout<<"Enter coefficients of polynomial (a, b, c in that order)";
	is>>p.a>>p.b>>p.c;
	return is;
} 
	
int main() {
	Polynomial a(2,1,2), b;
	cin>>b;
	cout<<a;
	cout<<b;
	a.roots();
	b.roots();
}
	

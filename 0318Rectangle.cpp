/* when implementing class
-> 1. member variables (private preferred)
   2. member functions (public)
*/
#include <iostream>
using namespace std;

class Rectangle {
	int xLow, yLow, height, width;
public:
	Rectangle(int x=0, int y=0, int h=0, int w=0): xLow(x), yLow(y), height(h), width(w){}
	int GetHeight(){ return height; } //inline
	int GetWidth(){ return width; }
	friend ostream& operator<<(ostream &os, Rectangle &r);
	friend bool operator==(const Rectangle &s, const Rectangle &p);

};

ostream& operator<<(ostream &os, Rectangle &r) {
	os<<"Position is: "<<r.xLow<<","<<r.yLow<<endl;
	os<<"Width is: "<<r.width<<endl;
	os<<"Height is: "<<r.height<<endl;
	return os; //return reference!!
}
bool operator==(const Rectangle &s, const Rectangle &p){
	if(&p==&s) return true; //same pointer value?
	if((s.xLow==p.xLow)&&(s.yLow==p.yLow)&&(s.height==p.height)&&(s.width==p.width)) return true; //same member variables?
	else return false;
}

int main() {
	Rectangle r(5,5,6,7), s(5,5,6,7);
	Rectangle *p = &s;
	if(r==s)
		cout<<"같음"<<endl;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Circle{
  string name;
  int radius;
public:
  Circle(int radius=0, string name=""): radius(radius), name(name){}
  double getArea() {return 3.14*radius*radius;}
  string getName() {return name;}
  bool operator <(const Circle &b) const;
  friend ostream& operator<<(ostream &os, vector <Circle> &b);
};

ostream& operator<<(ostream &os, vector<Circle> &b){
  os<<"모든원소를 출력한다.>>";
  for(auto it=0; it<b.size(); it++)
    os<<b[it].getName()<<" ";
  os<<endl;
  return os;
}
bool Circle::operator<(const Circle &b) const{
  return this->radius < b.radius;
}
void printVector(vector<Circle> &b){
  cout<<"모든원소를 출력한다.>>";
  for(auto it=b.begin(); it!=b.end(); it++)
    cout<<it->getName()<<" ";
  cout<<endl;
}

int main() {
  vector<Circle> v;
  v.push_back(Circle(2, "waffle"));
  v.push_back(Circle(3, "pizza"));
  v.push_back(Circle(1, "donut"));
  v.push_back(Circle(5, "pizzaLarge"));
  printVector(v);
  int it = v.size()-1;
  sort(&v[0], &v[it]);
  printVector(v);
  cout<<endl<<"프렌드함수 operator<<로 출력하는 경우 "<<endl;
  cout<<v<<endl;
}

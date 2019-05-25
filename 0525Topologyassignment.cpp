#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


class Toplogy {
private:
    unsigned vtx;
    vector<int> *inDegree ; //차수
    vector<int> *result ;
    vector <int> *Edges = new vector<int>[vtx];
public:
    Toplogy(unsigned vtx = 0) : vtx(vtx) {
        inDegree = new vector<int>(vtx, 0);
        result = new vector<int>();
    }
    void inputEdge(int startV, int endV);
    void printResult();
    void topologySorting();
};
void Toplogy::printResult(){
    vector<int>::iterator it;
    for(it=result->begin(); it!=result->end(); it++){
        cout<<*it<<' ';
    }
}
void Toplogy::inputEdge(int StartV, int EndV){
    Edges[StartV].push_back(EndV);
    inDegree->at(EndV)++;
}
void Toplogy::topologySorting(){
    queue<int> q;
    int i=0;
    vector<int>::iterator it;
    for(it = inDegree->begin(); it != inDegree->end(); it++){
        if(*it ==0)
            q.push(i);
        i++;
    }
    for(unsigned i=0; i<vtx; i++) {
        if(q.empty()){
            cout<<"cycle occured!";
            return;
        }
        int cur = q.front(); q.pop();
        result->push_back(cur);
        for(it = Edges[cur].begin(); it != Edges[cur].end(); it++){
            int next = *it;
            inDegree->at(next)--;
            if(inDegree->at(next)==0)
                q.push(next);
        }
    }
}
int main() {
    Toplogy tpl(9);
    tpl.inputEdge(2, 1);    tpl.inputEdge(2, 0);
    tpl.inputEdge(0, 1);    tpl.inputEdge(1, 3);
    tpl.inputEdge(1, 4);    tpl.inputEdge(4, 5);
    tpl.inputEdge(5, 3);    tpl.inputEdge(5, 7);
    tpl.inputEdge(3, 6);    tpl.inputEdge(6, 7);
    tpl.inputEdge(7, 8);
    tpl.topologySorting();
    tpl.printResult();
}


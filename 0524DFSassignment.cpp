
/*순환적 DFS-> 비순환적 DFS(스택과 for문)*/
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
class D_BFS {
private:
    int n;
    set<int> *list;
    bool *visited;
public:
    D_BFS(int n) {
        this->n = n;
        list = new set<int>[n];
        visited = new bool[n];
        fill(visited, visited+n, false);
    }
    void StartDFS(int v);
    void DFS(const int v);
    void addEdge(int src, int dest);
    void printGraph();
};
void D_BFS::StartDFS(int v){
    cout << "\n ==== DFS list ==== " << "\n";
    DFS(v);
    cout << endl<<endl;
    //delete[] visited;
}
/*void D_BFS::DFS(const int v) // Workhorse
{// Visit all previously unvisited vertices that are reachable from vertex v.
    if (visited[v]) return;
    visited[v] = true;
    cout << v << " ";
    set<int>::iterator ite;
    for (ite = list[v].begin(); ite != list[v].end(); ++ite) {
        int w = *ite;
        DFS(w);
    }
}*/
void D_BFS::DFS(const int v) {
    stack<int> st;
    st.push(v);
    set<int>::iterator it;
    
    while(!st.empty()){
        int cur = st.top();
        if(visited[cur] == false){
            cout<<cur<<' ';
            visited[cur]=true;
        }
        else
            st.pop();
        
        for(it = list[cur].begin(); it!=list[cur].end();it++){
            if(!visited[*it]){
                st.push(*it);
                break;
            }
        }
    }
}
void D_BFS::addEdge(int src, int dest){
    list[src].insert(dest);
    list[dest].insert(src);
}
void D_BFS::printGraph(){
    for(int i=0; i<n; ++i){
        set<int>::iterator ite;
        cout<<"\n Adjacency list of vertex"<<i<<"\n head";
        for(ite = list[i].begin(); ite!= list[i].end(); ++ite){
            cout<<"->"<<*ite;
        }
        cout<<endl;
        }
}

int main() {
    D_BFS gh(8);
    gh.addEdge(0,1); gh.addEdge(0,2);
    gh.addEdge(1,3); gh.addEdge(1,4);
    gh.addEdge(2,5); gh.addEdge(2,6);
    gh.addEdge(3,7); gh.addEdge(4,7);
    gh.addEdge(5,7); gh.addEdge(6,7);
    gh.printGraph();
    gh.StartDFS(0);
}


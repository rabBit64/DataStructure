/*prim 알고리즘*/
#include <iostream>
#include <queue>
#include <list>
#include <functional>
using namespace std;
class PrimMST {
    const int INF = 0x3f3f3f3f; //가중치 무한대
    int V; //정점 개수
    list< pair<int,int> > *graph;
    vector<int> minVertex; //최소가중치를 저장하는 vector
    vector<int> parent;
public:
    PrimMST(int V=0): V(V){ //생성자
        graph = new list<pair<int,int>>[V]; //각 정점에서 인접정점과 가중치
        minVertex = vector<int>(V,INF);
        parent = vector<int>(V,-1);
    }
    void addEdge(int u, int v, int w);
    void minMST();
    void printMST();
};
void PrimMST::addEdge(int u, int v, int w){
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}
//visited, priority_queue, minVertex, parent
void PrimMST::minMST(){
    priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;
    int src = 0; //신장트리 시작점
    vector<bool> visited(V, false);
    pq.push(make_pair(0, src));
    minVertex[src] = 0; parent[src] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;    pq.pop();
        visited[u]=true;
        list< pair<int,int> >::iterator it;
        for(it = graph[u].begin(); it!=graph[u].end(); ++it){
            int v = (*it).first;    int weight = (*it).second;
            if(visited[v] == false && minVertex[v] > weight) {
                minVertex[v] = weight;
                pq.push(make_pair(minVertex[v], v));
                parent[v] = u;
            }
        }
    }
}
void PrimMST::printMST(){
    int weightTotal = 0;
    for(int i=1; i<V; ++i) cout<<parent[i]<<'-'<<i<<endl;
    for(unsigned i=1; i<minVertex.size(); ++i) weightTotal += minVertex[i];
    cout<<"최소 신장트리 간선 가중치 = "<<weightTotal << endl;
}
int main() {
    int V = 7;
    PrimMST g(V);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 6, 3);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 7);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 6, 8);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 6);
    g.minMST();
    g.printMST();
    return 0;
}

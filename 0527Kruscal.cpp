/* Kruscal 알고리즘은 간선중심*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge {
public:
	int node[2], distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a; this->node[1] = b; this->distance = distance;
	}
	bool operator<(Edge &edges)
	{
		return this->distance < edges.distance;
	}
};
class Graph {
private:
	int V, E;
	vector<Edge> edges;
	vector<Edge> MST;
public:
	Graph(int V = 0, int E = 0) :V(V), E(E) {}
	void addEdge(Edge e) { edges.push_back(e); }
	vector<Edge>& getVectorEdges() { return edges; }
	vector<Edge>& getVectorMST() { return MST;  }
	int kruscalMST();
	void printEdgesAll(vector <Edge> e);
};

void Graph::printEdgesAll(vector<Edge> e) {
	cout << "number of vertex: " << V << " number of Edges:" << e.size() << endl;
	for (auto it = e.begin(); it != e.end(); it++) {
		cout << it->node[0] << " " << it->node[1] << " " << it->distance << endl;
	}
	cout << endl;
}

class DisjointSet {
	int n; int *parent;
public:
	DisjointSet(int n) {
		this->n = n; parent = new int[n];
		for (int i = 0; i < n; i++) { parent[i] = i; }
	}
	int getParent(int x); void unionParent(int a, int b);
	int findParent(int a, int b);
};
int DisjointSet::getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}
void DisjointSet::unionParent(int a, int b) {
	a = getParent(a); b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int DisjointSet::findParent(int a, int b) {
	a = getParent(a); b = getParent(b);
	if (a == b) return 1;
	else return 0;
}
int Graph::kruscalMST() {
	//간선의 비용을 기준으로 오름차순으로 정렬
	int weightMST = 0;	DisjointSet ds(V);
	sort(edges.begin(), edges.end());
	//사이클이 발생하지 않는 경우 그래프 포함
	for (auto it = edges.begin(); it != edges.end(); it++) {
		int edgeFirst = it->node[0]; int edgeSecond = it->node[1];
		if (!ds.findParent(edgeFirst, edgeSecond)) {
		//(중요)사이클이 없으면 MST에 삽입, 그래프에 join, 최소비용을 구한다.
			weightMST += it->distance;	MST.push_back(*it);
			ds.unionParent(edgeFirst, edgeSecond);
		}
	}
	return weightMST;
}
int main() {
	int vtx = 7; int edg = 12;
	Graph g(vtx, edg);
	g.addEdge(Edge(0, 1, 9)); g.addEdge(Edge(0, 2, 10));
	g.addEdge(Edge(1, 3, 10)); g.addEdge(Edge(1, 4, 5));
	g.addEdge(Edge(1, 6, 3)); g.addEdge(Edge(2, 3, 9));
	g.addEdge(Edge(2, 4, 7)); g.addEdge(Edge(2, 5, 2));
	g.addEdge(Edge(3, 5, 4)); g.addEdge(Edge(3, 6, 8));
	g.addEdge(Edge(4, 6, 1)); g.addEdge(Edge(5, 6, 6));
	int weight = g.kruscalMST();
	g.printEdgesAll(g.getVectorEdges());
	g.printEdgesAll(g.getVectorMST());
	cout << "Weight of MST is: " << weight << endl;
	return 0;
}

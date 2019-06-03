#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
class Dijksta {
	int startnode;
	int V;
	vector<pair<int, int>> costTrace;
	vector<pair<int, int>> *graph;
public:
	Dijksta(int v = 9, int snode = 0) : V(v), startnode(snode) {
		graph = new vector<pair<int, int>>[v];
		for (int i = 0; i < v; i++) {
			costTrace.push_back(make_pair(numeric_limits<int>::max(), -1));
		}
		costTrace[0].first = 0; costTrace[0].second = startnode;

	}
	void addEdge(int u, int v, int w);
	void shortTestPath();
	void print();
};
void Dijksta::addEdge(int fromnode, int tonode, int cost) {
	graph[fromnode].push_back(make_pair(cost, tonode));
	graph[tonode].push_back(make_pair(cost, fromnode));
}
void Dijksta::print() {
	cout << "정점" << startnode << "으로부터 최단거리" << endl;
	for (int i = 0; i < V; i++) {
		cout << "[" << startnode << "," << i << "]" << "=" << costTrace[i].first << endl;
	}
	cout << endl;
	cout << "각 정점에서부터" << startnode << "까지 최단경로" << endl;
	for (int i = 0; i < V; i++) {
		int back = i;
		if (back != 0) cout << "" << back;
		for (; back != 0; back = costTrace[back].second) {
			cout << "->" << costTrace[back].second;
		}
		cout << endl;
	}
}
void Dijksta::shortTestPath() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> pq;
	//startndoe로 가는 cost와 startnode 번호를 priority queue에 넣어줌
	pq.push(make_pair(costTrace[0].first, costTrace[0].second));
	while (!pq.empty()) {
		int n_cost = pq.top().first; //가장 작은 cost를 가진 top을 꺼내옴
		int n_node = pq.top().second; //가장 작은 cost를 가진 노드의 번호를 꺼내옴
		pq.pop();//queue에서 제거
		if (n_cost > costTrace[n_node].first) continue; //새로 꺼내온 것보다 기존 것이 더작을 경우 넘어감(없어도됨)
		for (unsigned j = 0; j < graph[n_node].size(); j++) { //꺼내온 노드에서 갈 수 있는 모든 node를 탐색
			int edgeCost = graph[n_node][j].first;
			int visitvertex = graph[n_node][j].second;
			//startnode ~ 현재 node의 거리 + 현재 node와 다른 node로 가는 cost를 비교 기록도니 최소 비용보다 작을 경우
			if (n_cost + edgeCost < costTrace[visitvertex].first) { //costTrace 2개 값 고쳐주고, primary queue 고쳐줌
				/*이부분 시험에 나올듯*/
				costTrace[visitvertex].first = n_cost + edgeCost;
				costTrace[visitvertex].second = n_node;
				pq.push(make_pair(n_cost + edgeCost, visitvertex));
			}
		}
	}
}
int main() {
	int vertex = 8;
	int startvertex = 0;
	Dijksta g(vertex, startvertex);
	g.addEdge(0, 1, 1);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 3, 3);
	g.addEdge(1, 4, 1);
	g.addEdge(1, 2, 4);
	g.addEdge(1, 5, 6);
	g.addEdge(3, 4, 5);
	g.addEdge(4, 6, 2);
	g.addEdge(2, 5, 1);
	g.addEdge(2, 7, 2);
	g.addEdge(2, 6, 1);
	g.addEdge(5, 7, 9);
	g.addEdge(6, 7, 1);
	g.shortTestPath();
	g.print();
	return 0;
}

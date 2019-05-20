/* depth first 와 bread first방법으로 신장트리 그릴 수 있다 */
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
class D_BFS {
private:
	int n;
	set<int> *list;
	bool *visited;
public:
	D_BFS(int n) {
		this->n = n; list = new set<int>[n];
		visited = new bool[n];
		fill(visited, visited + n, false);
	}
	void StartDFS(int v); void BFS(int v); void DFS(int v);
	void addEdge(int src, int dest);
	void printGraph();
};
void D_BFS::addEdge(int src, int dest) {
	list[src].insert(dest);
	list[dest].insert(src);
}
void D_BFS::printGraph() {
	for (int i = 0; i < n; ++i) {
		set<int>::iterator ite;
		cout << "\n Adjacency list of vertex" << i << "\n head";
		for (ite = list[i].begin(); ite != list[i].end(); ++ite) {
			cout << "->" << *ite;
		}
		cout << endl;
	}
}
void D_BFS::StartDFS(int v) {
	cout << "\n====DFS list====" << "\n";
	DFS(v);
	cout << endl << endl;
}
void D_BFS::DFS(const int v) {
	if (visited[v]) return;
	visited[v] = true;
	cout << v << " ";
	set<int>::iterator ite;
	for(ite = list[v].begin(); ite != list[v].end(); ++ite) {
		int w = *ite;
		DFS(w);
	}
}
void D_BFS::BFS(int v) {
	bool *visited = new bool[n];
	fill(visited, visited + n, false);
	visited[v] = true; queue<int> q; q.push(v);
	cout << "\n===BFS list====" << "\n";
	while (!q.empty()) {
		v = q.front(); q.pop();
		cout << v << " ";
		set<int>::iterator ite;
		for (ite = list[v].begin(); ite != list[v].end(); ++ite) {
			int w = *ite;
			if (!visited[v]) {
				q.push(w); visited[w] = true;
			}
		}
	}
	cout << endl; delete[] visited;
}
int main() {
	D_BFS gh(8);
	gh.addEdge(0, 1); gh.addEdge(0, 2); gh.addEdge(1, 3); gh.addEdge(1, 4);
	gh.addEdge(2, 5); gh.addEdge(2, 6); gh.addEdge(3, 7); gh.addEdge(4, 7);
	gh.addEdge(5, 7); gh.addEdge(6, 7);

	gh.printGraph();
	//gh.BFS(0);
	gh.StartDFS(0);
	return 0;
}

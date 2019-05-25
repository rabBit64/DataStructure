/* depth first 와 breadth first spanning방법으로 신장트리 그릴 수 있다 */
#include <iostream>
#include <set> //chain 저장
#include <queue> //queue의 insert()
#include <algorithm> //fill()
using namespace std;
//stl이용 자료구조 정의
class D_BFS {
private:
	int n;
	set<int> *list; //키값으로 구성되며 오름차순으로 정렬됨
	bool *visited;
public:
	D_BFS(int n) {
		this->n = n; list = new set<int>[n];
		visited = new bool[n]; //멤버변수로 사용함
		fill(visited, visited + n, false); //멤버변수로 DFS에서 사용함
	}
	void StartDFS(int v); void BFS(int v); void DFS(int v);
	void addEdge(int src, int dest); //adding edge to graph
	void printGraph();
};
void D_BFS::addEdge(int src, int dest) { //adding edge to graph
	list[src].insert(dest);
	list[dest].insert(src);
}
void D_BFS::printGraph() { //print the graph
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

/*과제: 순환적 DFS를 스택과 for문을 사용하여 비순환적 DFS로 재작성*/
void D_BFS::DFS(const int v) { 
	//visit all previously unvisited vertices that are reachable from vertex v
	if (visited[v]) return;
	visited[v] = true;
	cout << v << " ";
	set<int>::iterator ite;
	for(ite = list[v].begin(); ite != list[v].end(); ++ite) {
		int w = *ite;
		DFS(w);
	}
}
/*BFS; Breadth-First Search (너비 우선 탐색)
-시작정점 v를 방문
-v에 인접한 모든 정점들을 방문
-새롭게 방문한 정점들에 인접하며서 아직 방문하지 못한 정점들을 방문
*/
void D_BFS::BFS(int v) {
	bool *visited = new bool[n]; //지역변수로 사용
	fill(visited, visited + n, false); //지역변수로 사용
	visited[v] = true; queue<int> q; q.push(v);
	cout << "\n===BFS list====" << "\n";
	while (!q.empty()) {
		v = q.front(); q.pop();
		cout << v << " ";
		set<int>::iterator ite;
		//다음 정점을 찾고 스택에 큐에 
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
	//print the adjacency list representation of the above graph
	gh.printGraph();
	//gh.BFS(0);
	gh.StartDFS(0);
	return 0;
}

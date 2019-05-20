#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Topology {
private:
	unsigned vtx; int *inDegree = new int[vtx];
	int *result = new int[vtx];
	vector<int> *Edges = new vector<int>[vtx];
public:
	Topology(unsigned vtx = 0) : vtx(vtx) {
		fill(inDegree, inDegree + this->vtx, 0);
		fill(result, result + this->vtx, 0);
	}
	void inputEdge(int startV, int endV);
	void printResult(); void topologySorting();
};
//방향성이 있기 때문에 하나만 집어넣음
void Topology::inputEdge(int startV, int endV) {
	Edges[startV].push_back(endV);
	inDegree[endV]++;
}
void Topology::printResult() {
	for (unsigned i = 0; i < vtx; i++) cout << result[i] << " ";
	cout << endl;
}
void Topology::topologySorting() {
	queue<int> q;
	for (unsigned i = 0; i < vtx; i++) {
		//진입차수가 0인 노드를 큐에 삽입
		if (inDegree[i] == 0) q.push(i);
	}
	//위상정렬이 완전히 수행하려면 정확하게 N개의 정점을 방문한다.
	for (unsigned i = 0; i < vtx; i++) {
		if (q.empty()) {
			cout << "사이클이 발생하였습니다."; return;
		}
		int x = q.front(); q.pop();
		result[i] = x;
		for (unsigned i = 0; i < Edges[x].size(); i++) {
			int y = Edges[x][i];
			if (--inDegree[y] == 0) q.push(y);
		}
	}
}

int main() {
	Topology tpl(9);
	tpl.inputEdge(2, 1); tpl.inputEdge(2, 0);
	tpl.inputEdge(0, 1); tpl.inputEdge(1, 3);
	tpl.inputEdge(1, 4); tpl.inputEdge(4, 5);
	tpl.inputEdge(5, 3); tpl.inputEdge(5, 7);
	tpl.inputEdge(3, 6); tpl.inputEdge(6, 7);
	tpl.topologySorting();
	tpl.printResult();
}

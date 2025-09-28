#include<iostream>
#include <vector>

using namespace std;

// 배열의 크기를 정하기 위해서 상수로 정의
#define V_MAX 6 // 최대 노드
#define E_MAX 10 // 최대 간선 수

int parent[V_MAX + 1]; // Union-Find를 위한 부모 배열

struct Edge { // 간선의 정보를 묶는 구조체
	int u, v, weight;
};

struct WeightedGraph {
	int n; // 정점 개수
	vector<vector<pair<int, int>>> adj; // 인접 리스트

	// 생성자: 정점 n개짜리 그래프 초기화
	explicit WeightedGraph(int n) : n(n), adj(n) {}

	// 간선 추가 함수
	void addEdge(int u, int v, int w, bool undirected = true) {
		adj[u].push_back({ v, w }); // u -> v (가중치 w)
		if (undirected) {
			adj[v].push_back({ u, w }); // v-> u (가중치 w), 무방향일 때만
		}
	}

	//그래프 출력
	void print() const {
		for (int u = 0; u < n; ++u) {
			cout << u << " : ";
			for (const auto& p : adj[u]) {
				cout << "(" << p.first << "," << p.second << ") ";
			}
			cout << "\n";
		}
	}
};

int getParent(int parent[], int x) // 노드 x가 속한 집합의 대표 루트를 찾는 함수
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) // 노드 a와 b가 속한 두 집합을 하나로 합치는 함수
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) // 두 노드의 루트가 같은지 확인하여 사이클 여부를 판단하는 함수
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

void bubble_sort(Edge edges[], int num_edges) // bubble_sort로 간선 배열을 오름차순으로 정렬하는 함수
{
	for (int i = 0; i < num_edges - 1; ++i) {
		for (int j = 0; j < num_edges - 1 - i; ++j)
		{
			if (edges[j].weight > edges[j + 1].weight)
			{
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
}

void kruskal_mst_list(const WeightedGraph& g) {
	int V = g.n;
	Edge edges[E_MAX];
	int num_edges = 0;

	for (int u = 0; u < V; ++u) { // WeightedGrapht의 인접 리스트를 순회 
		for (const auto& edge_pair : g.adj[u]) {
			int v = edge_pair.first;
			int weight = edge_pair.second;

			if (u < v) { // u가 v 보다 작을 때 간선을 저장
				edges[num_edges] = { u, v, weight };
				num_edges++;
			}
		}
	}

	bubble_sort(edges, num_edges); // 간선들을 정렬

	for (int i = 0; i < V; ++i) { // 모든 노드의 부모를 자기 자신으로 설정
		parent[i] = i;
	}

	int mst_weight = 0;
	int edges_count = 0;

	cout << "\n--- 최소 신장 트리 구성 ---" << endl;
	cout << "선택된 간선 (노드 0~4):" << endl;

	for (int k = 0; k < num_edges; ++k) { // 정렬된 간선의 순서 확인
		int u = edges[k].u;
		int v = edges[k].v;
		int weight = edges[k].weight;

		if (findParent(parent, u, v) == 0) { // 사이클 검사

			unionParent(parent, u, v); // 두 노드의 집합을 합침
			mst_weight += weight;
			edges_count++;

			cout << "(" << u << ", " << v << ", 가중치: " << weight << ")" << endl;

			if (edges_count == V - 1) { // 선택된 간선이 V-1개가 되면 루프 종료
				break;
			}
		}
	}

	cout << "-------------------------------" << endl;
	cout << "최소 신장 트리의 총 가중치: " << mst_weight << endl;
}

int main() {
	WeightedGraph g(5); // 정점 5개 (0~4)

	// 간선 추가 (u, v, weight)
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 5);
	g.addEdge(1, 3, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, 1);

	cout << "--- 입력 그래프 (인접 리스트) ---" << endl;
	g.print();

	kruskal_mst_list(g);

	return 0;
}
#include<iostream>
#include <vector>

using namespace std;

// �迭�� ũ�⸦ ���ϱ� ���ؼ� ����� ����
#define V_MAX 6 // �ִ� ���
#define E_MAX 10 // �ִ� ���� ��

int parent[V_MAX + 1]; // Union-Find�� ���� �θ� �迭

struct Edge { // ������ ������ ���� ����ü
	int u, v, weight;
};

struct WeightedGraph {
	int n; // ���� ����
	vector<vector<pair<int, int>>> adj; // ���� ����Ʈ

	// ������: ���� n��¥�� �׷��� �ʱ�ȭ
	explicit WeightedGraph(int n) : n(n), adj(n) {}

	// ���� �߰� �Լ�
	void addEdge(int u, int v, int w, bool undirected = true) {
		adj[u].push_back({ v, w }); // u -> v (����ġ w)
		if (undirected) {
			adj[v].push_back({ u, w }); // v-> u (����ġ w), �������� ����
		}
	}

	//�׷��� ���
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

int getParent(int parent[], int x) // ��� x�� ���� ������ ��ǥ ��Ʈ�� ã�� �Լ�
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) // ��� a�� b�� ���� �� ������ �ϳ��� ��ġ�� �Լ�
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) // �� ����� ��Ʈ�� ������ Ȯ���Ͽ� ����Ŭ ���θ� �Ǵ��ϴ� �Լ�
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

void bubble_sort(Edge edges[], int num_edges) // bubble_sort�� ���� �迭�� ������������ �����ϴ� �Լ�
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

	for (int u = 0; u < V; ++u) { // WeightedGrapht�� ���� ����Ʈ�� ��ȸ 
		for (const auto& edge_pair : g.adj[u]) {
			int v = edge_pair.first;
			int weight = edge_pair.second;

			if (u < v) { // u�� v ���� ���� �� ������ ����
				edges[num_edges] = { u, v, weight };
				num_edges++;
			}
		}
	}

	bubble_sort(edges, num_edges); // �������� ����

	for (int i = 0; i < V; ++i) { // ��� ����� �θ� �ڱ� �ڽ����� ����
		parent[i] = i;
	}

	int mst_weight = 0;
	int edges_count = 0;

	cout << "\n--- �ּ� ���� Ʈ�� ���� ---" << endl;
	cout << "���õ� ���� (��� 0~4):" << endl;

	for (int k = 0; k < num_edges; ++k) { // ���ĵ� ������ ���� Ȯ��
		int u = edges[k].u;
		int v = edges[k].v;
		int weight = edges[k].weight;

		if (findParent(parent, u, v) == 0) { // ����Ŭ �˻�

			unionParent(parent, u, v); // �� ����� ������ ��ħ
			mst_weight += weight;
			edges_count++;

			cout << "(" << u << ", " << v << ", ����ġ: " << weight << ")" << endl;

			if (edges_count == V - 1) { // ���õ� ������ V-1���� �Ǹ� ���� ����
				break;
			}
		}
	}

	cout << "-------------------------------" << endl;
	cout << "�ּ� ���� Ʈ���� �� ����ġ: " << mst_weight << endl;
}

int main() {
	WeightedGraph g(5); // ���� 5�� (0~4)

	// ���� �߰� (u, v, weight)
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 5);
	g.addEdge(1, 3, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, 1);

	cout << "--- �Է� �׷��� (���� ����Ʈ) ---" << endl;
	g.print();

	kruskal_mst_list(g);

	return 0;
}
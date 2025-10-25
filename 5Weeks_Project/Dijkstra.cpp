#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

const int INF = 1000000000;

struct WeightedGraph {
    int n;

    vector<vector<pair<int, int>>> adj;

    explicit WeightedGraph(int n) : n(n), adj(n) {}

    void addEdge(int u, int v, int w, bool undirected = true) {
        adj[u].push_back({ v, w });
        if (undirected) {
            adj[v].push_back({ u, w });
        }
    }
};


vector<int> dijkstra_noSTL(const WeightedGraph& graph, int startNode) {
    int N = graph.n;

    vector<int> dist(N, INF);       
    vector<bool> visited(N, false); 
    dist[startNode] = 0;

    for (int count = 0; count < N; ++count) {
        int min_dist = INF;
        int u = -1;

        for (int v = 0; v < N; ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;

        for (const auto& edge : graph.adj[u]) {
            int v = edge.first;   
            int weight = edge.second;

            if (!visited[v] && dist[u] != INF && (long long)dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

int main() {
    WeightedGraph g(5);

    // ���� �߰� (u, v, weight)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 1);

    cout << "--- ���ͽ�Ʈ�� �˰��� (���� ����Ʈ + �迭 ����) ---" << endl;
    cout << "�׷���: (0-1:10), (0-2:5), (1-3:2), (2-3:7), (3-4:1)" << endl;

    int startNode = 0;

    vector<int> shortestDistances = dijkstra_noSTL(g, startNode);

    cout << "\n���� ��� (" << startNode << ")�κ����� �ִ� �Ÿ�:" << endl;
    for (int i = 0; i < g.n; ++i) {
        cout << "��� " << i << ": ";
        if (shortestDistances[i] == INF) {
            cout << "���� �Ұ��� (INF)" << endl;
        }
        else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}
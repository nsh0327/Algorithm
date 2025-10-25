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



int primMST_noSTL(const WeightedGraph& graph, int startNode = 0) {
    int N = graph.n;


    vector<int> inMST(N, 0); 
    vector<int> key(N, INF); 

    key[startNode] = 0;

    int mstWeight = 0;


    for (int count = 0; count < N; ++count) {
        int minKey = INF;
        int u = -1;

        for (int v = 0; v < N; ++v) {
            if (inMST[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }

        inMST[u] = 1;
        mstWeight += key[u];

        for (const auto& edge : graph.adj[u]) {
            int v = edge.first;     
            int weight = edge.second;

            if (inMST[v] == 0 && weight < key[v]) {
                key[v] = weight;
            }
        }
    }

    return mstWeight;
}

int main() {

    WeightedGraph g(5);

    // 간선 추가 (u, v, weight)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 1);

    int totalWeight = primMST_noSTL(g);

    cout << "총 노드 수: " << g.n << endl;
    cout << "최소 신장 트리의 총 가중치: " << totalWeight << endl; 

    return 0;
}
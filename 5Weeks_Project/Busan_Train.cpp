#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <limits>
#include "station_data.h"

using namespace std;

const int INF = 1000000000;


struct WeightedGraph {
    int n;
    vector<vector<pair<int, int>>> adj;

    explicit WeightedGraph(int n) : n(n), adj(n) {}

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({ v, w });
        if (undirected) {
            adj[v].push_back({ u, w });
        }
    }
};


vector<int> bfs_shortest_stops(const WeightedGraph& graph, int startNode) {
    int N = graph.n;
    vector<int> dist(N, INF);
    vector<int> q_vector;
    int head = 0;

    dist[startNode] = 0;
    q_vector.push_back(startNode);

    while (head < q_vector.size()) {
        int u = q_vector[head];
        head++;

        for (const auto& edge : graph.adj[u]) {
            int v = edge.first;

            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q_vector.push_back(v);
            }
        }
    }
    return dist;
}


WeightedGraph buildGraph(map<string, int>& station_to_index, vector<string>& index_to_station) {

    vector<string> all_stations = get_all_station_names();

    for (int i = 0; i < all_stations.size(); ++i) {
        station_to_index[all_stations[i]] = i;
        index_to_station.push_back(all_stations[i]);
    }

    int NUM_V = all_stations.size();
    WeightedGraph g(NUM_V);

    vector<pair<string, string>> connections = get_line_connections();

    for (const auto& conn : connections) {
        const string& u_name = conn.first;
        const string& v_name = conn.second;

        if (station_to_index.count(u_name) && station_to_index.count(v_name)) {
            int u = station_to_index[u_name];
            int v = station_to_index[v_name];
            g.addEdge(u, v);
        }
        else {
            cerr << "경고: 알 수 없는 역 이름 발견 - " << u_name << " 또는 " << v_name << endl;
        }
    }
    return g;
}


int main() {
    map<string, int> station_to_index;
    vector<string> index_to_station;

    WeightedGraph g = buildGraph(station_to_index, index_to_station);

    cout << "--- 부산 지하철 최소 역 개수 계산 ---" << endl;
    cout << "총 " << g.n << "개 역이 로드되었습니다." << endl;
    cout << "------------------------------------" << endl;

    string start_name, end_name;

    cout << "출발역 이름을 입력하세요: ";
    cin >> start_name;

    cout << "도착역 이름을 입력하세요: ";
    cin >> end_name;

    if (!station_to_index.count(start_name) || !station_to_index.count(end_name)) {
        cout << "오류: 입력하신 출발역 (" << start_name << ") 또는 도착역 (" << end_name << ")이 노선도에 없습니다." << endl;
        cout << "현재 노선도에 있는 역 예시: 서면, 부산진, 연산, 장산, 대저 등" << endl;
        return 1;
    }

    int start_index = station_to_index[start_name];
    int end_index = station_to_index[end_name];

    vector<int> shortest_stops = bfs_shortest_stops(g, start_index);

    int stops = shortest_stops[end_index];

    cout << "\n[검색 결과]" << endl;
    cout << "출발역: " << start_name << endl;
    cout << "도착역: " << end_name << endl;
    cout << "-----------------------------------" << endl;


    cout << start_name << "에서 " << end_name << "까지의 최소 이동 횟수 (역 개수): " << stops << "개 역" << endl;
   

    return 0;
}
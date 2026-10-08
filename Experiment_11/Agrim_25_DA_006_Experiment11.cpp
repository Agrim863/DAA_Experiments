// Agrim Chaturvedi 25/DA/006

// Dijikstra's algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};
typedef pair<int, int> pii;

void dijkstra(int start, const vector<vector<Edge>>& graph, int numVertices) {
    // Distance array initialized to infinity
    vector<int> dist(numVertices, INT_MAX);
    
    // Min-priority queue storing pairs of (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize starting node
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        // Traverse neighbors
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Vertex \t Distance from Source (" << start << ")\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " \t\t ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int vertices = 5;
    vector<vector<Edge>> graph(vertices);

    // Adjacency list representation of a weighted graph
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    dijkstra(0, graph, vertices);
    return 0;
}

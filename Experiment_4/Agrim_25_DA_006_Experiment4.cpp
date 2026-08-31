// Agrim Chaturvedi 25/DA/006

// Connected Components of a Graph using DFS
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    cout << "Enter the edges: ";
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    cout << "Number of connected components: " << components << endl;
    return 0;
}
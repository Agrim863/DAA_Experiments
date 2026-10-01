// Agrim Chaturvedi 25/DA/006

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int u, int parent, int &timer, const vector<vector<int>> &adj,
         vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<bool> &isAP) {
    
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            children++;
            DFS(v, u, timer, adj, disc, low, visited, isAP);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) {
                isAP[u] = true;
            }
        }
    }

    if (parent == -1 && children > 1) {
        isAP[u] = true;
    }
}

int main() {
    int V = 5; 
    vector<vector<int>> adj(V);

    // Default built-in graph structure
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[0].push_back(3); adj[3].push_back(0);
    adj[3].push_back(4); adj[4].push_back(3);

    vector<int> disc(V, -1), low(V, -1);
    vector<bool> visited(V, false), isAP(V, false);
    int timer = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFS(i, -1, timer, adj, disc, low, visited, isAP);
        }
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < V; ++i) {
        if (isAP[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

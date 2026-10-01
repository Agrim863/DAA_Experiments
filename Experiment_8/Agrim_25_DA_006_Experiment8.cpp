// Agrim Chaturvedi 25/DA/006

// Minimum Spanning Tree of a weighted graph using Prism's and Kruskal's algorithms
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int source;
	int destination;
	long long weight;
};

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;

public:
	DisjointSet(int size) : parent(size), rank(size, 0) {
		for (int vertex = 0; vertex < size; ++vertex) {
			parent[vertex] = vertex;
		}
	}

	int find(int vertex) {
		if (parent[vertex] != vertex) {
			parent[vertex] = find(parent[vertex]);
		}
		return parent[vertex];
	}

	bool unite(int first, int second) {
		int firstRoot = find(first);
		int secondRoot = find(second);
		if (firstRoot == secondRoot) {
			return false;
		}

		if (rank[firstRoot] < rank[secondRoot]) {
			parent[firstRoot] = secondRoot;
		} else if (rank[firstRoot] > rank[secondRoot]) {
			parent[secondRoot] = firstRoot;
		} else {
			parent[secondRoot] = firstRoot;
			++rank[firstRoot];
		}
		return true;
	}
};

void kruskalMST(const vector<vector<long long>>& graph) {
	int vertices = static_cast<int>(graph.size());
	vector<Edge> edges;
	for (int source = 0; source < vertices; ++source) {
		for (int destination = source + 1; destination < vertices; ++destination) {
			if (graph[source][destination] != 0) {
				edges.push_back({source, destination, graph[source][destination]});
			}
		}
	}

	sort(edges.begin(), edges.end(), [](const Edge& first, const Edge& second) {
		return first.weight < second.weight;
	});

	DisjointSet sets(vertices);
	vector<Edge> mst;
	long long totalWeight = 0;
	for (const Edge& edge : edges) {
		if (sets.unite(edge.source, edge.destination)) {
			mst.push_back(edge);
			totalWeight += edge.weight;
			if (static_cast<int>(mst.size()) == vertices - 1) {
				break;
			}
		}
	}

	cout << "\nKruskal's algorithm:\n";
	if (static_cast<int>(mst.size()) != vertices - 1) {
		cout << "The graph is disconnected; a minimum spanning tree does not exist.\n";
		return;
	}

	cout << "Edges in the minimum spanning tree:\n";
	for (const Edge& edge : mst) {
		cout << edge.source + 1 << " - " << edge.destination + 1
			 << " : " << edge.weight << '\n';
	}
	cout << "Total weight: " << totalWeight << '\n';
}

int main() {
	int vertices;
	cout << "Enter the number of vertices: ";
	cin >> vertices;
	if (!cin || vertices <= 0) {
		cout << "The number of vertices must be positive.\n";
		return 1;
	}
	vector<vector<long long>> graph(vertices, vector<long long>(vertices));
	cout << "Enter the symmetric adjacency matrix (use 0 where there is no edge):\n";
	for (int row = 0; row < vertices; ++row) {
		for (int column = 0; column < vertices; ++column) {
			cin >> graph[row][column];
		}
	}
	if (!cin) {
		cout << "Invalid adjacency matrix input.\n";
		return 1;
	}
	vector<long long> key(vertices, LLONG_MAX);
	vector<int> parent(vertices, -1);
	vector<bool> inMST(vertices, false);
	key[0] = 0;
	bool primConnected = true;

	for (int count = 0; count < vertices; ++count) {
		int current = -1;
		for (int vertex = 0; vertex < vertices; ++vertex) {
			if (!inMST[vertex] &&
				(current == -1 || key[vertex] < key[current])) {
				current = vertex;
			}
		}

		if (key[current] == LLONG_MAX) {
			cout << "The graph is disconnected; a minimum spanning tree does not exist.\n";
			primConnected = false;
			break;
		}
		inMST[current] = true;
		for (int neighbor = 0; neighbor < vertices; ++neighbor) {
			long long weight = graph[current][neighbor];
			if (weight != 0 && !inMST[neighbor] && weight < key[neighbor]) {
				key[neighbor] = weight;
				parent[neighbor] = current;
			}
		}
	}
	if (primConnected) {
		long long totalWeight = 0;
        cout << "\nPrim's algorithm:\n";
		cout << "Edges in the minimum spanning tree:\n";
		for (int vertex = 1; vertex < vertices; ++vertex) {
			cout << parent[vertex] + 1 << " - " << vertex + 1
				 << " : " << graph[vertex][parent[vertex]] << '\n';
			totalWeight += graph[vertex][parent[vertex]];
		}
		cout << "Total weight: " << totalWeight << '\n';
	}

	kruskalMST(graph);
	return 0;
}

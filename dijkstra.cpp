#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void dijkstra(int source, vector<vector<pii>>& graph, int n) {
    vector<int> dist(n, INT_MAX); // Store shortest distances
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

    // Initialize source
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // If the current distance is greater than the stored distance, skip
        if (currDist > dist[currNode]) continue;

        // Traverse neighbors
        for (auto& neighbor : graph[currNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[currNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n, m; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n); // Adjacency list

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Comment this line for a directed graph
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(source, graph, n);

    return 0;
}

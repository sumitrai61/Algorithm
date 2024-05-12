#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false); 
    queue<int> q; 

    q.push(start); 
    visited[start] = true; 

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " "; 

        
        for (int i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    cout << "Breadth First Search starting from vertex " << start << ": ";
    BFS(graph, start);
    cout << endl;

    return 0;
}

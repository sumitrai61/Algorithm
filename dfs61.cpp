#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false); 
    stack<int> stk;

    stk.push(start);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (!visited[current]) {
            cout << current << " "; 
            visited[current] = true;

            
            for (int i = 0; i < graph[current].size(); ++i) {
                int neighbor = graph[current][i];
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                }
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    cout << "Depth First Search starting from vertex " << start << ": ";
    DFS(graph, start);
    cout << endl;

    return 0;
}

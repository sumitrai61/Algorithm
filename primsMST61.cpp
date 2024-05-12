 #include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent a vertex
struct Vertex {
    int key;
    int parent;
    bool inMST;
    Vertex() : key(INF), parent(-1), inMST(false) {}
};

// Function to find the vertex with minimum key value
int findMinKey(const vector<Vertex> &vertices) {
    int minKey = INF;
    int minIndex = -1;
    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].inMST && vertices[i].key < minKey) {
            minKey = vertices[i].key;
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to print the adjacency matrix
void printAdjMatrix(const vector<vector<int>> &graph) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto &row : graph) {
        for (int weight : row) {
            if (weight == INF)
                cout << "INF ";
            else
                cout << weight << " ";
        }
        cout << endl;
    }
}

// Function to print the MST edges
void printMST(const vector<Vertex> &vertices) {
    cout << "Minimum Spanning Tree (MST):" << endl;
    cout << "Edge \t Weight" << endl;
    for (int i = 1; i < vertices.size(); ++i) {
        cout << vertices[i].parent << " - " << i << "\t  " << vertices[i].key << endl;
    }
}

// Prim's algorithm to find Minimum Spanning Tree
void MST_Prim(vector<vector<int>> &graph, int startVertex) {
    int V = graph.size(); // Number of vertices
    vector<Vertex> vertices(V);

    // Initialize vertices
    for (int i = 0; i < V; ++i) {
        vertices[i].key = INF;
        vertices[i].parent = -1;
    }

    vertices[startVertex].key = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(vertices);
        vertices[u].inMST = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !vertices[v].inMST && graph[u][v] < vertices[v].key) {
                vertices[v].parent = u;
                vertices[v].key = graph[u][v];
            }
        }
    }

    // Print Adjacency Matrix and MST
    printAdjMatrix(graph);
    printMST(vertices);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize the graph with all edges as INF
    vector<vector<int>> graph(V, vector<int>(V, INF));

    cout << "Enter the weights for edges ('0' for no edge):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << "Enter weight for edge from vertex " << i << " to vertex " << j << ": ";
            cin >> graph[i][j];
        }
    }

    int startVertex;
    cout << "Enter the starting vertex (0-based indexing): ";
    cin >> startVertex;

    MST_Prim(graph, startVertex);

    return 0;
}

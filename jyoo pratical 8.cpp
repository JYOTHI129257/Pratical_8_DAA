
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj = new vector<int>[V];
    }

    // Add edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS traversal
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbour : adj[vertex]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);
            }
        }
    }

    void DFS(int start) {
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;

        delete[] visited;
    }

    // BFS traversal
    void BFS(int start) {
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbour : adj[vertex]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
        delete[] visited;
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.DFS(0);
    g.BFS(0);

    return 0;
}

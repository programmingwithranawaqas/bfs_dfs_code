#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
using namespace std;

class Graph {
private:
    int numVertices;
    bool directed;
    vector<list<int>> adjList;

public:
    Graph(int ver, bool isDir = false) {
        numVertices = ver;
        directed = isDir;
        adjList.resize(ver);
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
            cout << "Invalid Edge\n";
            return;
        }
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void removeEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
            cout << "Invalid Edge\n";
            return;
        }
        adjList[u].remove(v);
        if (!directed) {
            adjList[v].remove(u);
        }
    }

    void display() {
        cout << "Adjacency List (Unweighted Graph) : " << endl;
        for (int i = 1; i < numVertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " , ";
            }
            cout << endl;
        }
    }

    // Iterative DFS using Stack
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(startVertex);
        cout << "DFS Traversal starting from vertex " << startVertex << ": ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout<<"BFS Traversal starting from vertex "<<startVertex<<" : ";

        while(!q.empty())
        {
             int current = q.front();
             q.pop();
             cout<<current<<" ";

             for(int neighbor: adjList[current])
             {
                 if(!visited[neighbor])
                 {
                     visited[neighbor] = true;
                     q.push(neighbor);
                 }
             }
        }
        cout<<endl;
    }
};

int main() {
    Graph g(11);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(3, 9);
    g.addEdge(3, 10);
    g.addEdge(3, 4);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(5, 6);
    g.addEdge(7, 8);

    g.display();

    g.DFS(1); // DFS Traversal
    g.BFS(1); // BFS Traversal

    return 0;
}

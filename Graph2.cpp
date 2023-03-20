#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices, **adjMatrix;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
        adjMatrix = new int *[vertices + 1];
        for (int i = 0; i <= vertices; i++)
        {
            adjMatrix[i] = new int[vertices + 1];
            for (int j = 0; j <= vertices; j++)
                adjMatrix[i][j] = 0;
        }
    }
    void addEdge(int src, int dest)
    {
        adjLists[src].push_front(dest);
    }
    void DFS(int vertex)
    {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        cout << vertex << " ";

        for (auto i = adjList.begin(); i != adjList.end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }
    void showAdjMatrix()
    {
        int vtxR = 0, vtxC = 1;
        for (int i = 0; i <= numVertices; i++)
        {
            for (int j = 0; j <= numVertices; j++)
            {
                if (i == 0)
                {
                    cout << vtxR++ << "\t";
                }
                else if (j == 0)
                {
                    cout << vtxC++ << "\t";
                }
                else
                    cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(7);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.showAdjMatrix();
}
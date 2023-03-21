#include <bits/stdc++.h>
using namespace std;

struct Graph
{
private:
    int numVertices;
    int **adjMatrix;
    bool *visitedDFS;
    bool *visitedBFS;
    vector<int> visitOrderDFS;
    vector<int> visitOrderBFS;
    void DFS_visit(int v)
    {
        visitedDFS[v] = true;
        visitOrderDFS.push_back(v);
        for (int i = 0; i <= numVertices; i++)
        {
            if (i != v && adjMatrix[v][i] == 1 && visitedDFS[i] == false)
                DFS_visit(i);
        }
    }
    void BFS_visit(int v)
    {
        visitedBFS[v] = true;
        visitOrderBFS.push_back(v);
        for (int i = v; i <= numVertices; i++)
        {
            for (int j = 0; j <= numVertices; j++)
            {
                if (i != j && adjMatrix[i][j] == 1 && visitedBFS[j] == false)
                {
                    visitedBFS[j] = true;
                    visitOrderBFS.push_back(j);
                }
            }
        }
    }

public:
    Graph(int v) : numVertices(v)
    {
        adjMatrix = new int *[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices + 1];
            for (int j = 0; j <= numVertices; j++)
                adjMatrix[i][j] = 0;
        }
        visitedDFS = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visitedDFS[i] = false;
        visitedBFS = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visitedBFS[i] = false;
    }
    void addEdge(int from, int to)
    {
        if (from > numVertices)
            cout << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << to << " does not exist in your graph" << endl;
        else
        {
            adjMatrix[from][to] = 1;
            adjMatrix[to][from] = 1;
        }
    }
    void removeEdge(int from, int to)
    {
        if (from > numVertices)
            cout << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << to << " does not exist in your graph" << endl;
        else
        {
            adjMatrix[from][to] = 0;
            adjMatrix[to][from] = 0;
        }
    }
    void showAdjMatrix()
    {
        int numR = 0, numC = 1;
        for (int i = 1; i <= numVertices; i++)
        {
            for (int j = 1; j <= numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int v)
    {
        DFS_visit(v);
        for (int i = 0; i < visitOrderDFS.size(); i++)
        {
            cout << visitOrderDFS[i] << "\t";
        }
        cout << endl;
    }
    void BFS(int v)
    {
        BFS_visit(v);
        for (int i = 0; i < visitOrderBFS.size(); i++)
        {
            cout << visitOrderBFS[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    Graph graph(9);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 5);
    graph.addEdge(2, 7);
    graph.addEdge(3, 4);
    graph.addEdge(3, 9);
    graph.addEdge(9, 8);
    graph.addEdge(6, 8);
    graph.addEdge(5, 6);
    // graph.showAdjMatrix();
    graph.DFS(1);
    graph.BFS(1);
}
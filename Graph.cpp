#include <bits/stdc++.h>
using namespace std;

struct Graph
{
private:
    int numVertices, visitCountBFS = 0, visitCountDFS = 0;
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
            if (i != v && adjMatrix[v][i] == 1 && visitedDFS[i] == false)
                DFS_visit(i);
    }
    void BFS_visit(int v)
    {
        visitedBFS[v] = true;
        queue<int> que;
        que.push(v);
        while (!que.empty())
        {
            for (int i = 0; i <= numVertices; i++)
                if (adjMatrix[que.front()][i] == 1 && visitedBFS[i] == false)
                {
                    visitedBFS[i] = true;
                    que.push(i);
                }
            visitOrderBFS.push_back(que.front());
            que.pop();
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
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
        else
        {
            adjMatrix[from][to] = 1;
            adjMatrix[to][from] = 1;
        }
    }
    void removeEdge(int from, int to)
    {
        if (from > numVertices)
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
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
    // void showAdjMatrix()
    // {
    //     int vtxR = 0, vtxC = 1;
    //     for (int i = 0; i <= vertex; i++)
    //     {
    //         for (int j = 0; j <= vertex; j++)
    //         {
    //             if (i == 0)
    //             {
    //                 cout << vtxR++ << "\t";
    //             }
    //             else if (j == 0)
    //             {
    //                 cout << vtxC++ << "\t";
    //             }
    //             else
    //                 cout << adjMatrix[i][j] << "\t";
    //         }
    //         cout << endl;
    //     }
    // }

    void DFS(int v)
    {
        DFS_visit(v);
        cout << "DFS visit order : ";
        for (int i = 0; i < visitOrderDFS.size(); i++)
        {
            cout << visitOrderDFS[i] << "\t";
        }
        cout << endl;
    }
    void BFS(int v)
    {
        BFS_visit(v);
        cout << "BFS visit order : ";
        for (int i = 0; i < visitOrderBFS.size(); i++)
        {
            cout << visitOrderBFS[i] << "\t";
        }
        cout << endl;
    }
    ~Graph()
    {
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph graph(15);
    graph.addEdge(1, 5);
    graph.addEdge(1, 6);
    graph.addEdge(1, 8);
    graph.addEdge(2, 6);
    graph.addEdge(2, 3);
    graph.addEdge(2, 10);
    graph.addEdge(11, 10);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(4, 12);
    graph.addEdge(9, 7);
    graph.addEdge(14, 7);
    graph.addEdge(14, 5);
    graph.addEdge(13, 7);
    graph.addEdge(11, 15);
    graph.addEdge(11, 3);
    graph.showAdjMatrix();
    graph.DFS(1);
    graph.BFS(1);
}
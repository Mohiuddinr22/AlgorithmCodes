#include<bits/stdc++.h>
using namespace std;

struct Undirected_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedDFS, *visitedBFS, *visited;
    vector<int> visitOrderDFS, visitOrderBFS; //, visited;
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
    bool cycle_Visit(int v)
    {
        visited[v] = true;
        for (int i = 0; i <= numVertices; i++)
        {
            if (adjMatrix[v][i] == 1)
            {
                if (!visited[i])
                {
                    if (cycle_Visit(i))
                        return true;
                }
                else if (i != INT_MIN)
                    return true;
            }
        }
        return false;
    }

public:
    Undirected_Graph(int v) : numVertices(v)
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
        visited = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visited[i] = false;
    }
    bool cycleExists()
    {
        for (int i = 0; i <= numVertices; i++)
        {
            if (!visited[i])
                if (cycle_Visit(i))
                    return true;
        }
        return false;
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
            if (i != visitOrderDFS.size() - 1)
                cout << visitOrderDFS[i] << " -> ";
            else
                cout << visitOrderDFS[i] << endl;
        }
    }
    void BFS(int v)
    {
        BFS_visit(v);
        cout << "BFS visit order : ";
        for (int i = 0; i < visitOrderBFS.size(); i++)
        {
            if (i != visitOrderBFS.size() - 1)
                cout << visitOrderBFS[i] << " -> ";
            else
                cout << visitOrderBFS[i] << endl;
        }
    }
    ~Undirected_Graph()
    {
        visitOrderBFS.clear();
        visitOrderDFS.clear();
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix, visitedBFS, visitedDFS;
    }
};

int main(){}
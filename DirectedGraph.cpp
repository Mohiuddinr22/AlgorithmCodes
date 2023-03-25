#include <bits/stdc++.h>
using namespace std;

struct Directed_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS, *visited;
    vector<int> visitOrderBFS, visitOrderDFS;
    enum Color
    {
        WHITE,
        GREY,
        BLACK
    };
    Color *colors;
    void BFS_visit(int v)
    {
        visitedBFS[v] = true;
        queue<int> queue;
        queue.push(v);
        while (!queue.empty())
        {
            for (int i = 0; i <= numVertices; i++)
            {
                if (adjMatrix[queue.front()][i] == 1 && visitedBFS[i] == false)
                {
                    visitedBFS[i] = true;
                    queue.push(i);
                }
            }
            visitOrderBFS.push_back(queue.front());
            queue.pop();
        }
    }
    void DFS_visit(int v)
    {
        visitedDFS[v] = true;
        visitOrderDFS.push_back(v);
        for (int i = 0; i <= numVertices; i++)
            if (adjMatrix[v][i] == 1 && visitedDFS[i] == false)
                DFS_visit(i);
    }
    /*bool cycle_Visit(int v)
    {
        visited[v] = true;
        for (int i = 0; i < numVertices; i++)
            if (adjMatrix[v][i] == 1)
            {
                if (!visited[i])
                {
                    if (cycle_Visit(i))
                        return true;
                }
                else if (i != INT32_MIN)
                    return true;
            }
        return false;
    }*/
    bool cycle_Visit(int v)
    {
        colors[v] = GREY;
        for (int i = 0; i <= numVertices; i++)
        {
            if (adjMatrix[v][i] != 0)
            {
                if (colors[i] == GREY)
                    return true;
                else if (colors[i] == WHITE && cycle_Visit(i))
                    return true;
            }
        }
        colors[v] = BLACK;
        return false;
    }

public:
    Directed_Graph(int v) : numVertices(v)
    {
        adjMatrix = new int *[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices + 1];
            for (int j = 0; j <= numVertices; j++)
                adjMatrix[i][j] = 0;
        }
        visitedBFS = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visitedBFS[i] = false;
        visitedDFS = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visitedDFS[i] = false;
        visited = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visited[i] = false;
        colors = new Color[numVertices + 1];
        memset(colors, WHITE, sizeof(colors) * (numVertices + 1));
    }
    void addEdge(int from, int to)
    {
        if (from > numVertices)
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
        else
            adjMatrix[from][to] = 1;
    }
    void removeEdge(int from, int to)
    {
        if (from > numVertices)
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
        else
            adjMatrix[from][to] = 0;
    }
    void BFS(int v)
    {
        BFS_visit(v);
        cout << "BFS visit order : ";
        for (int i = 0; i < visitOrderBFS.size(); i++)
        {
            if (i != visitOrderBFS.size() - 1)
                cout << visitOrderBFS[i] << "->";
            else
                cout << visitOrderBFS[i] << endl;
        }
    }
    void DFS(int v)
    {
        DFS_visit(v);
        cout << "DFS visit order : ";
        for (int i = 0; i < visitOrderDFS.size(); i++)
        {
            if (i != visitOrderDFS.size() - 1)
                cout << visitOrderDFS[i] << "->";
            else
                cout << visitOrderDFS[i] << endl;
        }
    }
    /*bool cycleExists()
    {
        for (int i = 0; i <= numVertices; i++)
        {
            if (!visited[i])
                if (cycle_Visit(i))
                    return true;
        }
        return false;
    }*/
    bool cycleExists()
    {
        for (int i = 1; i <= numVertices; i++)
        {
            if (colors[i] == WHITE)
            {
                if (cycle_Visit(i))
                    return true;
            }
        }
        return false;
    }
    void showAdjMatrix()
    {
        for (int i = 1; i <= numVertices; i++)
        {
            for (int j = 1; j <= numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
    ~Directed_Graph()
    {
        visitOrderBFS.clear();
        visitOrderDFS.clear();
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix, visitedBFS, visitedDFS;
    }
};

int main()
{
    Directed_Graph graph(5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    // graph.addEdge(5, 1);
    graph.cycleExists() ? cout << "Exists" : cout << "Doesn't";
}
#include <bits/stdc++.h>
using namespace std;

struct Directed_Weighted_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS;
    vector<int> visitOrderBFS, visitOrderDFS;
    vector<pair<pair<int, int>, int>> edge;

    bool weight_exists(int weight_to_check)
    {
        return any_of(
            edge.begin(), edge.end(),
            [weight_to_check](const pair<pair<int, int>, int> &p)
            {
                return p.second == weight_to_check;
            });
    }
    void BFS_visit(int v)
    {
        visitedBFS[v] = true;
        queue<int> queue;
        queue.push(v);
        while (!queue.empty())
        {
            for (int i = 0; i <= numVertices; i++)
            {
                if (adjMatrix[queue.front()][i] != 0 && visitedBFS[i] == false)
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
            if (adjMatrix[v][i] != 0 && visitedDFS[i] == false)
                DFS_visit(i);
    }

public:
    Directed_Weighted_Graph(int v) : numVertices(v)
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
    void addEdge(int from, int to, int weight)
    {
        if (from > numVertices)
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
        else
        {
            adjMatrix[from][to] = weight;
            edge.push_back(make_pair(make_pair(from, to), weight));
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
            edge.erase(
                remove_if(edge.begin(), edge.end(),
                          [from, to](const pair<pair<int, int>, int> &pair)
                          {
                              return pair.first.first == from && pair.first.second == to;
                          }),
                edge.end());
        }
    }
    void removeEdge(int weight)
    {
        if (!weight_exists(weight))
            cout << "An edge with " << weight << " weight does not exist in your graph" << endl;
        else
        {
            for (int i = 0; i <= numVertices; i++)
            {
                for (int j = 0; j <= numVertices; j++)
                    if (adjMatrix[i][j] == weight)
                    {
                        adjMatrix[i][j] = 0;
                    }
            }
            edge.erase(remove_if(edge.begin(), edge.end(),
                                 [weight](const pair<pair<int, int>, int> &pair)
                                 {
                                     return pair.second == weight;
                                 }),
                       edge.end());
        }
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
    void showEdges()
    {
        for (int i = 0; i < edge.size(); i++)
            cout << edge[i].first.first << " <-------" << edge[i].second << "-------> " << edge[i].first.second << endl;
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
    ~Directed_Weighted_Graph()
    {
        visitOrderBFS.clear();
        visitOrderDFS.clear();
        edge.clear();
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix, visitedBFS, visitedDFS;
    }
};

struct UnDirected_Weighted_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS;
    vector<int> visitOrderBFS, visitOrderDFS;
    vector<pair<pair<int, int>, int>> edge;

    bool weight_exists(int weight_to_check)
    {
        return any_of(
            edge.begin(), edge.end(),
            [weight_to_check](const pair<pair<int, int>, int> &p)
            {
                return p.second == weight_to_check;
            });
    }
    void BFS_visit(int v)
    {
        visitedBFS[v] = true;
        queue<int> queue;
        queue.push(v);
        while (!queue.empty())
        {
            for (int i = 0; i <= numVertices; i++)
            {
                if (adjMatrix[queue.front()][i] > 0 && visitedBFS[i] == false)
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
            if (adjMatrix[v][i] != 0 && visitedDFS[i] == false)
                DFS_visit(i);
    }

public:
    UnDirected_Weighted_Graph(int v) : numVertices(v)
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
    void addEdge(int from, int to, int weight)
    {
        if (from > numVertices)
            cout << "Vertex " << from << " does not exist in your graph" << endl;
        if (to > numVertices)
            cout << "Vertex " << to << " does not exist in your graph" << endl;
        else
        {
            adjMatrix[from][to] = weight;
            adjMatrix[to][from] = weight;
            edge.push_back(make_pair(make_pair(from, to), weight));
            edge.push_back(make_pair(make_pair(to, from), weight));
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
            edge.erase(
                remove_if(edge.begin(), edge.end(),
                          [from, to](const pair<pair<int, int>, int> &pair)
                          {
                              return pair.first.first == from && pair.first.second == to;
                          }),
                edge.end());
            edge.erase(
                remove_if(edge.begin(), edge.end(),
                          [from, to](const pair<pair<int, int>, int> &pair)
                          {
                              return pair.first.first == to && pair.first.second == from;
                          }),
                edge.end());
        }
    }
    void removeEdge(int weight)
    {
        if (!weight_exists(weight))
            cout << "An edge with " << weight << " weight does not exist in your graph" << endl;
        else
        {
            for (int i = 0; i <= numVertices; i++)
            {
                for (int j = 0; j <= numVertices; j++)
                    if (adjMatrix[i][j] == weight)
                    {
                        adjMatrix[i][j] = 0;
                        adjMatrix[j][i] = 0;
                    }
            }
            edge.erase(remove_if(edge.begin(), edge.end(),
                                 [weight](const pair<pair<int, int>, int> &pair)
                                 {
                                     return pair.second == weight;
                                 }),
                       edge.end());
        }
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
    void showEdges()
    {
        for (int i = 0; i < edge.size(); i++)
            cout << edge[i].first.first << " <-------" << edge[i].second << "-------> " << edge[i].first.second << endl;
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
    ~UnDirected_Weighted_Graph()
    {
        visitOrderBFS.clear();
        visitOrderDFS.clear();
        edge.clear();
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix, visitedBFS, visitedDFS;
    }
};

struct Directed_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS;
    vector<int> visitOrderBFS, visitOrderDFS;
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
    bool cycleExists()
    {
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

struct Undirected_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedDFS, *visitedBFS;
    vector<int> visitOrderDFS, visitOrderBFS;
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
    ~Undirected_Graph()
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
    Undirected_Graph graph(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);
    graph.DFS(1);
}
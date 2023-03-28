#include <bits/stdc++.h>
using namespace std;

struct Undirected_Weighted_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS;
    vector<int> visitOrderBFS, visitOrderDFS, visited;
    vector<pair<pair<int, int>, int>> edge;
    bool cycle_Visit(int v, int x)
    {
        visited[v] = true;
        for (int i = 0; i < numVertices; i++)
            if (adjMatrix[v][i] != 0)
            {
                if (!visited[i])
                {
                    if (cycle_Visit(i, v))
                        return true;
                }
                else if (i != x)
                    return true;
            }
        return false;
    }
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
    static bool compare(const pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
    {
        return a.second < b.second;
    }
    bool exists(vector<int> &arr, int val)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == val)
                return true;
        }
        return false;
    }

public:
    Undirected_Weighted_Graph(int v) : numVertices(v)
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
    bool cycleExists()
    {
        for (int i = 0; i <= numVertices; i++)
        {
            if (!visited[i])
                if (cycle_Visit(i, -1))
                    return true;
        }
        return false;
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
    vector<int> DFS(int v)
    {
        DFS_visit(v);
        return visitOrderDFS;
    }
    void showDFS(int v)
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
    bool connected()
    {
        for (int i = 1; i <= numVertices; i++)
        {
            if (DFS(i).size() != numVertices)
                return false;
        }
        return true;
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
    void MST_Prims()
    {
        vector<int> visitedNodes;
        vector<pair<int, int>> edgesMST;
        int totalWeight = 0;
        sort(edge.begin(), edge.end(), compare);
        visitedNodes.push_back(edge[0].first.first);
        visitedNodes.push_back(edge[0].first.second);
        edgesMST.push_back({edge[0].first.second, edge[0].first.first});
        while (edgesMST.size() < numVertices - 1)
        {
            int minWeight = INT_MAX;
            pair<int, int> minEdge;
            for (int i = 0; i < visitedNodes.size(); i++)
            {
                for (int j = 1; j <= numVertices; j++)
                {
                    if (!exists(visitedNodes, j) && adjMatrix[visitedNodes[i]][j] != 0 && adjMatrix[visitedNodes[i]][j] < minWeight)
                    {
                        minWeight = adjMatrix[visitedNodes[i]][j];
                        minEdge = make_pair(visitedNodes[i], j);
                    }
                }
            }
            edgesMST.push_back(minEdge);
            visitedNodes.push_back(minEdge.second);
        }
        cout << "Minimum Spanning Tree Edges: " << endl;
        for (int i = 0; i < edgesMST.size(); i++)
        {
            cout << edgesMST[i].first << " <-------" << adjMatrix[edgesMST[i].first][edgesMST[i].second] << "------->" << edgesMST[i].second << endl;
        }
    }
    ~Undirected_Weighted_Graph()
    {
        visitOrderBFS.clear();
        visitOrderDFS.clear();
        edge.clear();
        for (int i = 0; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix, visitedBFS, visitedDFS;
    }
};

int main()
{
    Undirected_Weighted_Graph graph(9);
    graph.addEdge(1, 2, 9);
    graph.addEdge(1, 3, 12);
    graph.addEdge(1, 4, 8);
    graph.addEdge(1, 6, 11);
    graph.addEdge(1, 9, 11);
    graph.addEdge(2, 4, 6);
    graph.addEdge(2, 6, 8);
    graph.addEdge(3, 6, 13);
    graph.addEdge(3, 9, 10);
    graph.addEdge(4, 6, 5);
    graph.addEdge(4, 8, 7);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 9);
    graph.addEdge(5, 8, 11);
    graph.addEdge(6, 8, 9);
    graph.addEdge(6, 7, 8);
    graph.addEdge(6, 9, 7);
    graph.addEdge(7, 8, 11);
    graph.addEdge(7, 9, 10);
    graph.addEdge(8, 9, 8);
    // graph.MST_Prims();
    cout << graph.connected();
}
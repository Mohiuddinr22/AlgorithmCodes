#include <bits/stdc++.h>
using namespace std;

struct Directed_Weighted_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS, *visited;
    vector<int> visitOrderBFS, visitOrderDFS;
    vector<pair<pair<int, int>, int>> edge;
    enum Color
    {
        WHITE,
        GREY,
        BLACK
    };
    Color *color;
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
    /*bool cycle_Visit(int v, int x)
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
    }*/
    bool cycle_Visit(int v)
    {
        color[v] = GREY;
        for (int i = 1; i <= numVertices; i++)
        {
            if (adjMatrix[v][i] != 0)
            {
                if (color[i] == GREY)
                    return true;
                else if (color[i] == WHITE && cycle_Visit(i))
                    return true;
            }
        }
        color[v] = BLACK;
        return false;
    }
    static bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
    {
        return a.second < b.second;
    }
    bool exists(vector<int> &arr, int val)
    {
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == val)
                return true;
        return false;
    }
    int adjLowest(int v)
    {
        vector<int> weight;
        for (int i = 0; i <= numVertices; i++)
        {
            if (adjMatrix[v][i] != 0)
                weight.push_back(adjMatrix[v][i]);
        }
        int lowest = weight[0];
        for (int i = 1; i < weight.size(); i++)
            if (weight[i] < lowest)
                lowest = weight[i];
        return lowest;
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
        memset(visitedDFS, 0, sizeof(visitedDFS));
        visitedBFS = new bool[numVertices + 1];
        memset(visitedBFS, 0, sizeof(visitedBFS));
        visited = new bool[numVertices + 1];
        memset(visited, 0, sizeof(visited));
        color = new Color[numVertices + 1];
        memset(color, WHITE, sizeof(color) * (numVertices + 1));
    }
    bool cycleExists()
    {
        for (int i = 1; i <= numVertices; i++)
        {
            if (color[i] == WHITE)
            {
                if (cycle_Visit(i))
                    return true;
            }
        }
        return false;
    }
    /*bool cycleExists()
    {
        for (int i = 0; i <= numVertices; i++)
        {
            if (!visited[i])
                if (cycle_Visit(i, -1))
                    return true;
        }
        return false;
    }*/
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
    void MST_Kruskals()
    {
        sort(edge.begin(), edge.end(), compare);
        vector<int> visitedNodes;
        visitedNodes.push_back(edge[0].first.first);
        Directed_Weighted_Graph mstGraph(numVertices);
        int totalWeight = 0;
        for (int i = 0; i < edge.size(); i++)
        {
            if (!exists(visitedNodes, edge[i].first.second))
            {
                visitedNodes.push_back(edge[i].first.second);
                mstGraph.addEdge(edge[i].first.first, edge[i].first.second, edge[i].second);
                totalWeight += edge[i].second;
            }
            if (mstGraph.cycleExists())
            {
                totalWeight -= edge[i].second;
                mstGraph.removeEdge(edge[i].first.first, edge[i].first.second);
            }
        }
        mstGraph.showEdges();
        cout << "Total MST weight : " << totalWeight << endl;
    }
    void MST_Prims()
    {
        vector<int> visitedNodes(numVertices);
        sort(edge.begin(), edge.end(), compare);
        visitedNodes.push_back(edge[0].first.first);
        Directed_Weighted_Graph graph(numVertices);
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

int main()
{
    Directed_Weighted_Graph graph(6);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 3);
    graph.addEdge(1, 5, 2);
    graph.addEdge(1, 6, 1);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 3);
    graph.addEdge(3, 5, 5);
    graph.addEdge(3, 6, 2);
    graph.showEdges();
    graph.cycleExists() ? cout << "Exists" << endl : cout << "Doesn't exist" << endl;
    graph.MST_Kruskals();
}
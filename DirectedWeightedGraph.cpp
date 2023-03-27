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
    int lowest(vector<int> &weight)
    {
        int lowestVal = weight[0];
        for (int i = 1; i < weight.size(); i++)
            if (weight[i] < lowestVal)
                lowestVal = weight[i];
        return lowestVal;
    }
    void eraseElement(vector<int> &arr, int val)
    {
        auto it = find(arr.begin(), arr.end(), val);
        if (it != arr.end())
            arr.erase(it);
    }
    pair<int, int> minVertex(vector<int> &mstSet)
    {
        int min = INT_MAX;
        int vertex;
        pair<int, int> e;
        for (int i = 1; i <= mstSet.size(); i++)
            for (int j = 1; j <= numVertices; j++)
                if (!exists(mstSet, j) && adjMatrix[i][j] < min)
                {
                    vertex = i;
                    min = adjMatrix[i][j];
                    e = make_pair(i, vertex);
                }
        return e;
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
    /**/
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
    vector<int> DFS(int v)
    {
        DFS_visit(v);
        return visitOrderDFS;
        /*cout << "DFS visit order : ";
        for (int i = 0; i < visitOrderDFS.size(); i++)
        {
            if (i != visitOrderDFS.size() - 1)
                cout << visitOrderDFS[i] << "->";
            else
                cout << visitOrderDFS[i] << endl;
        }*/
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
            if (DFS(i).size() == numVertices)
                return true;
        }
        return false;
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
        if (!connected())
        {
            cout << "Graph is not connected, can't find MST" << endl;
            return;
        }
        sort(edge.begin(), edge.end(), compare);
        vector<int> visitedNodes;
        visitedNodes.push_back(edge[0].first.first);
        Directed_Weighted_Graph mstGraph(numVertices);
        int totalWeight = 0, i;
        for (i = 0; i < edge.size(); i++)
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
    /*void MST_Prims()
    {
        int track[numVertices];
        vector<int> val(numVertices, INT_MAX);
        vector<bool> mstSet(numVertices, false);
        track[0] = -1;
        val[0] = 0;
        for (int i = 1; i < numVertices; i++)
        {
            int minVx = minVertex(val, mstSet);
            mstSet[minVx] = true;
            for (int j = 1; j <= numVertices; j++)
            {
                if (adjMatrix[minVx][j] != 0 && mstSet[j] == false && adjMatrix[minVx][j] < val[j])
                {
                    val[j] = adjMatrix[minVx][j];
                    track[j] = minVx;
                }
            }
        }
        for (int i = 1; i <= numVertices; i++)
            cout << track[i] << "<----" << adjMatrix[track[i]][i] << "---->" << i << endl;
    }*/
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
}
// graph.BFS(1);
// graph.showDFS(1);
// graph.connected() ? cout << "is" : cout << "isn't";
// // graph.showEdges();
// graph.cycleExists() ? cout << "Exists" << endl : cout << "Doesn't exist" << endl;
// graph.MST_Kruskals();
// }
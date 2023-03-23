#include <bits/stdc++.h>
using namespace std;

struct Directed_Graph
{
private:
    int numVertices, **adjMatrix;
    bool *visitedBFS, *visitedDFS;
    vector<int> visitOrderBFS, visitOrderDFS;

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
    ~Directed_Graph()
    {
        
    }
};

int main() {}
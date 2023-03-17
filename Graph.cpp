#include <bits/stdc++.h>
using namespace std;

struct Graph
{
private:
    int vertex;
    int **adjMatrix;

public:
    Graph(int v) : vertex(v)
    {
        adjMatrix = new int *[v + 1];
        for (int i = 0; i <= v; i++)
        {
            adjMatrix[i] = new int[v + 1];
            for (int j = 0; j <= v; j++)
                adjMatrix[i][j] = 0;
        }
    }
    void addEdge(int start, int end)
    {
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
    }
    void removeEdge(int start, int end)
    {
        adjMatrix[start][end] = 0;
        adjMatrix[end][start] = 0;
    }
    void showAdjMatrix()
    {
        int vtxR = 0, vtxC = 1;
        for (int i = 0; i <= vertex; i++)
        {
            for (int j = 0; j <= vertex; j++)
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
    ~Graph()
    {
        for (int i = 0; i <= vertex; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(1, 4);
    graph.addEdge(1, 3);
    graph.addEdge(4, 5);
    graph.addEdge(3, 5);

    graph.showAdjMatrix();
}
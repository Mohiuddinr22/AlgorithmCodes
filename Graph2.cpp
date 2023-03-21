#include <bits/stdc++.h>
using namespace std;

/*struct Stack
{
private:
    vector<int> stack;

public:
    void push(int item)
    {
        stack.push_back(item);
    }
    void pop()
    {
        stack.pop_back();
    }
    void showStack()
    {
        for (int i = 0; i < stack.size(); i++)
            cout << stack[i] << "\t";
        cout << endl;
    }
    int top()
    {
        return stack[stack.size() - 1];
    }
    bool exists(int v)
    {
        for (int i = 0; i < stack.size(); i++)
            if (stack[i] == v)
                return true;
        return false;
    }
};

struct Queue
{
private:
    vector<int> queue;

public:
    void enqueue(int item)
    {
        queue.push_back(item);
    }
    void dequeue()
    {
        for (int i = 0; i < queue.size() - 1; i++)
        {
            queue.at(i) = queue[i + 1];
        }
        queue.resize(queue.size() - 1);
    }
    void showQueue()
    {
        for (int i = 0; i < queue.size(); i++)
        {
            cout << queue[i] << "\t";
        }
        cout << endl;
    }
    bool exists(int v)
    {
        for (int i = 0; i < queue.size(); i++)
            if (queue[i] == v)
                return true;
        return false;
    }
};*/

struct Graph
{
private:
    int numVertices;
    int **adjMatrix;
    bool *visited;
    void DFS_visit(int v)
    {
        visited[v] = true;
        for (int i = 0; i <= numVertices; i++)
        {
            if (i != v && adjMatrix[v][i] == 1 && visited[i] == false)
                DFS_visit(i);
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
        visited = new bool[numVertices + 1];
        for (int i = 0; i <= numVertices; i++)
            visited[i] = false;
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
        adjMatrix[from][to] = 0;
        adjMatrix[to][from] = 0;
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
        for (int i = 0; i <= numVertices; i++)
        {
            if (visited[i] == true)
                cout << i << "\t";
        }
        cout << endl;
    }
};

int main()
{
    Graph graph(10);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 6);
    graph.addEdge(3, 6);
    graph.addEdge(3, 5);
    graph.addEdge(6, 7);
    graph.addEdge(6, 8);
    graph.addEdge(8, 9);
    graph.addEdge(9, 10);
    graph.addEdge(4, 10);
    graph.addEdge(4, 5);
    graph.addEdge(5, 9);
    graph.removeEdge(6, 7);
    graph.showAdjMatrix();
    graph.DFS(1);
}
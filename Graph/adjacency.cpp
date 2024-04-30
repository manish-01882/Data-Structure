#include <iostream>
using namespace std;
int a[50][50], n, visited[50];
int q[20], front = -1, rear = -1;
int s[20], top = -1, count = 0;
void bfs(int v)
{
    int i, cur;
    visited[v] = 1;
    q[++rear] = v;
    while (front != rear)
    {
        cur = q[++front];
        for (i = 1; i <= n; i++)
        {
            if ((a[cur][i] == 1) && (visited[i] == 0))
            {
                q[++rear] = i;
                visited[i] = 1;
                cout << i;
            }
        }
    }
}
void dfs(int v)
{
    int i;
    visited[v] = 1;
    s[++top] = v;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            cout << i;
            dfs(i);
        }
    }
}
int main()
{
        // cout<<"Name : Manish Choudhary\nURN : 2203495\n\n";

    int ch, start, i, j;
    cout << "\nEnter the number of vertices in graph: ";
    cin >> n;
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    cout << "\nEnter the starting vertex: ";
    cin >> start;
    cout << "\n==>1. BFS: Print all nodes reachable from a given starting node";
    cout << "\n==>2. DFS: Print all nodes reachable from a given starting node";
    cout << "\n==>3:Exit";
    cout << "\nEnter your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nNodes reachable from starting vertex" << start << " are: ";
        bfs(start);
        for (i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
                cout << "\nThe vertex that is not reachable is " << i;
        }
        break;
    case 2:
        cout << "\nNodes reachable from starting vertex" << start << "are:\n";
        dfs(start);
        break;
    case 3:
        exit(0);
    default:
        cout << "\nPlease enter valid choice:";
    }
    cout << endl;
}
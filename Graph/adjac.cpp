#include <iostream>
using namespace std;

const int MAX_VERTICES = 50;
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES], front = -1, rear = -1;
int stack[MAX_VERTICES], top = -1;
int vertexCount = 0;

void bfs(int startVertex) {
    visited[startVertex] = 1;
    queue[++rear] = startVertex;
    while (front != rear) {
        int currentVertex = queue[++front];
        cout << currentVertex << " ";
        for (int i = 1; i <= vertexCount; ++i) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int startVertex) {
    visited[startVertex] = 1;
    stack[++top] = startVertex;
    cout << startVertex << " ";
    for (int i = 1; i <= vertexCount; ++i) {
        if (adjacencyMatrix[startVertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int choice, startVertex;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertexCount;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= vertexCount; ++i) {
        for (int j = 1; j <= vertexCount; ++j)
            cin >> adjacencyMatrix[i][j];
    }

    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "\n1. BFS: Print all nodes reachable from the starting node" << endl;
    cout << "2. DFS: Print all nodes reachable from the starting node" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nNodes reachable from starting vertex " << startVertex << " are: ";
            bfs(startVertex);
            for (int i = 1; i <= vertexCount; ++i) {
                if (!visited[i])
                    cout << "\nThe vertex that is not reachable is " << i;
            }
            break;
        case 2:
            cout << "\nNodes reachable from starting vertex " << startVertex << " are:" << endl;
            dfs(startVertex);
            break;
        case 3:
            exit(0);
        default:
            cout << "\nPlease enter a valid choice.";
    }

    return 0;
}

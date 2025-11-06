#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int graph[MAX][MAX], visited[MAX], queue[MAX];
    int n, links, from, to, start;
    int front = 0, rear = 0;

    cout << "Enter number of web pages: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) graph[i][j] = 0;
    }

    cout << "Enter number of hyperlinks: ";
    cin >> links;
    cout << "Enter links (from to):\n";
    for (int i = 0; i < links; i++) {
        cin >> from >> to;
        graph[from][to] = 1;
    }

    cout << "Enter start page: ";
    cin >> start;

    cout << "\nIndexing pages starting from: " << start << "\n";

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        cout << "Indexed page: " << curr << "\n";
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

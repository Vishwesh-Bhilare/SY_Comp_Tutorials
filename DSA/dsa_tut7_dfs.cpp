#include <iostream>
using namespace std;

const int MAX = 10;
int graph[MAX][MAX], visited[MAX];
int n;

void dfs(int page) {
    cout << "Indexed page: " << page << "\n";
    visited[page] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[page][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    int links, from, to, start;

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
    dfs(start);
}

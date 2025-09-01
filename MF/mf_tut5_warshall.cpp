#include <iostream>
using namespace std;

const int sized = 4;
const int INF = 100;
int dist[4][4] = {
    {0,   15,  6,   8},
    {INF, 0,   15,  1},
    {8,   INF, 0,   3},
    {INF, 2,   INF, 0}
};

void print_matrix(){
    int i = 0, j = 0;
    cout << endl;
    for (i = 0; i < sized; i++){
        for (j = 0; j < sized; j++){
            if (dist[i][j] >= INF) cout << "INF\t\t";
            else cout << dist[i][j] << "\t\t";
        }
        cout << endl;
    }
}

void warshall(){
    int i = 0, j = 0, k = 0;

    for (k = 0; k < sized; k++){
        cout << "\nConsidering k = " << k << ":\n";

        for (i = 0; i < sized; i++){
            for ( j = 0; j < sized; j++){
                if (i == k && j == k) continue;

                // if there's no path i->k or k->j, skip
                if (dist[i][k] >= INF || dist[k][j] >= INF) continue;

                int through = dist[i][k] + dist[k][j];
                if (through < dist[i][j]) {
                    cout << "dist[" << i << "][" << j << "] ";
                    if (dist[i][j] >= INF) cout << "(INF)";
                    else cout << "(" << dist[i][j] << ")";
                    cout << " > dist[" << i << "][" << k << "] + dist[" << k << "][" << j << "] ";
                    cout << "(" << dist[i][k] << "+" << dist[k][j] << ")"
                         << " => update to " << through << "\n";
                    dist[i][j] = through;
                }
            }
        }

        // show matrix after finishing this k
        print_matrix();
    }
}

int main(){
    print_matrix();

    cout << "---------------" << endl;

    warshall();

    cout << "---------------" << endl;

    print_matrix();

    return 0;
}

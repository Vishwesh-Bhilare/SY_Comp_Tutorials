#include<iostream>
using namespace std;

int main() {
    int hash_val, servers, requests, num_val = 0;
    string val;

    cout << "Enter number of servers: "; 
    cin >> servers;
    cout << "\nEnter number of incoming requests: "; 
    cin >> requests;

    string hash_servers[100][100];   // max 100 servers, 100 requests each
    int server_count[100] = {0};     // track how many requests each server got

    cout << "\nEnter request IDs:\n";

    for(int i = 0; i < requests; i++) {
        cout << "Request " << i+1 << ": "; 
        cin >> val;

        // take last octet
        int j = val.size() - 1;
        int k = 1;
        num_val = 0;

        while(val[j] != '.' && j >= 0) {
            num_val = num_val + (val[j] - '0') * k;
            k *= 10;
            j--;
        }
        hash_val = num_val % servers;   // division method

        // assign request
        hash_servers[hash_val][server_count[hash_val]] = val;
        server_count[hash_val]++;

        cout << "Request '" << val << "' is handled by Server " << hash_val << "\n";
    }

    cout << "\nServer Load Summary:\n";
    for (int i = 0; i < servers; i++) {
        cout << "Server " << i << " handled " << server_count[i] << " requests";
        if (server_count[i] > 0) {
            cout << ": ";
            for (int j = 0; j < server_count[i]; j++) {
                cout << hash_servers[i][j];
                if (j < server_count[i]-1) cout << ", ";
            }
        }
        cout << "\n";
    }

    return 0;
}

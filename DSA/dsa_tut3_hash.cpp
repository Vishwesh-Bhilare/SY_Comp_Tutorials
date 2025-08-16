#include<iostream>
using namespace std;

int main(){
	int hash_val, servers, requests, num_val = 0;
    string val;
	
	cout << "Enter the no. of servers: "; cin >> servers;
	cout << "\nEnter the no. of requests: "; cin >> requests;
	
	string hash_servers[servers];

    // set '0' to all hash_map table
    for (int i = 0; i < servers; i++){
        hash_servers[i] = "0";
    }
	
	cout << endl;
	
	for(int i = 0; i < requests; i++){
		cout << "\nEnter the IP add. " << i+1 <<": "; cin >> val;
		int j = val.size() - 1;
        int k = 1;
        num_val = 0;

        while(val[j] != '.'){
            num_val = num_val + (val[j] - '0')*k;	// - '0' because val[j] is char
            k *= 10;
            j--;
        }
        hash_val = num_val % servers;   // division method

		// linear probing for collion resolution
		int check = 0;
		while (hash_servers[hash_val] != "0"){
			hash_val = (hash_val + 1) % servers;
			
			check += 1;	// check for repetitions
			if (check >= servers){
				cout << "No free space!";
				return -1;
			}
		}
		hash_servers[hash_val] = val;
	}
	
	for (int i = 0; i < servers; i++){
        if (hash_servers[i] == "0"){
            cout << "\nServer " << i+1 << " is not handling any request";
            continue;
        }
		cout << "\nServer " << i+1 << " is handling " << hash_servers[i] << " request";
	}
	
	return 0;
}

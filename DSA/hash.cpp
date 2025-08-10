#include<iostream>
using namespace std;

int main(){
	int val, hash_val, servers, requests;
	
	cout << "Enter the no. of servers: "; cin >> servers;
	cout << "\nEnter the no. of requests: "; cin >> requests;
	
	int hash_servers[servers] = {};
	
	cout << endl;
	
	for(int i = 0; i < requests; i++){
		cout << "\nEnter the IP add. " << i+1 <<": "; cin >> val;
		hash_val = val % servers;	// division method
		
		// linear probing for collion resolution
		int check = 0;
		while (hash_servers[hash_val] != 0){
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
		cout << "\nServer " << i+1 << " is handling " << hash_servers[i] << " request";
	}
	
	return 0;
}

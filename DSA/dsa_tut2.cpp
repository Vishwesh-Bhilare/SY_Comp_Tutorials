#include <iostream>
using namespace std;

void bubble_sort(int scores[], int players){
	for (int i = 0; i < players-1; i++){
		for (int j = 0; j < players - 1 - i; j++){
			if (scores[j] > scores[j+1]){
				int temp = scores[j];
				scores[j] = scores[j+1];
				scores[j+1] = temp;
			}
		}
	}
}

void insertion_sort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int current = arr[i];
        int j = i - 1;

		// exchange if previous element > next element
        while (j >= 0 && arr[j] > current){
            arr[j + 1] = arr[j];
            j--;	// so while condition becomes false after one iteration
        }

        arr[j + 1] = current;
    }
}

int main(){
	int players;
	
	cout << "Enter the number of players: ";
	cin >> players;
	if (!(players)){
		cout<<"ERROR!\nInput only int!";
		return -1;
	}
	
	int scores[players];
	
	for (int i = 0; i < players; i++){
		cout << "Enter the score for player no. " << i+1 << ": ";
		cin >> scores[i];
	}
	
	int sort_choice;
	
	cout<<"1 - Bubble Sort\n2 - Insertion Sort\n";
	cin>>sort_choice;
	
	if (sort_choice == 1){
		bubble_sort(scores, players);
	}
	else if (sort_choice == 2){
		insertion_sort(scores, players);
	}
	
	cout<<"\nSorted scoreboard is: "<<endl;
	
	for (int i = 0; i < players; i++){
		cout<<scores[i]<<endl;
	}
	return 0;
}

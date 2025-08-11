#include <iostream>
using namespace std;

void display_hand(int arr[], int size) {
    cout << "Current hand: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
        display_hand(arr, i + 1); // Show current sorted hand after each step
    }
}

int main() {
    int cards;

    cout << "Enter the number of cards in your hand: ";
    cin >> cards;

    if (!cin || cards <= 0) {
        cout << "ERROR! Input only positive integers!" << endl;
        return -1;
    }

    int hand[cards];
    for (int i = 0; i < cards; i++) {
        cout << "Enter value of card " << i + 1 << ": ";
        cin >> hand[i];
    }

    insertion_sort(hand, cards);

    cout << "\nFinal sorted hand:\n";
    for (int i = 0; i < cards; i++) {
        cout << hand[i] << " ";
    }
    cout << endl;

    return 0;
}

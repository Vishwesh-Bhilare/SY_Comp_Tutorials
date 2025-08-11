#include <iostream>
using namespace std;

void bubble_sort(int scores[], int games) {
    for (int i = 0; i < games - 1; i++) {
        for (int j = 0; j < games - 1 - i; j++) {
            if (scores[j] > scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
                cout << "Leveling up!" << endl; // message after every swap
            }
        }
    }
}

int main() {
    int games;

    cout << "Enter the number of games played: ";
    cin >> games;

    if (!cin || games <= 0) {
        cout << "ERROR! Input only positive integers!" << endl;
        return -1;
    }

    int scores[games];
    for (int i = 0; i < games; i++) {
        cout << "Enter your score for game " << i + 1 << ": ";
        cin >> scores[i];
    }

    bubble_sort(scores, games);

    cout << "\nYour scores in ascending order:\n";
    for (int i = 0; i < games; i++) {
        cout << scores[i] << endl;
    }

    return 0;
}

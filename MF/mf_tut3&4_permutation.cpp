#include <iostream>
using namespace std;

// factorial
long long fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// nPr
long long nPr(int n, int r) {
    return fact(n) / fact(n - r);
}

int main() {
    int choice;
    cout << "Enter 1 for Assignment 1, 2 for Assignment 2: ";
    cin >> choice;

    if (choice == 1) {
        /*
            assignment 1:
            12 participants → arrange top 5
            first 3 are distinct medals (gold, silver, bronze)
            next 2 just certificates (order doesn't matter)
        */
        int n = 12;

        // choose 3 for medals
        long long medalWays = nPr(12, 3);

        // remaining 9, choose 2 for certificates
        long long certWays = (fact(9) / (fact(2) * fact(7)));

        long long totalWays = medalWays * certWays;

        cout << "Number of ways: " << totalWays << endl;

    } else if (choice == 2) {
        /*
            assignment 2:
            digits: {1,2,3,4,5,6}
        */
        int total = 6 * 5 * 4; // total 3-digit numbers
        int even = 0, lessThan400 = 0;
        
        /*
            total even: last digit must be even {2,4,6}
            choose last digit (3 ways), then 2 other from remaining 5 -> 5*4
        */
        even = 3 * 5 * 4;

        /*
            less than 400: first digit {1,2,3} (3 ways)
            then choose 2 more from remaining 5 → 5*4
        */
        lessThan400 = 3 * 5 * 4;

        cout << "Total 3-digit numbers: " << total << endl;
        cout << "Even numbers: " << even << endl;
        cout << "Numbers < 400: " << lessThan400 << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

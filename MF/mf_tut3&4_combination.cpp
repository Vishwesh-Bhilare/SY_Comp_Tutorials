#include <iostream>
using namespace std;

// n! / (r! * (n - r)!)
int combination(int n, int k) {
    int result = 1;
   
    for (int i = 0; i < k; i++) {
        result = result * (n - i);
        result = result / (i + 1);
    }

    return result;
}

// assignment 1
void assignment1() {
    int n = 20, k = 3;
    cout << "Number of ways to select 3 students from 20 for the debate competition: "
         << combination(n, k) << endl;
}

// assignment 2
void assignment2() {
    int women = 7, men = 5;
   
    // 3W, (2M + 4W), (1M + 5W), 0M
    int result = combination(women, 3) * combination(men, 2) +
                 combination(women, 4) * combination(men, 1) +
                 combination(women, 5) * combination(men, 0);
                 
    cout << "Number of ways to select a committee with at least 3 women: " << result << endl;
}

// assignment 3
void assignment3() {
    int women = 7, men = 9;
   
    // (1W, 4M) + (2W, 3M) + (3W, 2M) + (4W, 1M)
    int result = combination(women, 1) * combination(men, 4) +
                 combination(women, 2) * combination(men, 3) +
                 combination(women, 3) * combination(men, 2) +
                 combination(women, 4) * combination(men, 1);
   
    cout << "Number of ways to select a committee with at least 1 woman and 1 man: "
         << result << endl;
}

int main() {
    int choice;
   
   
   
    // respective question
    do{
cout << "\n\nChoose an assignment to solve (1, 2, or 3 | 4 to exit): ";
cin >> choice;

if (choice == 1) {
assignment1();
continue;
} else if (choice == 2) {
assignment2();
continue;
} else if (choice == 3) {
assignment3();
continue;
} else if (choice == 4) {
cout << "Exiting..";
break;
} else {
cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
}
} while (choice != 4);

    return 0;
}

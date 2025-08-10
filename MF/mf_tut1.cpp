#include <iostream>
#include <string>
using namespace std;

int universal[12] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

// input array
void input_array(int arr[], string group){
    cout << "\nEnter the roll numbers of students in " << group << " Club: " << endl;
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
}

// find intersection
void set_intersection(int set1[], int set2[]){
    int flag = 0;
    bool found = false;
    cout << "\n";
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(set1[i] == set2[j]){
                if(flag == 0){
                    cout << "Common students in both groups: ";
                }
                cout << set1[i] << " ";
                found = true;
                flag = 1;
            }
        }
    }
    if(!found){
        cout << "No common students found!";
    }
    cout << endl;
}

// students in neither group
void not_in_any_set(int unions[], int counter){
    bool copy_exists = false;
    cout << "\nStudents who are in neither group: ";
    
    for (int i = 0; i < 12; i++){
        copy_exists = false;
        for (int j = 0; j < counter; j++){
            if (universal[i] == unions[j]){
                copy_exists = true;
                break;
            }
        }
        if (!copy_exists){
            cout << " " << universal[i];
        }
    }
    cout << endl;
}

// union of sets
void set_union(int set1[], int set2[]){
    bool breakOutter = false;
    int counter = 0;
    int unions[10] = {};

    cout << "Students who are in either one group: ";
    
    // adding elements of set1 to union
    for(int i = 0; i < 5; i++){
        cout << " " << set1[i];
        unions[counter] = set1[i]; // add the element to union set
        counter++;
    }

    // adding elements of set2 to union
    for(int j = 0; j < 5; j++){
        breakOutter = false;
        for(int i = 0; i < 5; i++){
            if (set2[j] == set1[i]){
                breakOutter = true;
                break;
            }
        }
        if(breakOutter){
            continue;
        }
        else{
            cout << " " << set2[j];
            unions[counter] = set2[j]; // adding the element to union set
            counter++;
        }
    }
    
    not_in_any_set(unions, counter); // call to find complement of union
    cout << endl;
}

// symmetric difference
void symmetric_difference(int set1[], int set2[]){
    int symDiff[10]; // array to store symmetric difference
    int symDiffCounter = 0;

    // elements in set1 but not in set2
    for (int i = 0; i < 5; i++){
        bool found = false;
        for (int j = 0; j < 5; j++){
            if (set1[i] == set2[j]){
                found = true;
                break;
            }
        }
        if (!found){
            symDiff[symDiffCounter++] = set1[i];
        }
    }
    
    // elements in set2 but not in set1
    for (int i = 0; i < 5; i++){
        bool found = false;
        for (int j = 0; j < 5; j++){
            if (set2[i] == set1[j]){
                found = true;
                break;
            }
        }
        if (!found){
            symDiff[symDiffCounter++] = set2[i];
        }
    }

    cout << "\nSymmetric difference (students in either group but not both): ";
    if (symDiffCounter == 0) {
        cout << "No symmetric difference found!";
    } else {
        for (int i = 0; i < symDiffCounter; i++) {
            cout << symDiff[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int set1[5], set2[5];
    input_array(set1, "Science");
    input_array(set2, "Drama");

    set_intersection(set1, set2);  // display intersection
    set_union(set1, set2);  // display union
    symmetric_difference(set1, set2);  // display symmetric difference

    return 0;
}

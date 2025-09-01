#include <iostream>
#include <string>
using namespace std;

class ListNode {
public:
    string taskName;
    int priority;
    float exec_time;
    ListNode *next;
};

void sort_priority(ListNode* arr[], int n){
int i, j;
ListNode *key;
for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && (arr[j])->priority > key->priority) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sort_exec(ListNode* arr[], int n){
int i, j;
ListNode *key;
for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && (arr[j])->exec_time > key->exec_time) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
ListNode *head = nullptr;
ListNode *tail = nullptr;
ListNode *temp = nullptr;

int n;
cout << "Enter the number of tasks to be added: "; cin >> n;
ListNode* ptr_arr[n];

for (int i = 0; i < n; i++){
temp = new ListNode;

cout << "Enter task name: "; cin >> temp->taskName;
cin.ignore();
cout << "Enter task priority (1 - 10): "; cin >> temp->priority;
cout << "Enter task execution time (ms): "; cin >> temp->exec_time;

if (head == nullptr){
head = temp;
tail = temp;
} else{
tail->next = temp;
tail = temp;
}

ptr_arr[i] = temp;
cout << "\n------------\n";

}

sort_priority(ptr_arr, n);

cout << "Tasks according to Priority: "<< endl;
for (int i = 0; i < n; i++){
cout << (ptr_arr[i])->taskName << ": " << (ptr_arr[i])->priority << endl;
}

sort_exec(ptr_arr, n);

cout << "\nTasks according to Execution Time: "<< endl;
for (int i = 0; i < n; i++){
cout << (ptr_arr[i])->taskName << ": " << (ptr_arr[i])->exec_time << "ms" << endl;
}

return 0;
}

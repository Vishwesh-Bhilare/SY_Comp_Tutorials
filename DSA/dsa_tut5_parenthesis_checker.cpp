#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(char c) {
        if (topIndex < MAX - 1)
            arr[++topIndex] = c;
    }

    void pop() {
        if (topIndex >= 0)
            topIndex--;
    }

    bool empty() {
        return topIndex == -1;
    }

    char top() {
        return arr[topIndex];
    }
};

bool isBalanced(string exp) {
    Stack s;

    for (char ch : exp) {
        if (ch == '(' || ch == '[' || ch == '{')
            s.push(ch);

        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;

            char open = s.top();
            s.pop();

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
                return false;
        }
    }

    return s.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

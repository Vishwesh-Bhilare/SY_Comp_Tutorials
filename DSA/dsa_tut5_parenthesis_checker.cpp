#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        } 
        else if (ch == '}') {
            if (s.empty() || s.top() != '{') return false;
            s.pop();
        } 
        else if (ch == ']') {
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced expression" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}

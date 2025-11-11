#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[50];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(char x) { arr[++topIndex] = x; }
    void pop() { topIndex--; }
    char top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    string infix, postfix = "";
    cout << "Enter infix: ";
    cin >> infix;

    Stack s;

    for (char c : infix) {
        if (c >= 'A' && c <= 'Z') 
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } 
        else {
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;
}

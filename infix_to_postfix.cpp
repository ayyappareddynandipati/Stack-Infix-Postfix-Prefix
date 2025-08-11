#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letters
           (c >= 'a' && c <= 'z') ||  // Lowercase letters
           (c >= '0' && c <= '9');    // Digits
}

// Function to return priority of an operator
int priorityValue(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1; // For non-operators
}

// Function to convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st;    // Stack to store operators
    string result = ""; // Final postfix expression

    for (char c : s) {
        if (isOperand(c)) {
            // If operand, add to result
            result += c;
        }
        else if (c == '(') {
            // Push '(' to stack
            st.push(c);
        }
        else if (c == ')') {
            // Pop until '(' is found
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from stack
        }
        else {
            // For operators: pop operators from stack with higher or equal precedence
            while (!st.empty() && priorityValue(c) <= priorityValue(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators from stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string s = "a+b*c";
    cin >> s; // Read infix expression (no spaces)
    cout << infixToPostfix(s);
}

/*
Time Complexity:
- Iterates through N characters → O(N)
- Each operator pushed and popped at most once → O(N)
- Final stack emptying → O(N)
Overall: O(N)

Space Complexity:
- Stack may store up to O(N) operators
- Result string stores O(N) characters
Overall: O(N)

------------------------------
Sample Input 1:
a+b*c

Sample Output 1:
abc*+

Sample Input 2:
(a+b)*(c-d)

Sample Output 2:
ab+cd-*
------------------------------
*/

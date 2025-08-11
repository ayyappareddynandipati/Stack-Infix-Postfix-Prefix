#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letter
           (c >= 'a' && c <= 'z') ||  // Lowercase letter
           (c >= '0' && c <= '9');    // Digit
}

// Function to convert postfix expression to prefix
string postfixToPrefix(string s) {
    stack<string> st;

    // Traverse each character in postfix expression
    for (char c : s) {
        if (isOperand(c)) {
            // If operand, push it as a string
            st.push(string(1, c));
        }
        else {
            // If operator, pop two operands from stack
            string a = st.top(); st.pop(); // First operand
            string b = st.top(); st.pop(); // Second operand

            // Form new prefix expression: operator + operand1 + operand2
            string res = string(1, c) + b + a;

            // Push back to stack
            st.push(res);
        }
    }

    // The stack will have the final prefix expression
    return st.top();
}

int main() {
    string s;
    cin >> s; // Read postfix expression without spaces
    cout << postfixToPrefix(s);
}

/*
Time Complexity:
- Scans the string once: O(N)
- Stack push/pop operations: O(1) each
Overall: O(N)

Space Complexity:
- Stack stores at most O(N) strings
- Final prefix expression length O(N)
Overall: O(N)

------------------------------
Sample Input 1:
ab+c*

Sample Output 1:
*+abc

Sample Input 2:
abc*+de/-

Sample Output 2:
-+a*bc/de
------------------------------
*/

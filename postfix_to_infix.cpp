#include <bits/stdc++.h>
using namespace std;

// Function to check if the character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letters
           (c >= 'a' && c <= 'z') ||  // Lowercase letters
           (c >= '0' && c <= '9');    // Digits
}

// Function to convert a postfix expression to infix
string postfixToInfix(string s) {
    stack<string> st;

    // Traverse each character of the postfix expression
    for (char c : s) {
        if (isOperand(c)) {
            // If it's an operand, push it as a string
            st.push(string(1, c));
        } 
        else {
            // If it's an operator, pop two operands from stack
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();

            // Combine into a valid infix expression with parentheses
            string res = '(' + b + c + a + ')';

            // Push the new expression back to stack
            st.push(res);
        }
    }

    // The final element in the stack is the complete infix expression
    return st.top();
}

int main() {
    string s;
    cin >> s; // Read postfix expression without spaces
    cout << postfixToInfix(s);
}

/*
Time Complexity:
- Traverse input string once: O(N)
- Push and pop operations on stack: O(1) each
Overall: O(N)

Space Complexity:
- Stack holds at most O(N) strings
- Final string size is O(N)
Overall: O(N)

------------------------------
Sample Input 1:
ab+c*

Sample Output 1:
((a+b)*c)

Sample Input 2:
abc*+de/-

Sample Output 2:
((a+(b*c))-(d/e))
------------------------------
*/

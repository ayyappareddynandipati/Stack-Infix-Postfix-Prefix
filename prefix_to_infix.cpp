#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letter
           (c >= 'a' && c <= 'z') ||  // Lowercase letter
           (c >= '0' && c <= '9');    // Digit
}

// Function to convert a prefix expression to infix
string prefixToInfix(string s) {
    stack<string> st;

    // Traverse the prefix expression from right to left
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];

        if (isOperand(c)) {
            // If it's an operand, push it to the stack
            st.push(string(1, c));
        }
        else {
            // If it's an operator, pop two operands from the stack
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();

            // Form an infix expression with parentheses
            string res = '(' + a + c + b + ')';

            // Push the new expression back onto the stack
            st.push(res);
        }
    }

    // Final infix expression is at the top of the stack
    return st.top();
}

int main() {
    string s;
    cin >> s; // Read prefix expression without spaces
    cout << prefixToInfix(s);
}

/*
Time Complexity:
- Traverse string once → O(N)
- Push/pop from stack → O(1) each
Overall: O(N)

Space Complexity:
- Stack stores at most O(N) strings
- Final result length is O(N)
Overall: O(N)

------------------------------
Sample Input 1:
*+abc

Sample Output 1:
((a+b)*c)

Sample Input 2:
-+a*bc/de

Sample Output 2:
((a+(b*c))-(d/e))
------------------------------
*/

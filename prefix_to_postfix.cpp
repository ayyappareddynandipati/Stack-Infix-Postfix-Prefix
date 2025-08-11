#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letter
           (c >= 'a' && c <= 'z') ||  // Lowercase letter
           (c >= '0' && c <= '9');    // Digit
}

// Function to convert prefix expression to postfix
string prefixToPostfix(string s) {
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

            // Combine in postfix form: operand1 operand2 operator
            string res = a + b + c;

            // Push the result back onto the stack
            st.push(res);
        }
    }

    // The final postfix expression will be at the top of the stack
    return st.top();
}

int main() {
    string s;
    cin >> s; // Read prefix expression without spaces
    cout << prefixToPostfix(s);
}

/*
Time Complexity:
- Scan input once → O(N)
- Push/pop operations → O(1) each
Overall: O(N)

Space Complexity:
- Stack can hold up to O(N) strings
- Final postfix expression length O(N)
Overall: O(N)

------------------------------
Sample Input 1:
*+abc

Sample Output 1:
ab+c*

Sample Input 2:
-+a*bc/de

Sample Output 2:
abc*+de/-
------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Check if character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Uppercase letters
           (c >= 'a' && c <= 'z') ||  // Lowercase letters
           (c >= '0' && c <= '9');    // Digits
}

// Return precedence of operators
int priorityValue(char c) {
    if (c == '^') return 3;              // Highest precedence
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;                      // Not an operator
}

// Convert infix to postfix (modified for prefix conversion step)
string infixTopPrefix(string s) {
    string res = "";
    stack<char> st;

    for (char c : s) {
        if (isOperand(c)) {
            // If operand, add to result
            res += c;
        }
        else if (c == '(') {
            // Push '(' to stack
            st.push(c);
        }
        else if (c == ')') {
            // Pop until '(' is found
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        else {
            // Handle right-associative '^' differently
            if (c == '^') {
                while (!st.empty() && priorityValue(c) <= priorityValue(st.top())) {
                    res += st.top();
                    st.pop();
                }
            }
            else {
                while (!st.empty() && priorityValue(c) < priorityValue(st.top())) {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

// Convert infix expression to prefix
string convertToPrefix(string s) {
    // Step 1: Reverse the infix string
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Step 3: Convert reversed expression to postfix
    string res = infixTopPrefix(s);

    // Step 4: Reverse postfix result to get prefix
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string s;
    cin >> s; // Read infix expression without spaces
    cout << convertToPrefix(s);
}

/*
Time Complexity:
- Reversing input: O(N)
- Converting to postfix: O(N)
- Reversing result: O(N)
Overall: O(N)

Space Complexity:
- Stack for operators: O(N)
- Result string: O(N)
Overall: O(N)

------------------------------
Sample Input 1:
(a-b/c)*(a/k-l)

Sample Output 1:
*-a/bc-/akl

Sample Input 2:
x+y*z/w+u

Sample Output 2:
++x/*yzwu
------------------------------
*/

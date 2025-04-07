#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Check if uppercase letter
           (c >= 'a' && c <= 'z') ||  // Check if lowercase letter
           (c >= '0' && c <= '9');    // Check if digit
}

string postfixToInfix(string s){
	stack<string>st;
	for(char c : s){
		if(isOperand(c)){
			st.push(string(
			    1,c));
		}else{
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			string res = '(' + b + c + a + ')';
			st.push(res);
		}
	}
	return st.top();
}
int main(){
	string s;
	cin>>s;
	cout<<postfixToInfix(s);
}

//    Time Complexity (TC):   
// - You  iterate through the string  once →   ( O(N)  )   
// -  For each operand (isOperand(c))  → Push onto the stack  (O(1))   
// -  For each operator (`+`, `-`, `*`, etc.) :  
//   - Pop  two  elements  (O(1))   
//   - Construct a new infix string →  O(1) amortized  (string concatenation in C++ is optimized).  
//   - Push back onto the stack  (O(1))   

//  Overall Time Complexity:  ( O(N)  )   

//    Space Complexity (SC):   
// -  Stack stores at most O(N) substrings  in the worst case.  
// -  Each operand contributes O(1) space initially .  
// -  Each operator combines two strings into one , leading to  O(N) space in the worst case .  

//   Overall Space Complexity:  ( O(N)  )   

//    Final Complexity Summary:   
// -  Time Complexity:   ( O(N)  )  
// -  Space Complexity:   ( O(N)  )  

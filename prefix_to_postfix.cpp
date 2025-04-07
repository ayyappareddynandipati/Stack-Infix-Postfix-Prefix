#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Check if uppercase letter
           (c >= 'a' && c <= 'z') ||  // Check if lowercase letter
           (c >= '0' && c <= '9');    // Check if digit
}

string prefixToPostfix(string s){
	stack<string>st;
	for(int i=s.size()-1;i>=0;i--){
		char c = s[i];
		if(isOperand(c)){
			st.push(string(1,c));
		}else{
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			string res = a + b + c;
			st.push(res);
		}
	}
	return st.top();
}
int main(){
	string s;
	cin>>s;
	cout<<prefixToPostfix(s);
}

//    Time Complexity (TC) 
// -  You iterate through the string once →  ( O(N)  ) 
// -  Each operand is pushed once →  ( O(1)  ) 
// -  Each operator pops two elements and pushes one →  ( O(1)  ) 

//  Overall Time Complexity:  ( O(N)  )   

//    Space Complexity (SC) 
// -  Stack stores at most O(N) substrings in the worst case .
// -  Each operand contributes O(1) space initially .
// -  Each operator combines two strings into one, leading to O(N) space in the worst case .

//  Overall Space Complexity:  ( O(N)  )   

//    Final Complexity Summary 
// -   Time Complexity:  ( O(N)  )   
// -   Space Complexity:  ( O(N)  )   
#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||  // Check if uppercase letter
           (c >= 'a' && c <= 'z') ||  // Check if lowercase letter
           (c >= '0' && c <= '9');    // Check if digit
}
int priorityValue(char c){
	if(c=='^') return 3;
	else if(c=='*' || c=='/') return 2;
	else if(c=='+' || c=='-') return 1;
	else return -1;
}

string infixToPostfix(string s){
	stack<char>st;
	string result="";
	for(char c : s){
		if(isOperand(c)){
			result+=c;
		}else if(c=='('){
			st.push(c);
		}else if(c==')'){
			while(!st.empty() && st.top()!='('){
				result+=st.top();
				st.pop();
			}
			st.pop();
		}else{
			while(!st.empty() && priorityValue(c) <= priorityValue(st.top())){
				result+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty()){
			result+=st.top();
			st.pop();
	}
	return result;
}

int main(){
	string s;
	cin>>s;
	cout<<infixToPostfix(s);
}


//    Time Complexity (TC):   
// 1.  Iterating through the string:   ( O(N)  )  
// 2.  Stack operations (push/pop for operators):  Each operator is pushed once and popped once →  ( O(N)  )  
// 3.  Final stack emptying:   ( O(N)  ) in the worst case  

//Overall Time Complexity:  ( O(N)  )   

//    Space Complexity (SC):   
// 1.  Stack usage:  In the worst case (fully parenthesized expressions like `((a+b)*(c-d))`), the stack holds  O(N)  elements.  
// 2.  Result string storage:   ( O(N)  ) (since it stores the postfix expression).  

//Overall Space Complexity:  ( O(N)  )   
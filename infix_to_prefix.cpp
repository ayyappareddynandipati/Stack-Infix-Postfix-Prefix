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

string infixTopPrefix(string s){

	string res = "";
	stack<char> st;
	for(char c : s){
		if(isOperand(c)){
			res+=c;
		}else if(c=='('){
			st.push(c);
		}else if(c==')'){
			while(!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			if(c=='^'){
				while(!st.empty() && priorityValue(c) <= priorityValue(st.top())){
					res+=st.top();
					st.pop();
				}
			}
			else{
				while(!st.empty() && priorityValue(c) < priorityValue(st.top())){
					res+=st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}

string convertToPrefix(string s){
	reverse(s.begin(),s.end());

	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			s[i]=')';
			i++;
		}
		else if(s[i] == ')'){
			s[i]='(';
			i++;
		}
	}
	string res = infixTopPrefix(s);

	reverse(res.begin(),res.end());

	return res;
}
int main(){
	string s;
	cin>>s;
	cout<<convertToPrefix(s);
}

// Your code converts an infix expression to a prefix expression using the stack-based approach. Here’s a quick analysis of its  time complexity (TC) and space complexity (SC):   

//   Time Complexity (TC):   
// -  Reversing the string:   ( O(N)  )
// -  Processing the expression using `infixTopPrefix()` (infix to postfix conversion):   ( O(N)  )  
// -  Reversing the result:   ( O(N)  )  
// -  Overall complexity:    ( O(N) + O(N) + O(N) = O(N)  )   

//   Space Complexity (SC):   
// - The function `infixTopPrefix()` uses a  stack  to store operators, which in the worst case (for an expression like `"((((a+b)*c)-d)/e)"`) would have   ( O(N)  )  extra space.  
// - The  result string  `res` also takes up   ( O(N)  )  space.  
// - Overall, the auxiliary space used is   ( O(N)  )  in the worst case.  

//   Final Complexity:   
// -  Time Complexity:  ( O(N) )  
// -  Space Complexity:  ( O(N) )  

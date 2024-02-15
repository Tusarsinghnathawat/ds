#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char s){
    if(s=='+'|| s=='-' ||s=='*'|| s=='/'){
        return 1;
    }
    else return 0;
}

string postfixToInfix(string s) {
    stack<string> st;

    for (int i=0; i<s.size(); i++){
        if (!isOperator(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string newExpression = "(" + op1 + s[i] + op2 + ")";
            st.push(newExpression);
        }
    }

    return st.top();
}

string postfixToPrefix(string s) {
    stack<string> st;

    for (int i=0; i<s.size(); i++) {
        if (!isOperator(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string newExpression = s[i] + op1 + op2;
            st.push(newExpression);
        }
    }

    return st.top();
}

int main() {
    string postfixExpression;
    
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);
    string prefixExpression = postfixToPrefix(postfixExpression);

    cout<<"Infix expression: "<<infixExpression<<endl;
    cout<<"Prefix expression: "<<prefixExpression<<endl;
}

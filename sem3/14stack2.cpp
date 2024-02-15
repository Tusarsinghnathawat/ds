#include<bits/stdc++.h>
#include<stack>
using namespace std;
int pre(char c){
    int p;
    if(c=='^') p=3;
    else if(c=='*' || c=='/') p=2;
    else if(c=='+' || c=='-') p=1;
    else p=-1;
    return p;
}

string infix_to_postfix(string s){
    stack<char> st;
    string res="";
    for(int i=0;i<s.size();i++){
        if((s[i]>=97 && s[i]<=122) || (s[i]>'0' && s[i]<='9' )){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(' ){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
            
        }
        else{
            while( !st.empty() && ( pre(st.top()) > pre(s[i]) ) ){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        
    }
    while(!st.empty()){
            res+=st.top();
            st.pop();
        }
    return res;
    
}
// TC: O(n)

bool isOperator(char s){
    if(s=='+'|| s=='-' ||s=='*'|| s=='/'){
        return 1;
    }
    else return 0;
}

int evaluate(string s){
    stack<int> st;
    int op1;
    int op2;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else if(isOperator(s[i])){
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            if(s[i]=='+'){
                st.push(op1+op2);
            }
            else if(s[i]=='-'){
                st.push(op1-op2);
            }
            else if(s[i]=='*'){
                st.push(op1*op2);
            }
            else if(s[i]=='/'){
                st.push(op1/op2);
            }
        }
    }
    return st.top();
}
// TC: O(n)

int main(){
    string stri;
    cout<<"enter infix input : ";
    cin>>stri;
    string post=infix_to_postfix(stri);
    cout<<post<<endl;
    cout<<"evaluation of postfix = ";
    int ans=evaluate(post);
    cout<<ans;
}
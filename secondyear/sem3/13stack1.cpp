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

bool wellParenthesized(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
           if(st.empty() || st.top()!='('){
            return false;
           }
            st.pop();
        }
    }
    return st.empty();
}
// TC: O(n)

void infix_to_prefix(string s){
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    stack<char> st;
    string res="";
    for(int i=0;i<s.size();i++){
        if((s[i]>=97 && s[i]<=122) || (s[i]>='0' && s[i]<='9')){
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
    reverse(res.begin(),res.end());
    cout<<res; 
}
// TC: O(n)
int main(){
    string stri;

    cout<<"enter input : ";
    cin>>stri;
    
    infix_to_prefix(stri);
    cout<<endl;
    cout<<wellParenthesized(stri);

}
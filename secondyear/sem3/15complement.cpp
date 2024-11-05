#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class binary{
    private:
    node* head;
    node* tail;
    public:
    binary(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        node* p=new node(val);
        if(head==NULL) {
            head=tail=p;
        }
        else{
           p->prev=tail;
           tail->next=p;
           tail=p;
        }
        
        
    }
    // tc: O(1)
    void display(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
    }
    // tc: O(n)
    void one(){
        node*curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                curr->data=1;
            }
            else{
                curr->data=0;
            }
            
            curr=curr->next;
        }
    }
    // tc: O(n)
    void two(){
        one();
        int carry=1;
        node* curr=head;
        while(curr!=NULL && carry==1){
            int sum=curr->data+carry;
            curr->data=sum%2;
            carry=sum/2;
            curr=curr->next;
        }
        if(carry==1){
            insert(carry);
        }
    }
    // tc: O(n)
};
int main(){
    binary obj;
    obj.insert(1);
    obj.insert(0);
    obj.insert(1);
    obj.insert(0);
    obj.display();
    cout<<endl;
    cout<<"once's compliment = ";
    obj.one();
    obj.display();
    cout<<endl;
    cout<<"two's compliment = ";
    obj.two();
    obj.display();
}
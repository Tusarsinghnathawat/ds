#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int PRN;
    string name;
    node* next;
    node(int PRN1,string n ){
        PRN = PRN1;
        name = n;
        next = NULL;
    }
};
class pinncal_club{
    private:
    node* pre;
    node* sec;
    public:
    pinncal_club(){
        pre=NULL;
        sec=NULL;
    }
    void insert(int PRN,string name){
        node* p =new node(PRN,name);
        if(pre==NULL){
            pre=p;
            sec=p;
        }
        else{
            sec->next=p;
            sec=p;
        }
    }
    // TC: O(1)

    void display(){
        node* temp=pre;
        while(temp!=NULL){
            cout<<temp->PRN<<" "<<temp->name<<" "<<endl;
            temp=temp->next;
        }
    }
    // TC: O(n)
    void del(int PRN){
        node* curr=pre;
        node* prev=NULL;
        while(curr!=NULL && curr->PRN!=PRN){
            prev=curr;
            curr=curr->next;
        }
        if(curr!=NULL){
            if(prev!=NULL){
                prev->next=curr->next;
            }
            else{
                pre=curr->next;
            }
            delete curr;
        }
    }
    // TC: O(n)
    int total(){
        int count=0;
        node* curr=pre;
        while(curr!=NULL){
            
            count++;
            curr=curr->next;
            
        }
        return count;
    }
    // TC: O(n)

};
int main(){
   pinncal_club obj;
    int n,prn;
    string name;
    cout<<"enter no of element :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter prn :";
        cin>>prn;
        cout<<"enter name :";
        cin>>name;
        obj.insert(prn,name);
    }
    
    cout<<"enter which element you want to delete :";
    int d;
    cin>>d;

    cout<<"before "<<endl;
    obj.display();
    cout<<endl;

    obj.del(d);

    cout<<"after "<<endl;
    obj.display();

    int tot=obj.total();
    cout<<tot;
}
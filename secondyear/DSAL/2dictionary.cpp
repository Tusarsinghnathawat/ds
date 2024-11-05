#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string word;
    string meaning;
    Node* next;
    Node(){
        word="";
        meaning="";
        next=NULL;
    }

    Node(string s, string m){
        word=s;
        meaning=m;
        next=NULL;
    }
};

class Hashing: public Node{
    public:
    Node* table[10];
    Hashing(){
        for(int i=0; i<10; i++){
            table[i]=NULL;
        }
    }

    int HashFn(string word){
        int hash=0;

        for(char ch: word){
            hash += int(ch);
        }
        return hash%10;
    }

    void insertWord(string word, string meaning){
        int index=HashFn(word);
        if(table[index]==NULL){
            table[index]=new Node(word, meaning);
        }
        else{
            Node* temp=table[index];
            table[index]=new Node(word, meaning);
            table[index]->next=temp;
        }
    }

    bool searchWord(string word){
        int index=HashFn(word);
        Node* temp=table[index];

        while(temp->word!=word && temp!=NULL){
            temp=temp->next;
        }
        if(temp!=NULL) return 1;
        return 0;
    }

    void Display(){
        for(int i=0; i<10; ++i){
            cout<<"["<<i<<"]: ";
    
            Node* temp=table[i];

            if(temp==NULL){
                cout<<endl;
            }

            while(temp!=NULL){
                cout<<temp->word<<": "<<temp->meaning<<endl;
                temp=temp->next;
            }
        }
    }
};

int main(){
    Hashing HashT;
    
    ifstream infile("Text.txt");
    string word, meaning;
    
    while(infile>>word>>meaning){
        HashT.insertWord(word, meaning);
    }

    HashT.Display();

    if(HashT.searchWord("forest")){
        cout<<"word is PRESENT"<<endl;
    }
    else{
        cout<<"word is ABSENT"<<endl;
    }
}

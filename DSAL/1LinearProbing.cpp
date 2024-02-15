#include <bits/stdc++.h>
using namespace std;

struct rec{
    int RollNo;
    string name;
};

class Hashing{

    rec Hashtable[10];

    public:

    Hashing(){
        for(int i=0; i<10; i++) Hashtable[i].RollNo=-1;
    }

    void insert(int roll,  const string& na){
        int index=roll%10;
        if(Hashtable[index].RollNo==-1){
            Hashtable[index]={roll, na};
        }
        else{
            int ele=index+1;
            while(ele!=index && Hashtable[ele].RollNo!=-1){
                ele=(ele+1)%10;
            }
            if(ele==index) cout<<"Hash Table is Full";
            else Hashtable[ele]={roll, na};
        }
    }

    int Search(int roll){
        int index=roll%10;
        if(Hashtable[index].RollNo==roll){
            return 1;
        }
        int ele=index+1;
        while(ele!=index && Hashtable[ele].RollNo!=roll){
            ele=(ele+1)%10;
        }
        if(ele==index) return 1;
        else return 0;
        return 0;
    }

    void del(int roll){
        int index=roll%10;
        if(Hashtable[index].RollNo==roll){
            Hashtable[index].RollNo=-2;
            Hashtable[index].name="";
        }
        int ele=index+1;
        while(ele!=index && Hashtable[ele].RollNo!=roll){
            ele=(ele+1)%10;
        }
        if(ele==index) cout<<"Element is ABSENT";
        else{
            Hashtable[index].RollNo=-2;
            Hashtable[index].name="";
        }
    }

    void display(){
        for(int i=0; i<10; i++){
            cout<<Hashtable[i].RollNo<<": "<<Hashtable[i].name<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Hashing Htable;

    string na;
    int ro;
    cout<<"1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\n";
    int choice;

    do{
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"How many elements to insert: ";
            int y;
            cin>>y;
            cout<<"Enter RollNo and Name to insert: "<<endl;
            while(y--){
            cin>>ro;
            cin>>na;
            Htable.insert(ro, na);
            }
            break;
        case 2:
            cout<<"Enter RollNo to be searched: ";
            cin>>ro;
            if(Htable.Search(ro)){
                cout<<"Roll No. "<<ro<<" is PRESENT"<<endl;
            }
            else{
                cout<<"Roll No. "<<ro<<" is ABSENT"<<endl;
            }
            break;
        case 3:
            cout<<"Enter RollNo to delete";
            cin>>ro;
            Htable.del(ro);
            break;
        case 4:
            Htable.display();
            break;
        case 0:
            cout<<"Exiting program..."<<endl;
            break;
        default:
            cout<<"Invalid choice. Try again!"<<endl;
            break;
    }
    } while(choice!=0);
}

// Input
// 9 Ankit
// 11 Aryan
// 62 Tushar
// 21 Div
// 19 Deep
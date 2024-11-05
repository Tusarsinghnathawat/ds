#include <iostream>
#include <vector>
using namespace std;

class CircularQue{
    int front;
    int rear;
    int size;
    vector<int>arr;
    public:
    CircularQue(int n){
        size=n;
        vector<int>arr(n,0);
        front=rear=-1;
    }

    bool isEmpty(){
        if(front==-1){
            return 1;
        }
        return 0;
    }
    bool isFull(){
        if( (front==0 && rear==size-1) || (front-1)%(size-1)==rear ){
            return 1;
        }
        return 0;
    }

    void insert(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            arr.insert(arr.begin()+ rear , val);
        }
        else if(front!=0 && rear==size-1){
            rear=0;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }

    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }

        arr[front]=-1;
        arr.erase(arr.begin() + front);
         
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    CircularQue obj(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(1);
    obj.insert(2);

    obj.display();

    obj.pop();

    obj.display();

    obj.insert(89);

    obj.display();
}
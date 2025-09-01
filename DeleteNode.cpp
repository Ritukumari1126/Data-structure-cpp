#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    //Node* tail;
    int size = 0;
    int s = 1;
    LinkedList(){
        head  = NULL;
        size = 0;

    }

    void insertAtEnd(int val){
        Node* temp = new Node(val);
        Node* mover = head;

        if(size == 0) head  = temp;
        else{
        while(mover->next!= NULL){
            mover = mover->next;
        }

        mover->next = temp;
    }
        size++;
    }

    void deleteHead(){
        head = head->next;
        size--;
    }

    void deleteTail(){
        Node* mover = head;
        while(mover->next->next != NULL){
            mover = mover->next;
        }
        mover->next = NULL;
        size--;
    }

    void deleteAtPos(int idx){
        if(size == 0) cout<<"List is empty"<<endl;
        else if(idx<0 || idx>size){
            cout<<"Invalid position"<<endl;
        }

        else if(idx == 0) deleteHead();
        else if(idx == (size-1)){
            deleteTail();
        }

        else{
            Node* mover = head;
            while(s<idx){
                mover = mover->next;
                s++;
            }
            mover->next = mover->next->next;
            size--;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    cout<<ll.size<<endl;
    ll.deleteAtPos(1);
    ll.display();
    cout<<ll.size;
}

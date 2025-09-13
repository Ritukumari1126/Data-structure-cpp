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
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void insertAtAnyPos(int pos , int val){
        if(pos<0 || pos>size){
            cout<<"invalid position : "<<endl;
        }
        else if(size == 0) cout<<"list is empty : "<<endl;
        else if(pos == 0) insertAtHead(val);
        else if(pos == (size-1)){
            insertAtEnd(val);
        }

        else{
            Node* temp = new Node(val);
            Node* mover = head;
            for(int idx = 1; idx<pos;idx++){
                mover = mover->next;
            }

            temp->next = mover->next;
            mover->next = temp;

        }
        size++;
    }

    void DeleteHead(){
        head = head->next;
    }

    void DeleteTail(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        tail = temp;
    }

    void DeleteAnyPos(int pos){
        if(pos<0 || pos>size) cout<<"Invalid position !!"<<endl;
        else if(size == 0) cout<<" list is empty .."<<endl;
        else if(pos == 0 ) DeleteHead();
        else if(pos == size-1) DeleteTail();
        else{
            Node* temp = head;
            for(int idx = 1;idx<pos;idx++){
                temp = temp->next;
            }

            temp->next = temp->next->next;
            
        }

        size--;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.display();

    ll.insertAtAnyPos(2,100);
    ll.insertAtAnyPos(3,200);
    ll.display();
    cout<<ll.size<<endl;

    ll.DeleteHead();
    ll.display();

    ll.DeleteAnyPos(3);
    ll.DeleteAnyPos(4);
    ll.display();
    cout<<ll.size<<endl;
}


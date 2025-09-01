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
    int s = 0;

    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd( int val){
        Node* temp = new Node(val);

        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
            
        }
        size++;
    }

    void getElement(int pos){
        Node* temp = head;
        while(s<pos){
            temp = temp->next;
            s++;
        }
        cout<<temp->val;

    }

};

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.getElement(3);

}
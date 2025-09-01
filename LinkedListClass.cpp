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

    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;

    }

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size == 0 ) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void InsertAtPos(int pos , int val){

        if(pos<0 || pos>size){
            cout<<"invalid position";
            
        }

        else if(pos == 0){
            insertAtHead(val);
        }
        else if(pos == size){
            insertAtEnd(val);
        }
        else{
          Node* temp = new Node(val);
          Node* mover = head;
          while(s < (pos-1)){
              mover = mover->next;
              s++;
           
            }

           temp->next = mover->next;
           mover->next = temp;
           size++;
       }
        
            
    
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    // LinkedList* ll = new LinkedList();
    LinkedList ll;
    /*ll->insertAtEnd(10);
    ll->insertAtEnd(20);
    ll->display();*/

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtHead(1);
    ll.insertAtHead(0);
    ll.InsertAtPos(2,40);
    ll.InsertAtPos(0,100);
    ll.display();
    cout<<ll.size;
}
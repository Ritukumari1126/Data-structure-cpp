#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLL{
    public:
    
    Node* head;
    Node* tail;
    int size;

    DoubleLL(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
        Node* temp = new Node(val);

        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        size++;
    }

    void inserAtHead(int val) {
        Node* temp = new Node(val);

        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++; 

    }

    void insertAtPos(int val,int pos){
        if(pos<0 || pos>size) {
            cout<<"invalid position.. "<<endl;
        }
        else if(pos == 0) inserAtHead(val);
        else if(pos == size) insertAtTail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i = 1;i<=pos-1;i++){
                temp = temp->next;
            }

            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;
        }

        size++;
        
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void DeleteHead(){
        if(size == 0) return;
        else{
            head = head->next;
            if(head) head->prev = NULL;
            if(head == NULL) tail = NULL;
        }
        size--;

    }

    void DeleteTail(){
        if(size == 0){
            cout<<"List is empty .. !!";
            return;
        }
        else if(size == 1){
            DeleteHead();
            return;
        }
        else{
            Node* temp = tail->prev;
            temp->next = NULL;
            tail = temp;
        }
        size--;
    }

    void DeleteAtPos(int pos){
        if(size == 0){
            cout<<"list is empty..";
            return;
        }
        if(pos<0 || pos>size){
            cout<<"invalid pos.. "<<endl;
            return;
        }

        else if(pos == 0) DeleteHead();
        else if(pos == size-1) DeleteTail();
        else{
            Node* temp = head;
            for(int i = 1; i<pos;i++){
                temp = temp->next;
            }
            Node* temp2 = temp->next->next;
            temp->next = temp2;
            temp2->prev = temp;

        }
        size--;

    }

    int getNodeAt(int pos){
        if(pos<0 || pos>size){
            cout<<" Invalid position... "<<endl;
            return -1;
        }

        else if(pos == size-1) return tail->val;
        else if(pos == 0) return head->val;
        else{
            Node* temp = head;
            for(int i = 1;i<=pos;i++){
                temp = temp->next;
                
            }
            return temp->val;
            
        }
        
    }

};

int main(){
    DoubleLL DLL;
    DLL.insertAtTail(10);
    DLL.insertAtTail(20);
    DLL.insertAtTail(30);
    DLL.insertAtTail(40);

    cout<<DLL.getNodeAt(3)<<endl;;
    DLL.display();
    cout<<DLL.size<<endl;
    DLL.DeleteAtPos(2);
    DLL.display();
    DLL.DeleteHead();
    DLL.display();
    cout<<DLL.size<<endl;
    DLL.DeleteTail();
    DLL.display();
}
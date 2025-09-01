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

int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    cout<<a.val<<" ";
    
    cout<<a.next->val<<" ";
    cout<<a.next->next->val<<" ";
    cout<<a.next->next->next->val<<" ";
    cout<<a.next->next->next->next<<" ";
    cout<<endl;

    
    cout<<"address of b "<<a.next<<endl;
    cout<<"address of c "<<b.next;
   

}


#include<iostream>
using namespace std;
#include<stack>

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    
};
#include<iostream>
using namespace std;
#include<vector>

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node* ConvertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;

}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}



int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = ConvertArr2LL(arr);
    display(head);
}
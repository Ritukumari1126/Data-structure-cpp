#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning
void addAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to add a node at the end
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to add a node after a given node
void addAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node after a given node
void deleteAfterNode(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("There is no node to delete\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Adding nodes
    addAtBeginning(&head, 10);
    addAtBeginning(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);
    addAfterNode(head->next, 25);  // Add after second node (20)

    printf("Doubly Linked List: ");
    displayList(head);

    // Deleting nodes
    deleteFromBeginning(&head);
    printf("After deleting from beginning: ");
    displayList(head);

    deleteFromEnd(&head);
    printf("After deleting from end: ");
    displayList(head);

    deleteAfterNode(head);
    printf("After deleting after the first node: ");
    displayList(head);

    return 0;
}

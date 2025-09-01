#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to insert a node at the beginning of the circular linked list
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    if ((*head)->next == *head) {  // Only one node in the list
        *head = NULL;
        free(temp);
        return;
    }

    while (last->next != *head) {
        last = last->next;
    }

    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

// Function to delete a node from the end of the circular linked list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if ((*head)->next == *head) {  // Only one node in the list
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Function to insert a node after a specified node
void insertAfter(struct Node** head, int afterData, int data) {
    struct Node* temp = *head;
    do {
        if (temp->data == afterData) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Node with data %d not found.\n", afterData);
}

// Function to insert a node before a specified node
void insertBefore(struct Node** head, int beforeData, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == beforeData) {
        insertBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    do {
        if (temp->data == beforeData) {
            struct Node* newNode = createNode(data);
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    printf("Node with data %d not found.\n", beforeData);
}

// Function to delete a node after a specified node
void deleteAfter(struct Node** head, int afterData) {
    struct Node* temp = *head;
    do {
        if (temp->data == afterData) {
            struct Node* delNode = temp->next;
            if (delNode == *head) { // If the node to delete is the head itself
                deleteBeginning(head);
                return;
            }
            temp->next = delNode->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Node with data %d not found.\n", afterData);
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    printf("Original List:\n");
    displayList(head);

    // Insert a node at the beginning
    insertBeginning(&head, 5);
    printf("After inserting 5 at the beginning:\n");
    displayList(head);

    // Insert a node after a specified node
    insertAfter(&head, 20, 25);
    printf("After inserting 25 after 20:\n");
    displayList(head);

    // Insert a node before a specified node
    insertBefore(&head, 30, 27);
    printf("After inserting 27 before 30:\n");
    displayList(head);

    // Delete a node from the beginning
    deleteBeginning(&head);
    printf("After deleting from the beginning:\n");
    displayList(head);

    // Delete a node from the end
    deleteEnd(&head);
    printf("After deleting from the end:\n");
    displayList(head);

    // Delete a node after a specified node
    deleteAfter(&head, 20);
    printf("After deleting the node after 20:\n");
    displayList(head);

    return 0;
}

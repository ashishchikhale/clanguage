#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
void insert_at_beginning(struct Node** head, int value) {
    struct Node* new_node = create_node(value);
    new_node->next = *head; // Point new node to current head
    *head = new_node; // Update head to new node
}

// Function to insert a node at the end
void insert_at_end(struct Node** head, int value) {
    struct Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node; // If list is empty, new node becomes the head
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = new_node; // Link the last node to the new node
}

// Function to delete a node by value
void delete_node(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Move head to the next node
        free(temp); // Free the old head node
        printf("Node with value %d deleted.\n", value);
        return;
    }
    
    // Search for the node to be deleted
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    // If node not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    
    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Node with value %d deleted.\n", value);
}

// Function to traverse the linked list and print the elements
void traverse_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL; // Initialize an empty list
    
    // Insert elements at the beginning
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    
    // Insert element at the end
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    
    // Traverse and display the list
    traverse_list(head);
    
    // Delete a node with value 20
    delete_node(&head, 20);
    
    // Traverse and display the list again
    traverse_list(head);
    
    // Delete a node that does not exist
    delete_node(&head, 100);
    
    // Delete the head node
    delete_node(&head, 30);
    
    // Traverse and display the list after deletion
    traverse_list(head);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtPos(struct Node** head, int pos, int data) {
    struct Node* newNode = createNode(data);
    struct Node* curr = *head;
    int i = 1;
    if (pos == 1) 
    {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        printf("Node inserted\n");
        return;
    }
    while (i < pos-1 && curr != NULL) 
    {

        curr = curr->next;
        i++;
    }

    if (curr == NULL) 
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->prev = curr;
    newNode->next = curr->next;

    if (curr->next != NULL) 
    {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    printf("Node inserted\n");
}
void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    int i = 1;

    if (pos == 1) 
    {
        *head = curr->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(curr);
        printf("Node deleted\n");
        return;
    }

    while (i < pos && curr != NULL) 
    {
        curr = curr->next;
        i++;
    }

    if (curr == NULL) 
    {
        printf("Invalid position.\n");
        return;
    }

    curr->prev->next = curr->next;

    if (curr->next != NULL) 
    {
        curr->next->prev = curr->prev;
    }

    free(curr);
    printf("Node deleted\n");
}
void traverse(struct Node* head) {
    struct Node* curr = head;
    printf("The list is: ");
    while (curr != NULL) {
        printf("%d", curr->data);
        if(curr->next!=NULL)
        printf("-> ");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, choice, pos,t=1;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtPos(&head, i + 1, data);
    }
    do{
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(&head, pos, data);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                // Free memory and exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                t=0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(t==1);

    return 0;
}

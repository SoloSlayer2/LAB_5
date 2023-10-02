#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next; 
};
void createNode(struct Node** head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    if(*head==NULL)
    {
        ptr->next=ptr;
        *head=ptr;
    }
    else
    {
        struct Node* curr=*head;
        while(curr->next!=*head)
        curr=curr->next;
        curr->next=ptr;
        ptr->next=*head;
    }
}
void display(struct Node* head)
{
    struct Node* curr=head;
    if(head==NULL)
    {
        printf("List Is empty\n");
        return;
    }
    do
    {
        printf("%d",curr->data);
        if(curr->next!=head)
        printf("-> ");
        curr=curr->next;
    }while(curr!=head);
    printf("\n");
}
int main()
{
    int i,n;
    struct Node *head=NULL;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int data=0;
        printf("Enter data:\n");
        scanf("%d",&data);
        createNode(&head,data);
    }
    display(head);
    while(head!=NULL)
    {
        struct Node* temp=head;
        free(temp);
        head=head->next;
    }
    return 0;
}
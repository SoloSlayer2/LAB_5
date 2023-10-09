#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*top,*top1,*temp;
int count=-1;
void push(int data,int n)
{
    if(count==n-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    if(top==NULL)
    {
        top=(struct Node*)malloc(sizeof(struct Node));
        top->data=data;
        top->next=NULL;
    }
    else
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        temp->next=top;
        top=temp;
    }
    count++;
    printf("Node Inserted\n");
}
int pop()
{
    top1=top;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    top1=top1->next;
    int data=top->data;
    free(top);
    top=top1;
    count--;
    return data;
}
void traverse()
{
    top1=top;
    if(top1==NULL)
    {
        printf("Stack Underflow");
        return;
    }
    while(top1!=NULL)
    {
        printf("%d ",top1->data);
        if(top1->next!=NULL)
        printf("->");
        top1=top1->next;
    }
    printf("\n");
}
int main()
{
    int n,choice,value;
    printf("Enter size of stack");
    if(n<0)
    printf("Invalid Size");
    else
    scanf("%d",&n);
    while (1) 
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value,n);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
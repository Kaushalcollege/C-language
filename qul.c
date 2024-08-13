#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Front = NULL;
struct Node *Rear = NULL;
struct Node* Create_Node(int data)
{
    struct Node *newnode ;
    newnode = (struct Node*)malloc(1*sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}
void Enqueue(int data)
{
    struct Node *newnode = Create_Node(data);
    if(Front==NULL && Rear==NULL)
    {
        Front = Rear = newnode;
    }
    else
    {
        Rear->next = newnode;
        Rear = newnode;
    }
    printf("%d has been Enqueued into Queue.",Rear->data);
}
void Dequeue()
{
    if(Front==NULL && Rear==NULL)
    {
        printf("Queue is Empty");
    }
    else if(Front==Rear)
    {
        printf("%d has been Dequeued from the Queue",Front->data);
        Front = Rear = NULL;
    }
    else
    {
        printf("%d has been Dequeued from the Queue",Front->data);
        Front = Front->next;
    }
}
void Peek()
{
    if(Front==NULL && Rear==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("\nThe Front element is %d ",Front->data);
    }
}
void Display()
{
    printf("\nQueue :- ");
    struct Node *temp=Front;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}
int main()
{
    printf("-----------------WELCOME---------------------");
    printf("\nEnter 1 to Enqueue an Element into Queue ");
    printf("\nEnter 2 to Dequeue an Element from Queue");
    printf("\nEnter 3 to Peek into Queue");
    printf("\nEnter 4 to Display the Queue");
    printf("\nEnter -1 to Exit");
    
    int input,data;
    printf("\nEnter your Choice :- ");
    scanf("%d",&input);
    
    while(input!=-1)
    {
        switch(input)
        {
            case 1:
            {
                printf("Enter an Element to Enqueued into Queue :- ");
                scanf("%d",&data);
                Enqueue(data);
                break;
            }
            case 2:
            {
                Dequeue();
                break;
            }
            case 3:
            {
                Peek();
                break;
            }
            case 4:
            {
                Display();
                break;
            }
            default:
            {
                printf("Enter Valid Input");
            }
        }
        printf("\nEnter your Choice :- ");
        scanf("%d",&input);
    }
    printf("Program Terminated ..!");
    return 0;
}



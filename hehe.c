#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node* Create_Node(int data)
{
    struct node *newnode ;
    newnode = (struct node*)malloc(1*sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}
void enqueue(int data)
{
    struct node* newnode = Create_Node(data);
    if(front==NULL&&rear==NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    if(front==NULL&&rear==NULL)
    {
        printf("\n Stack Underflow.");
    }    
    else if (front==rear)
    {
        front=rear=NULL;
    }
    
    else
    {
        struct node*temp = front;
        front=front->next;
        free(temp);
    }
}
void peek()
{
    if(front==NULL&&rear==NULL)
    {
        printf("\n Stack Empty");
    } 
    else
    {
        printf("%d ", front->data);//the top of the queue is always the front pointer.
    }
}
void display()
{
    printf("\n Queue:-");
    struct node* temp = front;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data );
        temp=temp->next;
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
                enqueue(data);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                display();
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



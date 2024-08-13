#include<stdio.h>
#define size 5 
int front = -1, rear=-1 ;
int arr[100];
int IsFull()
{
    if(rear-front+1 == size)
        return 1;
    else
        return 0;
}
int IsEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
void Enqueue(int data)
{
    if(IsFull())
    {
        printf("Queue is Full");   
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
        printf("%d is Enqueued into Queue",arr[rear]);
    }
}
void Dequeue()
{
    if(IsEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("%d is Dequeued from Queue",arr[front]);
        if(front==rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}
void Peek()
{
    if(IsEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("The Front element is %d ",arr[front]);
    }
}
void Display()
{
    printf("Queue :- ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d -> ",arr[i]);
    }
}
int main()
{
    printf("-----------------WELCOME---------------------");
    printf("\nEnter 1 to Enqueue an Element into Queue ");
    printf("\nEnter 2 to Dequeue an Element from Queue");
    printf("\nEnter 3 to Peek into Queue");
    printf("\nEnter 4 to check if Queue is Full");
    printf("\nEnter 5 to check if Queue is Empty");
    printf("\nEnter 6 to Display the Queue");
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
                printf("Enter an Element to Enque into the Queue :- ");
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
                if(IsFull())
                    printf("Queue is Full");
                else
                    printf("Queue is Not Full");
                break;
            }
            case 5:
            {
                if(IsEmpty())
                    printf("Queue is Empty");
                else
                    printf("Queue is Not Empty");
                break;
            }
            case 6:
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
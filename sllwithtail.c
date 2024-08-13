#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head = NULL;
struct Node *Tail = NULL;
struct Node* Create_Node(int data)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(1*sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}
void Insert_At_End(int data)
{
    struct Node *newnode = Create_Node(data);
    if(Head == NULL)
    {
        Head = newnode;
        Tail = newnode;
    }
    else
    {
        Tail->next = newnode;
        Tail = newnode; 
    }
    
}
void Insert_At_Begin(int data)
{
    struct Node *newnode = Create_Node(data);
    if(Head == NULL)
    {
        Head = newnode;
        Tail = newnode;
    }
    else
    {
        newnode->next = Head ;
        Head = newnode;
        
    }
}
void Insert_At_Position(int data, int pos)
{
    struct Node *newnode = Create_Node(data);
    if(Head == NULL)
    {
        printf("List is Empty");
    }
    else if (pos==1)
    {
        newnode->next = Head ;
        Head = newnode;
    }
    else
    {
        struct Node *temp = Head ;
        while(pos-2)
        {
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next ;
        temp->next = newnode;
    }
}
void Delete_At_End()
{
    if(Head==NULL)
    {
        printf("List is Empty");
    }
    else if(Head->next == NULL)
    {
        struct Node *del = Head ;
        Head = NULL;
        Tail = NULL;
        printf("%d is Deleted from End of List",del->data);
        free(del);
    }
    else
    {
        struct Node *temp=Head ;
        while(temp->next->next!=NULL)
        {
            temp= temp->next ;
        }
        struct Node *del = temp->next ;
        Tail = temp;
        temp->next = NULL;
        printf("%d is Deleted from End of List",del->data);
        free(del);
    }
}
void Delete_At_Begin()
{
    if(Head==NULL)
    {
        printf("List is Empty");
    }
    else if(Head->next == NULL)
    {
        struct Node *del = Head ;
        Head = NULL;
        Tail = NULL;
        printf("%d is Deleted from Begining of List",del->data);
        free(del);
    }
    else
    {
       struct Node *del = Head ;
       Head = Head->next ;
       printf("%d is Deleted from Begining of List",del->data);
       free(del);
    }
}
void Delete_At_Position(int pos)
{
    int pos2 = pos;
    if (Head==NULL)
    {
        printf("List is Empty");
    }
    else if(pos==1)
    {
        struct Node *del = Head ;
        Head = Head->next;
        printf("%d is Deleted from %d position of List",del->data,pos2);
        free(del);
    }
    else
    {
        struct Node *temp = Head;
        while(pos-2)
        {
            temp = temp->next;
            pos--;
        }
        struct Node *del = temp->next ;
        temp->next = temp->next->next ;
        printf("%d is Deleted from %dth Position of List",del->data,pos2);
        free(del);
    }
}
void Display()
{
    struct Node *temp = Head ;
    printf("\nList :- \n");
    printf("%ld %ld\n",Head,Tail);
    while(temp!=NULL)
    {
        printf("%ld %d %ld\n",temp,temp->data,temp->next);
        temp=temp->next;
    }
}
int main()
{
    printf("-----------------WELCOME-----------------");
    printf("\nEnter 1 for Insertion At End :- ");
    printf("\nEnter 2 for Insertion At Begining :- ");
    printf("\nEnter 3 for Insertion At Position :- ");
    printf("\nEnter 4 for Deletion At End :- ");
    printf("\nEnter 5 for Deletion At Begining :- ");
    printf("\nEnter 6 for Deletion At Position :- ");
    printf("\nEnter 7 for Displaying the List :- ");
    printf("\nEnter -1 for Exiting the Program :- ");
    int input,data, pos;
    printf("\nEnter the desired input :- ");
    scanf("%d",&input);
    while(input!=-1)
    {
        switch(input)
        {
            case 1:
            {
                printf("Enter the data to insert :- ");
                scanf("%d",&data);
                Insert_At_End(data);
                printf("%d is Inserted at End of list",data);
                break;
            }
            case 2:
            {
                printf("Enter the data to insert :- ");
                scanf("%d",&data);
                Insert_At_Begin(data);
                printf("%d is Inserted at Begining of list",data);
                break;
            }
            case 3:
            {
                printf("Enter the data & Position to insert :- ");
                scanf("%d%d",&data,&pos);
                Insert_At_Position(data,pos);
                printf("%d is Inserted at Position %d in the list ",data,pos);
                break;
            }
            case 4:
            {
                Delete_At_End();
                break;
            }
            case 5:
            {
                Delete_At_Begin();
                break;
            }
            case 6:
            {
                printf("Enter the Position to Delete :- ");
                scanf("%d",&pos);
                Delete_At_Position(pos);
                break;
            }
            case 7:
            {
                Display();
                break;
            }
            default:
            {
                printf("Enter Valid Input");
                break;
            }
        }
        printf("\nEnter the desired input :- ");
        scanf("%d",&input);
    }
    printf("Program Terminated ..!");
    return 0;
}
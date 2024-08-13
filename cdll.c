#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *Head = NULL;
struct Node *Tail = NULL;
struct Node* Create_Node(int data)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(1*sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
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
        newnode->prev = Tail ;
        Tail->next = newnode;
        Tail = newnode; 
    }
    Tail->next = Head ;
    Head->prev = Tail ;
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
        Head->prev = newnode ;
        Head = newnode;
    }
    Tail->next = Head ;
    Head->prev = Tail ;
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
        Head->prev = newnode;
        Head = newnode;
        Tail->next = Head ;
        Head->prev = Tail ;
    }
    else
    {
        struct Node *temp = Head ;
        while(pos-2)
        {
            temp = temp->next;
            pos--;
        }
        newnode->prev = temp;
        newnode->next = temp->next ;
        temp->next->prev = newnode ;
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
        struct Node *del = Tail;
        Tail = Tail->prev;
        Tail->next = Head;
        Head->prev = Tail;
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
       Tail->next = Head;
       Head->prev = Tail;
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
        Tail->next = Head;
        Head->prev = Tail;
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
        temp->next->prev = temp;
        printf("%d is Deleted from %dth Position of List",del->data,pos2);
        free(del);
    }
}
void Display()
{
    struct Node *temp = Head ;
    printf("\nList :- \n");
    printf("%ld %ld\n",Head,Tail);
    while(temp->next!=Head)
    {
        printf("%ld %ld %ld %ld\n",temp->prev,temp,temp->data,temp->next);
        temp=temp->next;
    }
    printf("%ld %ld %ld %ld\n",temp->prev,temp,temp->data,temp->next);

}
int main()
{
    printf("Enter 1 to Insert at Ending :- ");
    printf("\nEnter 2 to Insert at Begining :- ");
    printf("\nEnter 3 to Insert at Position :- ");
    printf("\nEnter 4 to Delete at Ending :- ");
    printf("\nEnter 5 to Delete at Begining :- ");
    printf("\nEnter 6 to Delete at Position :- ");
    printf("\nEnter 7 to Display :- ");
    printf("\nEnter -1 to Exit :- ");
    
    int n,data,pos;
    printf("\nEnter your Choice :- ");
    scanf("%d",&n);
    
    while(n!=-1)
    {
        switch(n)
        {
            case 1:
            {
                printf("Enter the data:- ");
                scanf("%d",&data);
                Insertion_At_End(data);
                printf("%d is Inserted at End",data);
                break;
            }
            case 2:
            {
                printf("Enter the data:- ");
                scanf("%d",&data);
                Insertion_At_Beg(data);
                printf("%d is Inserted at Begining",data);
                break;
            }
            case 3:
            {
                printf("Enter the data & Position:- ");
                scanf("%d%d",&data,&pos);
                Insertion_At_Pos(data,pos);
                printf("%d is Inserted at Position %d",data,pos);
                break;
            }
            case 4:
            {
                Deletion_At_End();
                printf("Value Deleted at End");
                break;
            }
            case 5:
            {
                Deletion_At_Beg();
                printf("Value Deleted at Begining");
                break;
            }
            case 6:
            {
                printf("Enter Position to delete:- ");
                scanf("%d",&pos);
                Deletion_At_Pos(pos);
                printf("Value Deleted at Position %d",pos);
                break;
            }
            case 7:
            {
                printf("The Linked List is :- ");
                Display();
                break;
            }
            default :
            {
                printf("Enter Valid Input");
                break;
            }
        }
        printf("\n\nEnter your Choice :- ");
        scanf("%d",&n);
    }
    printf("Program Terminated :- ");
    return 0;
}
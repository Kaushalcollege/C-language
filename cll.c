#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *Head = NULL;
struct Node *Tail = NULL;

struct Node* Create_Node(int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}

void Insert_At_End(int data) {
    struct Node *newnode = Create_Node(data);
    if (Head == NULL) {
        Head = newnode;
        Tail = newnode;
        newnode->next = Head;
    } else {
        Tail->next = newnode;
        Tail = newnode;
        Tail->next = Head;
    }
}

void Insert_At_Begin(int data) {
    struct Node *newnode = Create_Node(data);
    if (Head == NULL) {
        Head = newnode;
        Tail = newnode;
        newnode->next = Head;
    } else {
        newnode->next = Head;
        Head = newnode;
        Tail->next = Head;
    }
}

void Insert_At_Position(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node *newnode = Create_Node(data);
    if (Head == NULL) {
        if (pos == 1) {
            Head = newnode;
            Tail = newnode;
            newnode->next = Head;
        } else {
            printf("Invalid position\n");
            free(newnode);
            return;
        }
    } else if (pos == 1) {
        Insert_At_Begin(data);
    } else {
        struct Node *temp = Head;
        int i = 1;
        while (temp->next != Head && i < pos - 1) {
            temp = temp->next;
            i++;
        }
        if (i != pos - 1) {
            printf("Position out of range\n");
            free(newnode);
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp == Tail) {
            Tail = newnode;
        }
    }
}

void Delete_At_End() {
    if (Head == NULL) {
        printf("List is Empty\n");
    } else if (Head->next == Head) {
        printf("%d is Deleted from End of List\n", Head->data);
        free(Head);
        Head = NULL;
        Tail = NULL;
    } else {
        struct Node *temp = Head;
        while (temp->next != Tail) {
            temp = temp->next;
        }
        printf("%d is Deleted from End of List\n", Tail->data);
        free(Tail);
        temp->next = Head;
        Tail = temp;
    }
}

void Delete_At_Begin() {
    if (Head == NULL) {
        printf("List is Empty\n");
    } else if (Head->next == Head) {
        printf("%d is Deleted from Beginning of List\n", Head->data);
        free(Head);
        Head = NULL;
        Tail = NULL;
    } else {
        struct Node *temp = Head;
        Head = Head->next;
        printf("%d is Deleted from Beginning of List\n", temp->data);
        free(temp);
        Tail->next = Head;
    }
}

void Delete_At_Position(int pos) {
    if (Head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        Delete_At_Begin();
        return;
    }
    struct Node *temp = Head;
    struct Node *prev = NULL;
    int i = 1;
    while (temp->next != Head && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (i != pos) {
        printf("Position out of range\n");
        return;
    }
    printf("%d is Deleted from Position %d\n", temp->data, pos);
    prev->next = temp->next;
    if (temp == Tail) {
        Tail = prev;
    }
    free(temp);
}

void Display() {
    if (Head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = Head;
    printf("List: ");
    do {
        printf("%ld %ld \n %ld %ld \n %ld\n  ",Head,temp, temp->data,temp->next,Tail);
        temp = temp->next;
    } while (temp != Head);
    printf("\n");
}

int main() {
    printf("-----------------WELCOME-----------------\n");
    printf("Enter 1 for Insertion At End\n");
    printf("Enter 2 for Insertion At Beginning\n");
    printf("Enter 3 for Insertion At Position\n");
    printf("Enter 4 for Deletion At End\n");
    printf("Enter 5 for Deletion At Beginning\n");
    printf("Enter 6 for Deletion At Position\n");
    printf("Enter 7 for Displaying the List\n");
    printf("Enter -1 for Exiting the Program\n");

    int input, data, pos;
    printf("Enter the desired input: ");
    scanf("%d", &input);
    while (input != -1) {
        switch (input) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                Insert_At_End(data);
                printf("%d is Inserted at End of list\n", data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                Insert_At_Begin(data);
                printf("%d is Inserted at Beginning of list\n", data);
                break;
            case 3:
                printf("Enter the data & Position to insert: ");
                scanf("%d %d", &data, &pos);
                Insert_At_Position(data, pos);
                printf("%d is Inserted at Position %d in the list\n", data, pos);
                break;
            case 4:
                Delete_At_End();
                break;
            case 5:
                Delete_At_Begin();
                break;
            case 6:
                printf("Enter the Position to Delete: ");
                scanf("%d", &pos);
                Delete_At_Position(pos);
                break;
            case 7:
                Display();
                break;
            default:
                printf("Enter Valid Input\n");
                break;
        }
        printf("Enter the desired input: ");
        scanf("%d", &input);
    }
    printf("Program Terminated\n");
    return 0;
}


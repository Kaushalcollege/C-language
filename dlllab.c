#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

bool isEmpty()
{
    return head == NULL;
}

int length()
{
    int length = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

void displayForward()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}

void displayBackward()
{
    struct node *ptr = last;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->prev;
    }
}

void insertFirst(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    if (isEmpty())
    {
        last = link;
    }
    else
    {
        head->prev = link;
    }
    link->next = head;
    head = link;
}

void insertLast(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    if (isEmpty())
    {
        head = link;
    }
    else
    {
        last->next = link;
        link->prev = last;
    }
    last = link;
}

void deleteFirst()
{
    if (isEmpty())
    {
        printf("List is empty, cannot delete first element.\n");
        return;
    }
    struct node *tempLink = head;
    if (head->next == NULL)
    {
        last = NULL;
    }
    else
    {
        head->next->prev = NULL;
    }
    head = head->next;
    free(tempLink);
}

void deleteLast()
{
    if (isEmpty())
    {
        printf("List is empty, cannot delete last element.\n");
        return;
    }
    struct node *tempLink = last;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        last->prev->next = NULL;
    }
    last = last->prev;
    free(tempLink);
}

struct node *delete (int key)
{
    struct node *current = head;
    struct node *previous = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    while (current->data != key)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    if (current == head)
    {
        head = head->next;
    }
    else
    {
        current->prev->next = current->next;
    }
    if (current == last)
    {
        last = current->prev;
    }
    else
    {
        current->next->prev = current->prev;
    }
    free(current);
    return current;
}

void insertAfter(int key, int data)
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty, cannot insert after.\n");
        return;
    }
    while (current->data != key)
    {
        if (current->next == NULL)
        {
            printf("Key not found in the list.\n");
            return;
        }
        else
        {
            current = current->next;
        }
    }
    struct node *newLink = (struct node *)malloc(sizeof(struct node));
    newLink->data = data;
    if (current == last)
    {
        newLink->next = NULL;
        last = newLink;
    }
    else
    {
        newLink->next = current->next;
        current->next->prev = newLink;
    }
    newLink->prev = current;
    current->next = newLink;
}

int main()
{
    int choice = 0, i, j;
    while (1)
    {
        printf("\n0.insertafter\n1.insertFirst\n2.insertLast\n3.deleteLast\n");
        printf(" 4.Deletefirst\n5.delete\n6.displayForward\n7.displayBackward\n8.exit\n");
        printf("Enter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Enter key and data: ");
            scanf("%d %d", &i, &j);
            insertAfter(i, j);
            break;

        case 1:
            printf("Enter data: ");
            scanf("%d", &i);
            insertFirst(i);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &i);
            insertLast(i);
            break;

        case 3:
            deleteLast();
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            printf("Enter element to be deleted: ");
            scanf("%d", &i);
            delete (i);
            break;

        case 6:
            printf("List Forward: ");
            displayForward();
            break;

        case 7:
            printf("List Backward: ");
            displayBackward();
            break;

        case 8:
            exit(0);

        default:
            printf("Please enter valid choice..\n");
        }
    }
    return 0;
}

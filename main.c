//Abdurrehman Zulfiqar
//ID:AXZ190015
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
//Node structure
struct Node
{
    int num;
    struct Node *next;
};

void displayList(struct Node*);
void bubbleSort(struct Node*);
void selectionSort(struct Node*);
void swap(struct Node*, struct Node*);

int main()
{
    //Creating node pointers
    //=====================================================================
    struct Node *n = NULL;//node
    struct Node *temp = NULL;//temp node 1
    struct Node *temp2 = NULL;//temp node 2
    struct Node *head = NULL;//head of first linked list
    struct Node *head2 = NULL;//head of second linked list
    //=====================================================================
    //Allocating the nodes
    int x, i;
    const int SIZE = 8;
    for (i = 0; i < SIZE; i++)
    {
        //User input for 8 integers
        scanf("%d", &x);
        //Linked List 1
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->num = x;
        temp->next = NULL;
        if(head == NULL)
            head = temp;
        else
        {
           n = head;
           while (n->next != NULL)
                n = n->next;
           n->next = temp;
        }
        //Linked List 2
        temp2 = (struct Node*)malloc(sizeof(struct Node));
        temp2->num = x;
        temp2->next = NULL;
        if(head2 == NULL)
            head2 = temp2;
        else
        {
           n = head2;
           while (n->next != NULL)
                n = n->next;
           n->next = temp2;
        }
    }
    displayList(head);
    bubbleSort(head);
    displayList(head2);
    selectionSort(head2);
    //=====================================================================
    return 0;
}

void displayList(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

void swap(struct Node *x, struct Node *y)
{
    int t = x->num;
    x->num = y->num;
    y->num = t;
}

void bubbleSort(struct Node *head)
{
    int flag, a;
    struct Node *ptr;
    struct Node *ptr2 = NULL;
    if (head == NULL)
        return;
    do
    {
        flag = 0;
        ptr = head;
        while(ptr->next != NULL)
        {
            if(ptr->num > ptr->next->num)
            {
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        ptr2 = ptr;
        displayList(head);
    }while(flag);
}

void selectionSort(struct Node *head)
{
    struct Node *t = head;

    while(t->next)
    {
        struct Node *minIndex = t;
        struct Node *sb = t->next;
        while(sb)
        {
            if(minIndex->num > sb->num)
                minIndex = sb;
            sb = sb->next;
        }
        swap(t, minIndex);
        t = t->next;
        displayList(head);
    }
}

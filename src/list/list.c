/* 
list
empty list has size 0
insert 
remove
read/modify
element at position 
specify data-type

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
int size = 0;

void insertFront(int data);
void insertBack(int data);
int peak(void);
void printList(void);
void removeFromFront(void);
void removeFromBack(void);
void clear(void);

void insertFront(int data)
{
    // get curr and point to new node
    // set new node as head
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = head;

    head = new_node;

    size++;
}

void insertBack(int data)
{
    // get current head
    // move to back
    // create new node and add it to back

    struct node *current = head;

    if(head != NULL)
    {
        // move to last last
        while(current->next != NULL)
        {
            current = current->next;
        }
    }

    // insert
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    current->next = new_node;
    tail = new_node;

    size++;
}

void removeFromFront(void)
{
    if(head==NULL) return;

    struct node *current = head;
    head = head->next;
    
    size--;

    free(current);
    current = NULL;
}

void removeFromBack(void)
{
    if(tail==NULL) return;

    struct node *prev;
    struct node *current = head;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    tail = prev;
    size--;

    free(current);
    current = NULL;
}

void clear(void)
{
    if(head == NULL ) return;

    struct node *current = head;

    while(head->next != NULL)
    {
        current = head;
        head = head->next;
        free(current);
        current = NULL;
        size --;
    }
    head = NULL;
}

int peak(void)
{
    if(head!=NULL) 
        return head->data;
}

void printList(void)
{
    if(head == NULL)
    {
        printf("List: (Empty)\n");
        return;
    }

    struct node* current = head;


    printf("List: (Head) %d->", current->data);
    current = current->next;
    
    while(current->next != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d->NULL\n", current->data);
}

int main(int argc, void **args)
{
    printList();
    insertFront(10);
    insertFront(5);
    insertFront(2);
    insertFront(1);

    insertBack(0);
    insertBack(2);
    insertBack(15);
    insertBack(2);
    insertFront(7);

    printList();
    removeFromBack();
    removeFromFront();
    removeFromFront();
    printList();
    clear();
    printList();

    return 0;
}


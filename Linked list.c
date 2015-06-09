#include <stdio.h>
#include <stdlib.h>

struct link  //structure template
{
int data;
struct link *next;
};

typedef struct link node; //user defined type def
node *head; //head node

//function prototype definitions
void create(node *list);
void display(node *list);
node *insert(node *list, int key, int x);
node *del(node *list, int key);
node *del2(node *list, int key);
node *sort(node *list);

main () //main() func start
{
node *n1;
int i, j, key, x;
head = (node *)malloc(sizeof(node));
printf("Your choices are:\n1. Create a linked list.\n2. Display the created linked list.\n3. Insert an element in the linked list.\n4. Delete entire linked list after specific element.\n5. Delete a specific node.\n6. Sort the Linked list.\n");
do
{
printf("\nEnter your choice: ");
scanf("%d", &i);

switch(i) //switch-case method
{

case 1:
{create(head);
break;}

case 2:
{display(head);
break;}

case 3:
{
printf("Enter element of node to be found: "); scanf("%d", &key);
printf("Enter value of data to be inserted: "); scanf("%d", &x);
n1 = insert(head, key, x);
if (n1 == NULL)
    printf("Key not found.");
break;
}

case 4:
{
printf("Enter element of node to be found: "); scanf("%d", &key);
del(head, key);
break;
}

case 5:
{
printf("Enter element of node to be deleted: "); scanf("%d", &key);
n1 = del2(head, key);
if (n1==NULL)
    printf("Key not found.");
break;
}

case 6:
{
n1 = sort(head);
if (n1==NULL)
printf("\nLinked list has been sorted.");
break;
}
default:
printf("Choice not found, re-enter choice by entering 0 at next question.");
}
printf("\nDo you want to continue? (0/1): ");
scanf("%d", &j);
}while(j==0);
}

node *del2(node *list, int key)
{
    if (list->data == key)
    {
        head = list->next;
    }
    else if (list->next->data == key)
    {
        list->next = list->next->next;
    }
    else if(list->next->next == NULL)
        return (NULL);
    else del2(list->next, key);
}
node *insert(node *list, int key, int x)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    if (list->data == key)
    {
        new->data = x;
        new->next = head;
        head = new;
    }
    else if(list->next->data == key)
    {
        new->data = x;
        new->next = list->next;
        list->next = new;
    }
    else if (list->next == NULL)
    return (NULL);
    else
        insert(list->next, key, x);
}

node * del(node *list, int key)
{
if (list->data == key)
{
    list->next = NULL;
}
else
    del(list->next, key);
}

void create(node *list)
{
    printf("Enter data part of linked list (-1 to end): ");
    scanf("%d", &list->data);
    if (list->data == -1)
    {
        list->next = NULL;
    }
    else
    {
        list->next = (node*)malloc(sizeof(node));
        create(list->next);
    }
}

node *sort(node *list)
{
int a;
if (list->data > list->next->data)
{
a = list->data;
list->data = list->next->data;
list->next->data = a;
sort(head);
}
else if(list->next->next == NULL)
{return(NULL);}
else
sort(list->next);
}

void display(node *list)
{
 if (list->next != NULL)
 {
 printf("%d ---> ", list->data);
 display(list->next);
 }
 else
 printf("%d", list->data);
}

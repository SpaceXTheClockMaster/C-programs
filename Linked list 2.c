#include <stdio.h>
#include <stdlib.h>

struct link  //structure template
{
int data;
struct link *next;
};

typedef struct link node; //user defined type definition

node *head; //head node FIRST LINKED LIST
node *head1; //head1 node SECOND LINKED LIST

//function prototype definitions
void create(node *list);
void display(node *list);
void add(node *list1, node*list2)

main () //main() func start
{
node *n1;
int i, j, x;
head = (node *)malloc(sizeof(node));
head1 = (node*)malloc(sizeof(node));
//^SPACE ALLOCATION

printf("Your choices are:\n1. Create a linked list.\n2. Display the created linked list.\n3. Add the two linked lists. (Add only if made or program will crash)\n");
do
{
printf("\nEnter your choice: ");
scanf("%d", &i);

switch(i) //switch-case method + do-while
{

case 1:
{
printf("Enter linked list you want to create (1 or 2): ");
scanf("%d", &x);
if (x==1)
create(head);
else if (x==2)
create(head1);
break;
}

case 2:
{
printf("Enter linked list you want to display (1 or 2): ");
scanf("%d", &x);
if (x==1)
display(head);
else if (x==2)
display(head1);
}

case 3:
{
add(head, head1);
break;
}

default:
printf("Choice not found, re-enter choice by entering 0 at next question.");
}
printf("\nDo you want to continue? (0/1): ");
scanf("%d", &j);
}while(j==0);
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

void add(node*list1, node*list2)
{
int n;
if (list1->next != NULL && list2->next != NULL)
{
list1->data = list1->data + list2->data;
if (list1->data > = 10 && list1->next!=NULL)
{
n = list1->data/10;
list->next->data = n+list1->data;
}
add(list1->data, list2->data); //RECURSION.
}




#include<stdio.h>
#include<stdlib.h>
struct list 
{
    int info;
    struct list *next;
};
typedef struct list node;
void clearbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {

    }
}
node *create ()
{
    node *start, *newnode,*prev;
    start = NULL;
    int num;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the number:");
        scanf("%d",&num);
        newnode = (node*) malloc (sizeof(node));
        if(newnode == NULL)
        {
            newnode = (node *) malloc (sizeof(node));
            newnode -> info = num;
            newnode -> next = NULL;
            if(start == NULL)
            {
                start = newnode ;
            }
            else 
            {
                prev -> next = newnode;
            }
            prev = newnode;
        }
        else
        {
            newnode -> info = num;
            newnode -> next = NULL;
            if(start == NULL)
            {
                start = newnode ;
            }
            else 
            {
                prev -> next = newnode;
            }
            prev = newnode;
        }
        printf("Do you eish to continue (y/n):");
        clearbuffer();
        scanf("%c",&another);
        clearbuffer();
    }
    return start;
}
void freelist(node *start)
{
    node *temp;
    while (start != NULL)
    {
        temp = start ;
        start = start-> next;
        free(temp);
    }
}
void display(node *start)
{
    for (node *temp = start;temp != NULL; temp = temp -> next)
    {
        printf("%d \n",temp -> info);
    }
}
node *reverse(node *start)
{
    node *current,*prev,*save;
    prev = NULL;
    current = start;
    while (current != NULL)
    {
        save = current -> next;
        current -> next = prev;
        prev = current;
        current = save;
    }
    start = prev;
    return start;
}
int main()
{
    node *start;
    start = create();
    printf("Normal List:\n");
    display(start);
    printf("Reversed list:\n");
    start = reverse(start);
    display(start);
    return 0;
}
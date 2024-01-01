#include <stdio.h>
#include <stdlib.h>
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
node *create()
{
    node *start, *newnode, *prev;
    start = NULL;
    char another = 'y';
    int num;
    while (another == 'y')
    {
        printf("Enter the Numbers in ascending order:");
        scanf("%d", &num);
        newnode = (node *)malloc(sizeof(node));
        newnode->info = num;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            prev->next = newnode;
        }
        prev = newnode;
        printf("Do you wish to continue (y/n):");
        clearbuffer();
        scanf("%c", &another);
        clearbuffer();
    }
    return start;
}
void display(node *start)
{
    node *temp;
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->info);
    }
}
node *insertatend(node *start, int num)
{
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return start;
}
int main()
{
    node *start, *newstart = NULL;
    start = create();
    node *temp = start;
    while (temp != NULL)
    {
        newstart = insertatend(newstart, temp->info);
        temp = temp->next;
    }
    display(newstart);
    return 0;
}
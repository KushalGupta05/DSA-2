#include <stdio.h>
#include <stdlib.h>
struct list
{
    int info;
    struct list *next, *prev;
};
typedef struct list node;
void clearbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void create(node **start, node **last)
{
    node *newnode;
    int num;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the number : ");
        scanf("%d", &num);
        newnode = (node *)malloc(sizeof(node));
        newnode -> info = num;
        newnode->next = newnode->prev = NULL;
        if (*start == NULL)
        {
            *start = newnode;
        }
        else
        {
            newnode->prev = *last;
            (*last)->next = newnode;
        }
        *last = newnode;
        printf("Do uo wish to continue :");
        clearbuffer();
        scanf("%c", &another);
        clearbuffer();
    }
}
void display(node *start, node *last)
{
    node *temp;
    printf("Forward printing:\n");
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->info);
    }
    printf("Backward printing:\n");
    for (temp = last; temp != NULL; temp = temp->prev)
    {
        printf("%d\n", temp->info);
    }
}
void insert(node **start, node **last, int num, int pos)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = NULL;
    if (*start == NULL || pos == 1)
    {
        newnode -> prev = NULL;
        newnode->next = *start;
        if (*start != NULL)
        {
            (*start)->prev = newnode;
        }
        else
        {
            *last = newnode;
        }
        *start = newnode;
    }
    else
    {
        temp = *start;
        int i = 2;
        while (i <=pos-1 && temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newnode;
        }
        else
        {
            *last = newnode;
        }
        temp->next = newnode;
    }
}
int main()
{
    node *start = NULL, *last;
    create(&start, &last);
    display(start,last);
    int num, pos;
    printf("Enter the number and postion at you wish ti enter :");
    scanf("%d %d", &num, &pos);
    insert(&start, &last, num, pos);
    display(start, last);
    return 0;
}
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
        scanf("%c",&another);
        clearbuffer();
    }
    return start;
}
node *insertasc(node *start, int n)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = n;
    newnode->next = NULL;

    if (n < start->info || start == NULL)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        temp = start;
        while (1)
        {
            if ((n > temp->info && (temp->next == NULL || n < temp->next->info)))
            {
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    return start;
}
void display(node *start)
{
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d\n",temp->info);
        temp = temp-> next;
    }
}
int main()
{
    node * start = NULL;
    int num;
    start = create();
    printf("List:\n");
    display(start);
    printf("Enter the number you want to insert:");
    scanf("%d",&num);
    start = insertasc(start,num);
    printf("Modified list:\n");
    display(start);
    return 0;
}
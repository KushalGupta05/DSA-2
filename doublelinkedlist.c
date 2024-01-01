#include<stdio.h>
#include<stdlib.h>
struct dlist
{
    int info;
    struct dlist *prev,*next;
};
typedef struct dlist node;
void clearbuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void freememory(node *start)
{
    node *temp ;
    temp = start;
    while (temp != NULL)
    {
        start = start -> next;
        free(temp);
        temp = start;
    }
}
int main()
{
    node *newnode,*start = NULL,*last,*temp;
    int num;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the number :");
        scanf("%d",&num);
        newnode = (node*)malloc (sizeof(node));
        if(newnode != NULL)
        {
            newnode = (node *) malloc (sizeof(node));
        }
        newnode->info = num;
        newnode->next = NULL;
        if(start == NULL)
        {
            newnode -> prev = NULL;
            start = newnode;
        }
        else 
        {
            newnode -> prev = last;
            last -> next = newnode;
        }
        last = newnode;
        printf("Do uou wish  to continue [y/n]:");
        clearbuffer();
        scanf("%c",&another);
        clearbuffer();
    }
    printf("Forward printing :\n");
    for(temp = start;temp != NULL;temp = temp -> next)
    {
        printf("%d\n",temp -> info);
    }
    printf("Backward printing:\n");
    for(temp = last ; temp != NULL ; temp = temp -> prev)
    {
        printf("%d\n",temp -> info);
    }
    freememory(start);
    return 0;
}
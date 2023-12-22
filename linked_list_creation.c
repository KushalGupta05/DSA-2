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
int main()
{
    node *start = NULL,*newnode,*prev,*temp;
    char another = 'y';
    int num;
    while ( another == 'y')
    {
        printf("Enter the number : ");
        scanf("%d",&num);
        newnode = (node *) malloc(sizeof(node));
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
    for (temp = start;temp!=NULL;temp=temp->next)
    {
        printf("%d\n",temp->info);
    }
    return 0;


}
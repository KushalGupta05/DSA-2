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
    node *start = NULL, *newnode, *prev;
    char another = 'y';
    int num;
    while (another == 'y')
    {
        printf("Enter the number :");
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
    node *temp = start;
    if (start == NULL)
    {
        printf("List empty\n");
    }
    else
    {
        for (temp = start; temp != NULL; temp = temp->next)
        {
            printf("%d\n", temp->info);
        }
    }
}
node *insert(node *start, int num, int pos)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = NULL;
    if (start == NULL || pos == 1)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        temp = start;
        int count = 2;
        while (count < pos && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return start;
}
int delete(node **start, int num)
{
    node *temp, *prev;
    if (*start == NULL)
    {
        return 0;
    }
    else
    {
        prev = NULL;
        temp = *start;
        while (temp != NULL && temp->info != num)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            if (temp == *start)
            {
                *start = (*start)->next;
                free(temp);
                return 1;
            }

            else
            {
                prev->next = temp->next;
                free(temp);
                return 1;
            }
        }
    }
}
int main()
{
    int num, pos, opt, flag = 0;
    node *start = NULL;
    while (1)
    {
        printf("\nSelect from the options below:\n1.)Create a linked list:\n2.)Display a linked list\n3.)Insert a element in the linked:\n4.)Delete a elemnet in the linked list:\n5.)Exit from the linked list\n ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (flag == 0)
            {
                start = create();
                printf("Linked list created\n");
                flag++;
            }
            else
            {
                printf("Linked list already created\n");
            }
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Enter the elemnts and ata what postion do you wish to enter :");
            scanf("%d %d", &num, &pos);
            start = insert(start, num, pos);
            break;
        case 4:
            printf("Enter the element you want to delete :");
            scanf("%d", &num);
            int r = delete (&start, num);
            if (r == 1)
            {
                printf("Elemet successfully deleted\n");
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
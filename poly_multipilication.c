#include <stdio.h>
#include <stdlib.h>
struct list
{
    int coeff;
    int exp;
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
    node *newnode, *prev, *start = NULL;
    int c, e;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the coefficient:");
        if (scanf("%d", &c) != 1)
        {
            printf("Invalid input for coefficient. Exiting.\n");
            freelist(start);
            exit(EXIT_FAILURE);
        }
        clearbuffer();
        printf("Enter the exponent:");
        if (scanf("%d", &e) != 1)
        {
            printf("Invalid input for exponent. Exiting.\n");
            freelist(start);
            exit(EXIT_FAILURE);
        }
        clearbuffer();
        newnode = (node *)malloc(sizeof(node));
        newnode->coeff = c;
        newnode->exp = e;
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
        scanf("%c", &another);
        clearbuffer();
    }
    return start;
}
node *insertpolydesc(node *start, int c, int e)
{
    node *newnode, *temp;
    temp = start;
    while (temp != NULL && temp->exp != e)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->coeff = temp->coeff + c;
        return start;
    }
    else
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->coeff = c;
        newnode->exp = e;
        newnode->next = NULL;
        if (e > start->exp || start == NULL)
        {
            newnode->next = start;
            start = newnode;
        }
        else
        {
            temp = start;
            while (1)
            {
                if (temp->next == NULL || (e < temp->exp && e > temp->next->exp))
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
}
node *polymult(node *start1, node *start2)
{
    node *start = NULL;
    node *tempx, *tempy;
    int c, e;
    for (tempx = start1; tempx != NULL; tempx = tempx->next)
    {
        for (tempy = start2; tempy != NULL; tempy = tempy->next)
        {
            c = tempx->coeff * tempy->coeff;
            e = tempx->exp + tempy->exp;
            start = insertpolydesc(start, c, e);
        }
    }
    return start;
}
void display(node *start)
{
    node *temp;
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%d %d     ", temp->coeff, temp->exp);
    }
}
void freelist(node *start)
{
    node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}
int main()
{
    node *start1, *start2, *start3 = NULL;
    int c, e;
    printf("Polynomial 1 :\n");
    start1 = create();
    printf("Polynomial 2 :\n");
    start2 = create();
    clearbuffer();
    printf("Multiplied list :\n");
    start3 = polymult(start1, start2);
    display(start3);
    freelist(start1);
    freelist(start2);
    freelist(start3);
    return 0;
}
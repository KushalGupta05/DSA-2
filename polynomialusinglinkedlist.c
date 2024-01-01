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
        scanf("%d", &c);
        clearbuffer();
        printf("Enter the exponent:");
        scanf("%d", &e);
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
node *insertatend(node *start, int c, int e)
{
    node *newnode, *temp;
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
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
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
node *addpoly(node *start1, node *start2)
{
    node *tempx, *tempy;
    node *start = NULL; /*result linked list*/
    int c, e;
    tempx = start1;
    tempy = start2;
    while (tempx != NULL && tempy != NULL)
    {
        if (tempx->exp == tempy->exp)
        {
            c = tempx->coeff + tempy->coeff;
            e = tempx->exp;
            tempx = tempx->next;
            tempy = tempy->next;
        }
        else
        {
            if (tempx->exp > tempy->exp)
            {
                c = tempx->coeff;
                e = tempx->exp;
                tempx = tempx->next;
            }
            else
            {
                c = tempy->coeff;
                e = tempy->exp;
                tempy = tempy->next;
            }
        }
        start = insertatend(start, c, e);
    }
    if (tempy == NULL && tempx != NULL)
    {
        while (tempx != NULL)
        {
            c = tempx->coeff;
            e = tempx->exp;
            start = insertatend(start, c, e);
            tempx = tempx->next;
        }
    }
    if (tempx == NULL && tempy != NULL)
    {
        while (tempy != NULL)
        {
            c = tempy->coeff;
            e = tempy->exp;
            start = insertatend(start, c, e);
            tempy = tempy->next;
        }
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
int main()
{
    node *start1, *start2, *start3 = NULL;
    int c, e;
    printf("Polynomial 1 :\n");
    start1 = create();
    printf("Polynomial 2 :\n");
    start2 = create();
    start3 = addpoly(start1, start2);
    display(start3);
    printf("\nEnter the coefficent and exponent you want to enter:");
    scanf("%d %d", &c, &e);
    start3 = insertpolydesc(start3, c, e);
    printf("\nModified list is :\n");
    display(start3);
    start3 = polymult(start1, start2);
    printf("Multiplied list :\n");
    display(start3);
    freelist(start1);
    freelist(start2);
    freelist(start3);
    return 0;
}

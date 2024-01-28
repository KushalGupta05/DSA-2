#include <stdio.h>
#include <stdlib.h>
struct bintree
{
    int info;
    struct bintree *right, *left;
};
typedef struct bintree node;
void clearbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c == EOF)
    {
    }
}
node *insert(node *s, int n)
{
    if (s == NULL)
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        newnode->right = newnode->left = NULL;
        newnode->info = n;
        return newnode;
    }
    else
    {
        if (s->info > n)
        {
            s->left = insert(s->left, n);
        }
        else
        {
            s->right = insert(s->right, n);
        }
        return s;
    }
}
void inorder(node *s)
{
    if (s != NULL)
    {
        inorder(s->left);
        printf("%d\n", s->info);
        inorder(s->right);
    }
}
int search(node *s, int n)
{
    int r = 0;
    if (s == NULL)
    {
        return 0;
    }
    if (s->info == n)
    {
        return 1;
    }
    if (s->info > n)
    {
        r = search(s->left, n);
    }
    else
    {
        r = search(s->right, n);
    }
}
void freeTree(node *s)
{
    if (s != NULL)
    {
        freeTree(s->left);
        free(s);
        freeTree(s->right);
    }
}
int main()
{
    node *root = NULL;
    int n, c, r, k = 0, t;
    char another = 'y';
    while (1)
    {
        printf("\n1)Create a TREE:\n2)Print TREE\n3)Search the number:\n4)Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (k == 0)
            {
                while (another == 'y')
                {
                    printf("Enter the number:");
                    scanf("%d", &n);
                    clearbuffer();
                    root = insert(root, n);
                    printf(
                        "Do you wish to continue(y/n):");
                    scanf("%c", &another);
                    clearbuffer();
                }
                k++;
                printf("Tree created successfully\n");
            }
            else
            {
                printf("Please create the Tree:\n");
            }
            break;
        case 2:
            if (k == 1)
            {
                inorder(root);
            }
            else
            {
                printf("Please create the tree first\n");
            }
            break;
        case 3:
            if (k == 1)
            {
                printf("Enter the number you wish to search :");
                scanf("%d", &r);
                t = search(root, r);
                if (t == 1)
                {
                    printf("Element found\n");
                }
                else
                {
                    printf("Element not found\n");
                }
            }
            else
            {
                printf("Please create the Tree\n");
            }
        case 4:
            freeTree(root);
            exit(0);
        }
    }
}

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
    while ((c = getchar()) != '\n' && c != EOF)
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
void cpy(node *s, node **cs)
{
    if (s != NULL)
    {
        cpy(s->left, cs);
        *cs = insert(*cs, s->info);
        cpy(s->right, cs);
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
    node *root = NULL, *croot = NULL;
    int n, r, t, c, k = 0;
    char another = 'y';
    while (1)
    {
        printf("\n1)Create a TREE:\n2)Print TREE\n3)Copy Tree\n4)Exit\n");
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
                cpy(root, &(croot));
                inorder(croot);
            }
            else
            {
                printf("Please create the Tree\n");
            }
            break;
        case 4:
            freeTree(root);
            freeTree(croot);
            exit(0);
        }
    }
    return 0;
}
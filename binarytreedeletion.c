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
        ;
}
node *create(node *s, int n)
{
    if (s == NULL)
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        newnode->info = n;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (s->info > n)
    {
        s->left = create(s->left, n);
    }
    else
    {
        s->right = create(s->right, n);
    }
    return s;
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
int search(node *s, int n, node **p, node **xx)
{
    *p = NULL;
    while (s != NULL)
    {
        if (s->info == n)
        {
            *xx = s;
            return 1;
        }
        *p = s;
        if (n < s->info)
        {
            s = s->left;
        }
        else
        {
            s = s->right;
        }
    }
    return 0;
}
int delete(node *s, int n)
{
    node *parent, *xsucc;
    int r;
    if (s == NULL)
    {
        return 0;
    }
    r = search(s, n, &parent, &xsucc);
    if (r == 0)
    {
        return 0;
    }
    // 1. Node with two children
    if (xsucc->left != NULL && xsucc->right != NULL)
    {
        parent = xsucc;
        node *temp = xsucc->right;
        while (temp->left != NULL)
        {
            parent = temp;
            temp = temp->left;
        }
        xsucc->info = temp->info;
        xsucc = temp;
        parent->left = NULL; // Updated for the case of two children
    }
    // 2. Leaf node
    else if (xsucc->left == NULL && xsucc->right == NULL)
    {
        if (parent->left == xsucc)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    // 3. Left child
    else if (xsucc->left != NULL && xsucc->right == NULL)
    {
        if (parent->left == xsucc)
        {
            parent->left = xsucc->left;
        }
        else
        {
            parent->right = xsucc->left;
        }
    }
    // 4. Right child
    else if (xsucc->left == NULL && xsucc->right != NULL)
    {
        if (parent->left == xsucc)
        {
            parent->left = xsucc->right;
        }
        else
        {
            parent->right = xsucc->right;
        }
    }
    free(xsucc); // Free the memory of the deleted node
    return 1;
}
int main()
{
    node *root = NULL;
    int num, r;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the number :");
        scanf("%d", &num);
        clearbuffer();
        root = create(root, num);
        printf("Do you wish to continue (y/n):");
        scanf("%c", &another);
        clearbuffer();
    }
    printf("Enter the number you wish to delete:");
    scanf("%d", &num);
    clearbuffer();
    r = delete (root, num);
    if (r == 1)
    {
        printf("No. deleted\n");
        inorder(root);
    }
    else
    {
        printf("Number cannot be delted\n");
    }
}
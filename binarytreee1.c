#include <stdio.h>
#include<stdlib.h>
struct bintree
{
    int info;
    struct bintree *left, *right;
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
        newnode->info = n;
        newnode->right = newnode->left = NULL;
        return newnode;
    }
    else
    {
        if (n < s->info)
        {
            s ->left=insert(s->left, n);
        }
        else 
        {
            s-> right = insert(s->right, n);
        }
        return s;
    }
}
void inorder(node *s)
{
    if(s!=NULL)
    {
        inorder(s->left);
        printf("%d\n",s->info);
        inorder(s->right);
    }
}
void preorder(node *s)
{
    if( s!= NULL)
    {
        printf("%d\n",s->info);
        preorder(s->left);
        preorder(s->right);
    }
}
void postorder(node* s)
{
    if(s != NULL)
    {
        postorder(s->left);
        postorder(s->right);
        printf("%d\n",s->info);
    }
}
int main()
{
    node *root = NULL;
    int num;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the number : ");
        scanf("%d", &num);
        clearbuffer();
        root = insert(root, num);
        printf("Do you wish to continue (y/n):");
        scanf("%c", &another);
        clearbuffer();
    }
    printf("Inorder printing:\n");
    inorder(root);
    printf("Preorder printing:\n");
    preorder(root);
    printf("Postorder printing:\n");
    postorder(root);
    return 0;
}
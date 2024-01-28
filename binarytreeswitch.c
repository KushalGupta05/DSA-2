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
node *create(node *s, int n)
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
void preorder(node *s)
{
    if (s != NULL)
    {
        printf("%d\n", s->info);
        preorder(s->left);
        preorder(s->right);
    }
}
void postorder(node *s)
{
    if (s != NULL)
    {
        postorder(s->left);
        postorder(s->right);
        printf("%d\n", s->info);
    }
}
int summ(node *s)
{
    static int sum;
    if (s != NULL)
    {
        summ(s->left);
        sum = sum + s->info;
        summ(s->right);
    }
    return sum;
}
int countnodes(node *s)
{
    static int count;
    if (s != NULL)
    {
        countnodes(s->left);
        count++;
        countnodes(s->right);
    }
    return count;
}
int countleafs(node *s)
{
    static int leaf;
    if (s != NULL)
    {
        countleafs(s->left);
        if (s->right == NULL && s->left == NULL)
        {
            leaf++;
        }
        countleafs(s->right);
    }
    return leaf;
}
void freetree(node *s)
{
    if(s != NULL)
    {
        freetree(s->left);
        free(s);
        freetree(s->right);
    }
}
int main()
{
    node *root = NULL;
    int n, c, r = 0;
    char another = 'y';
    while (1)
    {
        printf("\nEnter the choice\n1)Create a tree:\n2)Print TREE:\n3)Sum of tree:\n4)Count Nodes\n5)Count leaf nodes:\n6)Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (r == 0)
            {
                while (another == 'y')
                {
                    printf("Enter the number :");
                    scanf("%d", &n);
                    clearbuffer();
                    root = create(root, n);
                    printf("Do you wish to continue(y/n):");
                    scanf("%c", &another);
                    clearbuffer();
                }
                r++;
            }
            printf("Tree created successfully\n");
            break;
        case 2:
            if (r == 1)
            {
                printf("Inoder printing:\n");
                inorder(root);
                printf("Preorder priting:\n");
                preorder(root);
                printf("Postorder printing:\n");
                postorder(root);
            }
            else
            {
                printf("Please create the tree\n");
            }
            break;
        case 3:
            if (r == 1)
            {
                printf("The sum of tree is %d\n", summ(root));
            }
            else
            {
                printf("Please create the tree\n");
            }
            break;
        case 4:
            if (r == 1)
            {
                printf("No of nodes is %d\n", countnodes(root));
            }
            else
            {
                printf("Please create the tree\n");
            }
            break;
        case 5:
            if (r == 1)
            {
                printf("No of leaf nodes is %d\n", countleafs(root));
            }
            else
            {
                printf("Please create the tree\n");
            }
            break;
        case 6:
            freetree(root);
            exit(0);
        default:
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
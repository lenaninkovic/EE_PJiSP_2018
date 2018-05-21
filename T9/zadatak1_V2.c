#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int value;
} node_t, *tree_t;

void preorder(tree_t tree)
{
    if (tree)
    {
        printf("%d\t", tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(tree_t tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%d\t", tree->value);
        inorder(tree->right);
    }
}

void reverse_order(tree_t tree)
{
    if (tree)
    {
        reverse_order(tree->right);
        printf("%d\t", tree->value);
        reverse_order(tree->left);
    }
}

void postorder(tree_t tree){

	if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t", tree->value);
    }
	
}

void insert(tree_t *tree, int value)
{
    if (*tree == NULL)
    {
        *tree = malloc(sizeof(node_t));
        (*tree)->value = value;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else if (value < (*tree)->value)
    {
        insert(&(*tree)->left, value);
    }
    else
    {
        insert(&(*tree)->right, value);
    }
}

void deltree(tree_t *tree)
{
    if (*tree != NULL)
    {
        deltree(&(*tree)->left);
        deltree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

int main()
{

    tree_t tree = NULL;
    insert(&tree, 8);
    insert(&tree, 5);
    insert(&tree, 9);
    insert(&tree, 6);
    insert(&tree, 4);

    preorder(tree);
    putchar('\n');

    inorder(tree);
    putchar('\n');

    reverse_order(tree);
    putchar('\n');
    
    postorder(tree);
    putchar('\n');

    deltree(&tree);
    return 0;
}



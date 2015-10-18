/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//print in preorder
void printPRE(TreeNode * current)
{
    if(current != NULL) {
        printf("%d\n",current->val);
        printf("<\n");
        printPRE(current->left);
        printf(">\n");
        printPRE(current->right);
    }
}

void print_tree(TreeNode *r, int l)
{
    int i;

    if(!r) return;
    //printf("%d\n", r->val);

    print_tree(r->left, l+1);
    for(i=0; i<l; ++i) printf(" ");
    //print_tree(r->right, l+1);

    printf("%d\n", r->val);
    print_tree(r->right, l+1);
}



void flatten(struct TreeNode *root)
{
    if(!root) return;

    if(root->left) flatten(root->left);
    if(root->right) flatten(root->right);

    struct TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while(root->right != NULL)
        root = root->right;
    root->right = tmp;
}



int main()
{
    TreeNode *root = malloc(sizeof(TreeNode));
    root->val = 1;

    root->left = malloc(sizeof(TreeNode));
    root->left->val = 2;

    root->left->left = malloc(sizeof(TreeNode));
    root->left->left->val =3;

    root->left->right = malloc(sizeof(TreeNode));
    root->left->right->val =4;

    root->right = malloc(sizeof(TreeNode));
    root->right->val =5;

    root->right->right = malloc(sizeof(TreeNode));
    root->right->right->val =6;
    printPRE(root);
    //print_tree(root,0);
    flatten(root);
    printf("after flatten\n");
    //printPRE(root);
    print_tree(root,0);
    return 0;
}

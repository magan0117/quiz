/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

void insert(TreeNode ** tree, TreeNode * item)
{
    if(!(*tree)) {
        *tree = item;
        return;
    }
    if(item->val<(*tree)->val)
        insert(&(*tree)->left, item);
    else if(item->val>(*tree)->val)
        insert(&(*tree)->right, item);
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
    srand(time(NULL));
    TreeNode *curr,*root;

    root = NULL;

    for(int i=1; i<=10; i++) {
        curr = (TreeNode *)malloc(sizeof(TreeNode));
        curr->left = curr->right = NULL;
        curr->val = rand()%100;
        insert(&root, curr);
    }


    printPRE(root);
    flatten(root);

    printf("after flatten\n");
    //printPRE(root);
    print_tree(root,0);
    return 0;
}

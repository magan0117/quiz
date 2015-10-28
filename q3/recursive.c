/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


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
    struct timespec start, end;
    double cpu_time1;
    root = NULL;

    for(int i=1; i<=10; i++) {
        curr = (TreeNode *)malloc(sizeof(TreeNode));
        curr->left = curr->right = NULL;
        curr->val = rand()%100;
        insert(&root, curr);
    }


    printPRE(root);
    clock_gettime(CLOCK_REALTIME, &start);
    flatten(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    printf("execution time of flatten() : %.9lf sec\n", cpu_time1);
//    printf("after flatten\n");
    //printPRE(root);
    print_tree(root,0);
    return 0;
}

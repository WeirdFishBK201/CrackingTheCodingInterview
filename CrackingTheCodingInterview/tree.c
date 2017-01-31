//
//  tree.c
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 2017/1/17.
//  Copyright © 2017年 WeirdFish. All rights reserved.
//

#include <stdlib.h>
#include "tree.h"

void _print_node(TreeNode*);
int _max_height(TreeNode*);
int _min_height(TreeNode*);
int _min(int, int);
int _max(int, int);

int _max(int a, int b) {
    return a > b ? a : b;
}

int _min(int a, int b) {
    return a < b ? a : b;
}

void _print_node(TreeNode* node)
{
    if (!node)
        return;
    printf("(%d", node->val);
    if (node->lchild)
        printf(", L: %d", node->lchild->val);
    if (node->rchild)
        printf(", R: %d", node->rchild->val);
    printf(")");
}

TreeNode* init_by_BFS(int* arr, size_t len)
{
    //head stores size of the tree.
    //true root is head[1]
    TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode) * len + 1);
    head->val = len;
    head->lchild = NULL;
    head->rchild = NULL;
    int i;
    for (i = 1; i <= len; i++) {
        head[i].val = arr[i - 1];
        if (2 * i > len)
            head[i].lchild = NULL;
        else
            head[i].lchild = &head[2 * i];
        if (2 * i + 1 > len)
            head[i].rchild = NULL;
        else
            head[i].rchild = &head[2 * i + 1];
    }
    return head;
}

void BFS_traversal(TreeNode* root)
{
    int i;
    printf("Tree in BFS:[ ");
    for (i = 0; i < root[0].val; i++){
        _print_node(&root[i + 1]);
        printf(", ");
    }
    printf("]\n");
}

//root, left, right
void preorder_traversal(TreeNode* root)
{
    static int is_head = 1;
    if (is_head) {
        root++;
        is_head = 0;
    }
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder_traversal(root->lchild);
    preorder_traversal(root->rchild);
}

//left, root, right
void inorder_traversal(TreeNode* root)
{
    static int is_head = 1;
    if (is_head) {
        root++;
        is_head = 0;
    }
    if (root == NULL)
        return;
    inorder_traversal(root->lchild);
    printf("%d ", root->val);
    inorder_traversal(root->rchild);
}

//left, right, root
void postorder_traversal(TreeNode* root)
{
    static int is_head = 1;
    if (is_head) {
        root++;
        is_head = 0;
    }
    if (root == NULL)
        return;
    postorder_traversal(root->lchild);
    postorder_traversal(root->rchild);
    printf("%d ", root->val);
}


/*
binary search tree
 */
TreeNode* bst(int* arr, size_t len)
{
    TreeNode *root = NULL;
    int i;
    for (i = 0; i < len; i++)
        bst_insert_node(&root, arr[i]);
    return root;
}

void bst_insert_node(TreeNode** root, int val)
{
    if (*root == NULL) {
        TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
        n->val = val;
        n->lchild = NULL;
        n->rchild = NULL;
        *root = n;
        return;
    }
    if (val > (*root)->val) bst_insert_node(&(*root)->rchild, val);
    else bst_insert_node(&(*root)->lchild, val);
}

void bst_preorder(TreeNode* root)
{
    if (root == NULL)
        return;
    _print_node(root);
    bst_preorder(root->lchild);
    bst_preorder(root->rchild);
}

int is_balanced(TreeNode* root)
{
    return _max_height(root) - _min_height(root) <= 1;
}

int _max_height(TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + _max(_max_height(root->lchild), _max_height(root->rchild));
}

int _min_height(TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + _min(_min_height(root->lchild), _min_height(root->rchild));
}

//
//  tree.h
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 2017/1/17.
//  Copyright © 2017年 WeirdFish. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct _Node {
    int val;
    struct _Node *lchild, *rchild;
} TreeNode;


TreeNode* init_by_BFS(int*, size_t);

//Traversal
void BFS_traversal(TreeNode*);
void preorder_traversal(TreeNode*);
void inorder_traversal(TreeNode*);
void postorder_traversal(TreeNode*);

//binary_search_tree
TreeNode* bst(int*, size_t);
void bst_insert_node(TreeNode**, int);
void bst_preorder(TreeNode*);
int is_balanced(TreeNode*); //4.1

#endif /* tree_h */

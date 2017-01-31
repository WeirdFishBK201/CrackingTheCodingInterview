//
//  linkedList.h
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 16/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#ifndef linkedList_h
#define linkedList_h

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

void init_with_array(int*, int);
void display_linked_list();
Node* new_node(int);
void push_node(Node*);

//2.3
void remove_node(Node*);

//2.1
void delete_duplicates();

//2.2
void nodes_from_nth(int);

//2.4
void add();

#endif /* linkedList_h */

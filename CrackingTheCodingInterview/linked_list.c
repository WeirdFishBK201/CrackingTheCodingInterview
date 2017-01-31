//
//  linkedList.c
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 16/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node* head = NULL;

void _init_head();


void _init_head()
{
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    //head's value stores size of the linked list
    head->value = 0;
}

//impletation
Node* new_node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}

void push_node(Node* node)
{
    if (!head)
        _init_head();
    Node* cursor = head;
    while (cursor->next)
        cursor = cursor->next;
    cursor->next = node;
}

void remove_node(Node* node)
{
    if (!node->next) {
        node = NULL;
        return;
    }
    node->value = node->next->value;
    Node* tmp = node->next;
    node->next = tmp->next;
    free(tmp);
// STUPID SOLUTION.
//    Node* cursor = head;
//    while (cursor && (cursor->next != node))
//        cursor = cursor->next;
//    if (cursor)
//        cursor->next = cursor->next->next;
}

void init_with_array(int* arr, int len)
{
    _init_head();
 
    int i = 0;
    Node* cursor = head;
    for (; i < len; i++) {
        cursor->next = new_node(arr[i]);
        cursor = cursor->next;
    }
    cursor->next = NULL;
    head->value = i;
}

void display_linked_list()
{
    if (!head) {
        printf("initilize first.\n");
        return;
    }
    Node* cursor = head;
    printf("Linked List: [");
    while ((cursor = cursor->next)) {
        printf("%d, ", cursor->value);
    }
    printf("]\n");
}

void delete_duplicates()
{
    Node* cursor = head, *dup = head;
    while (cursor->next) {
        while (dup->next) {
            dup = dup->next;
            if (dup->value == cursor->value)
                remove_node(dup);
        }
        cursor = cursor->next;
        dup = cursor;
    }
}

void nodes_from_nth(int n)
{
    if (!head) {
        printf("initilize first.\n");
        return;
    }
    int i = 0;
    Node* cursor = head;
    printf("the %dth to last element: [", n);
    while ((cursor = cursor->next)) {
        i++;
        if (i >= n)
            printf("%d, ", cursor->value);
    }
    printf("]");
}

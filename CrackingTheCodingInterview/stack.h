//
//  stack.h
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 2017/1/17.
//  Copyright © 2017年 WeirdFish. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>

typedef struct _STACK{
    int *arr;
    int top;
    size_t size;
} STACK;

void init_stack(STACK*, size_t);
void push(STACK*, int);
int pop(STACK*);
int peek(STACK*);
int isempty(STACK*);
int isfull(STACK*);
void sort(STACK*);
void display_stack(STACK*);

#endif /* stack_h */

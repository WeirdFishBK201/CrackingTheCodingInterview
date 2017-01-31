//
//  stack.c
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 2017/1/17.
//  Copyright © 2017年 WeirdFish. All rights reserved.
//

#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_stack(STACK *stack, size_t size)
{
    stack->size = size;
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
}

void push(STACK *s, int val)
{
    if (isfull(s)) {
        printf("stack is full.\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(STACK *s)
{
    if (isempty(s))
        return INT_MIN;
    return s->arr[(s->top)--];
}

int peek(STACK *s)
{
    if (isempty(s))
        return INT_MIN;
    return s->arr[s->top];
}

int isempty(STACK *s)
{
    return s->top == -1;
}

int isfull(STACK *s)
{
    return s->top == s->size - 1;
}

void display_stack(STACK* s)
{
    int i;
    printf("stack: [");
    while ( (i = pop(s)) != INT_MIN) {
        printf("%d, ", i);
    }
    printf("]");
}

void sort(STACK* src)
{
    STACK *tmp = (STACK*)malloc(sizeof(STACK));
    init_stack(tmp, src->size);
    int data, count;
    while (!isempty(src)) {
        data = pop(src);
        count = 0;
        while (!isempty(tmp) && data > peek(tmp)) {
            push(src, pop(tmp));
            count++;
        }
        push(tmp, data);
        while (count--)
            push(tmp, pop(src));
    }

    while (!isempty(tmp)) {
        push(src, pop(tmp));
    }
    free(tmp);
}

//
//  graph.h
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 19/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

//邻接矩阵实现Graph

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef struct _Graph {
    Node** adj;
    int V, E;
} Graph;

void graph(Graph*, int);
void add_edge(Graph*, int, int);
void g_display(Graph*);
//4.2
int has_route(Graph*, int, int);
#endif /* graph_h */

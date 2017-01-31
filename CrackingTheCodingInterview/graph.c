//
//  graph.c
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 19/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#include <stdlib.h>
#include "graph.h"

void graph(Graph* g, int v)
{
    g->V = v;
    //allocate and zero-initialize
    g->adj = (Node**)calloc(v, sizeof(Node*));
    g->E = 0;
}

//edge from v -> w
void add_edge(Graph* g, int v, int w)
{
    g->E++;
    Node* head = g->adj[v];
    if (!head) {
        printf("init\n");
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->value = w;
        g->adj[v] = head;
    }
    else {
        printf("exist\n");
        while (head->next)
            head = head->next;
        Node* n = (Node*)malloc(sizeof(Node));
        n->next = NULL;
        n->value = w;
        head->next = n;
    }
}

void g_display(Graph* g)
{
    printf("Graph: [%d, %d, ", g->V, g->E);
    int i = 0;
    Node* tmp = NULL;
    for (; i < g->V; i++) {
        printf("(%d: ", i);
        tmp = g->adj[i];
        while (tmp) {
            printf("%d, ", tmp->value);
            tmp = tmp->next;
        }
        printf("), ");
    }
    printf("]\n");
}

//check if there is a route from v1 to v2
int has_route(Graph* g, int v1, int v2) {
    Node* head = g->adj[v1];
    while (head) {
        if (head->value == v2)
            return 1;
        head = head->next;
    }
    return 0;
}

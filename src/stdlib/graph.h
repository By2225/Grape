#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// when the node already exists

struct Node *init_node(void *input);

struct Graph *init_graph();

struct Edge *init_edge(void *data);

void link_edge(struct Edge *e, struct Node *from, struct Node *to);

void link_edge_from(struct Node *from, struct Edge *e);

void link_edge_to(struct Node *to, struct Edge *e);

void add_node(struct Node *node, struct Graph *graph);

void add_edge(struct Edge *edge, struct Graph *graph);

void *get_val(struct Node *node);

struct Node *get_to(struct Edge *edge);

struct Node *get_from(struct Edge *edge);

struct List *get_outgoing2(struct Node *node, struct Graph *graph);

int GraphSize(struct Graph *graph);

bool GraphIsEmpty(struct Graph *graph);

struct List *GraphLeaves(struct Graph *graph);

struct List *GraphAdjacent(struct Node *node, struct Graph *graph);

void *node_get(struct Node *node);

void *edge_get(struct Edge *edge);

bool GraphFind(void *value, struct Graph *graph);

struct List *graph_to_list(struct Graph *graph);

struct List *neighbor(struct Node *node);

bool node_same(struct Node *a, struct Node *b);



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# include "types.h"

struct Graph *GraphInit(struct Graph *glist) {
	
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	initList(graph->nodes);
	return graph;
}

struct Node *GraphCreateNode(void *inputData, void *weight, struct Node *inputTo, struct Node *inputFrom) {
	
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	struct List *elist = (struct List *)malloc(sizeof(struct List));
	struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
	node->data = inputData;
	initList(elist);
	edge->data = weight;
	edge->to = inputTo;
	edge->from = inputFrom;
	addFront(elist, edge);

	return node;
}

// when the node already exists
void GraphAddEdge(struct Graph *graph, void *weight, struct Node *inputTo, struct Node *inputFrom, void *value) {
	
	struct ListNode *node = (graph->nodes)->head;
    while (node) {
		if (node->data == value) { // find the same node and add that edge
			struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
			struct Node *graphNode = node->data;
			edge->data = weight;
			edge->to = inputTo;
			edge->from = inputFrom;
			addFront(graphNode->edges, edge);
			break;
		} else {
			continue;
		}
		node = node->next;
	}
}
	
struct Graph *GraphAddNode(struct Graph *graph, struct Node *node) {
	
	addFront(graph->nodes, node);
	return graph;
}

int GraphSize(struct Graph *graph) {
	
	int graphSize = size(graph->nodes);	
	return graphSize;

}

/* decided to get rid of graph root
struct GraphNode *GraphRoot(struct Graph *graph) {
	
	return NULL;
}
*/

struct List *GraphLeaves(struct Graph *graph) {
	
	struct List *leavesList = (struct List *)malloc(sizeof(struct List));
	struct ListNode *target = (graph->nodes)->head;
	while (target) {
		struct Node *targetGraph = (struct Node *)(target->data);
		struct List *edges = targetGraph->edges;
		struct ListNode *tedge = edges->head;
		while (tedge) {
			struct Node *anode = ((struct Edge *)(tedge->data))->to;
			if (anode == NULL) {
				addFront(leavesList, anode);
				tedge = tedge->next;	
			}
		target = target->next;

		}
	}	
	return leavesList;
}

struct List *GraphAdjacent(struct Graph *graph, struct Node *node) {
	
	struct List *adjacentList = (struct List *)malloc(sizeof(struct List));
	struct ListNode *target = (graph->nodes)->head;
	while (target) {
		if (node->data == ((struct Node *)(target->data))->data) {
			struct Node *targetGraph = (struct Node *)(target->data);
			struct List *edges = targetGraph->edges;
			struct ListNode *tedge = edges->head;
			while (tedge) {
				struct Node *anode = ((struct Edge *)(tedge->data))->to;
				addFront(adjacentList, anode);
				tedge = tedge->next;	
			}
		}
		target = target->next;

	}
	return adjacentList;
}

bool GraphFind(struct Graph *graph, void *value) {

    struct ListNode *node = (graph->nodes)->head;
	
    while (node) {
		if (((struct Node *)(node->data))->data == value) {
			return true;
		}
		node = node->next;
	}

	return false;
}

bool GraphIsEmpty(struct Graph *graph) {
	
	return ((graph->nodes)->head == 0);
}

void GraphSwitch(struct Graph *graph, struct Node *node1, struct Node *node2) {

}

#ifndef GRAPH_H_INCLUDED_
#define GRAPH_H_INCLUDED_


#include <stdio.h>      /* printf */
#include <time.h>       /* clockt, clock, CLOCKSPERSEC */
#include <math.h>       /* sqrt ---- compile with -lm flag  */
#include <stdlib.h>     /* rand, srand , malloc*/

#include "Assignment_6.h"

typedef struct Vert_ListNode Node;
typedef struct Graph	Graph_Node;

Node *HeadNode, *PreviousNode, *CurrentNode;
Graph_Node *Current_Graph_Node;

// A structure to represent an adjacency list node
struct Vert_ListNode
{
	int dest;
	struct Vert_ListNode* previous;
	struct Vert_ListNode* next;
};

// A structure to represent HEAD NODE or adjency list
struct Vert_List
{
	struct Vert_ListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
	int V;
	struct Vert_List* array;
};

// A utility function to create a new adjacency list node
struct Vert_ListNode* newVert_ListNode(int dest);

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V);
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest);
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph);
int graph_insert_edge(Graph_Node *graph, int source, int destination);
Node* graph_insert_vertex(int destination);
#endif 
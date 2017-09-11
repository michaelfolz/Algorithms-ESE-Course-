#include "Graph.h"
/*
Credit goes to the following websites whom I used for refrence
	http://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Graphs.html
	https://www.cs.bu.edu/teaching/c/graph/linked/
	http://www.geeksforgeeks.org/graph-and-its-representations/
*/

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	int i;
	Current_Graph_Node = (struct Graph*) malloc(sizeof(struct Graph));
	Current_Graph_Node->V = V; // store the total number of vertexs in the main graph

	// Create an array of verticies.  Size of array will be V
	Current_Graph_Node->array = (struct Vert_List*) malloc(V * sizeof(struct Vert_List));

	// Initialize each adjacency list as empty by making head as NULL

	for (i = 0; i < V; ++i){
		Current_Graph_Node->array[i].head = NULL;
	}

	return Current_Graph_Node;
}

int graph_insert_edge(Graph_Node *graph, int source, int destination)
{
	int chk_src = 0;
	int chk_Vert_List = 0;
	// no sence making connections to itslef 
	if (source == destination)
		return 1;
	//Search through current source Node for destination if connection exists in current src
	// no need to recreate connection 

	CurrentNode = graph->array[source].head;

	for (; CurrentNode != NULL; CurrentNode = CurrentNode->next){
		chk_Vert_List++;
		chk_src = CurrentNode->dest;

		// Create no connection if destination == source or if links >= 6
		if (destination == chk_src || chk_Vert_List >= 6)
			return 1;
	}


	// Add an edge from src to dest.  A new node is added to the adjacency
	// list of src.  The node is added at the begining

	CurrentNode = graph_insert_vertex(destination);
	CurrentNode->next = graph->array[source].head;
	graph->array[source].head = CurrentNode;

	return 0;
}

// Print the Entire graph, one vertex at a time
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		CurrentNode = graph->array[v].head;

		printf("\n Vertex:  %d\n ---------------------------------------\n head ", v);
		while (CurrentNode != NULL)
		{
			printf("-> %d", CurrentNode->dest);
			CurrentNode = CurrentNode->next;
		}
		printf("\n");
	}
}

Node* graph_insert_vertex(int destination){
	CurrentNode =(struct Vert_ListNode*) malloc(sizeof(struct Vert_ListNode));
	CurrentNode->dest = destination;
	CurrentNode->next = NULL;
	CurrentNode->previous = NULL; // not used or necessary  
	return CurrentNode;
}



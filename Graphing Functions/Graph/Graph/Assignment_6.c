#include "Assignment_6.h"

/*

1.	[10] Implement the Graph ADT functions
void graph_init(Graph *graph); // initialize graph
int graph_insert_vertex(Graph *graph, Item data);
int graph_insert_edge(Graph *pg, Item v1, Item v2);

you will probably also want to implement
int graph_is_adjacent(Graph *pg, Item v1, Item v2)
static void graph_destroy( Graph *g )
using either an adjacency list or array.


2.	[10] Place N (at least 100) nodes into the graph, and connect each of them (randomly) to between 2 and 6 other nodes (depending on how you do this, more or fewer may result – that’s okay)
3.	[5] Print out the adjacency information for each node
*/


void Assignment_6(void){
	const int Random_Connection_Array[6];
	int count = 0;
	int node_count = 0; 
	int Connected_Nodes;
	time_t t;
	/// Create the Graph (this creates the array of all possible verticies as well
	struct Graph* graph = createGraph(NODE_MAX);
	// seed rand with time 
	srand((unsigned)time(&t));

	/// go through all nodes 0-99
	for (node_count = 0; node_count < NODE_MAX; node_count++){
		// Function retuns number of random numbers generated, number is limited between 2 & 6 
		Connected_Nodes = Rand_Array(Random_Connection_Array);

		// Loop for that number create an edge
		for (count = 0; count < (Connected_Nodes-1); count++)
		{
			/// add an edge for each value in the random connection array// 
			printf("\nadding connection: %d -> %d", node_count, Random_Connection_Array[count] );
			graph_insert_edge(graph, node_count, Random_Connection_Array[count]); 

		}
	}

	// print the adjacency list representation of the above graph
	printGraph(graph);

	return;
}

int Rand_Array(int Random_Connection_Array[]){

	int Random_Number = 0;
	int Random_Nodes_Connected = 0;
	int Random_Connection = 0;
	int count = 0;
	
	Random_Nodes_Connected = RandomNumberGenerate(CONNECT_MIN, CONNECT_MAX);
//	printf(" 0x%x ", Random_Nodes_Connected);
	//printf("\n Randle: "); 
	for (count = 0; count < (Random_Nodes_Connected - 1); count++){
		Random_Connection_Array[count] = RandomNumberGenerate(0, NODE_MAX);
		//printf(" %d ", Random_Connection_Array[count]); 
	}

	return Random_Nodes_Connected;
}

unsigned int RandomNumberGenerate(unsigned int RandomValMin, unsigned int RandomValMax)
{
	unsigned int RandomNumber = 0;

	RandomNumber = ((unsigned int)rand() % RandomValMax) + RandomValMin;

	return (RandomNumber);
}

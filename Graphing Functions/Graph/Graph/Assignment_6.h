#ifndef ASSIGNMENT_6_H_INCLUDED_
#define ASSIGNMENT_6_H_INCLUDED_


#include <stdio.h>      /* printf */
#include <time.h>       /* clockt, clock, CLOCKSPERSEC */
#include <math.h>       /* sqrt ---- compile with -lm flag  */
#include <stdlib.h>     /* rand, srand , malloc*/

#define CONNECT_MAX	6
#define CONNECT_MIN 2
#define NODE_MAX	10

void Assignment_6(void);
int Rand_Array(int Random_Connection_Array[]);
int Create_Nodes(int Number_of_Nodes);
unsigned int RandomNumberGenerate(unsigned int RandomValMin, unsigned int RandomValMax);


#endif 
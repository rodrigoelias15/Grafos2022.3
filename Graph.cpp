#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{

    return this->order;
}
int Graph::getNumberEdges()
{

    return this->number_edges;
}

bool Graph::getDirected()
{

    return this->directed;
}

bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

bool Graph::getWeightedNode()
{

    return this->weighted_node;
}

Node *Graph::getFirstNode()
{

    return this->first_node;
}

Node *Graph::getLastNode()
{

    return this->last_node;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id)
{
    bool v=searchNode(id);
    if(v==false)
    {
    Node* n = new Node(id);
    Node* aux = this->last_node;
    aux->setNextNode(n);
    this->last_node=n;
    n->setPreviousNode(aux);
    }
    else
    cout<<"Id ja tem";
}

void Graph::insertEdge(int id, int target_id, float weight)
{

    
}

void Graph::removeNode(int id)
{ 
    Node* n = getNode(id);
    Node *auxp, *auxn;
    auxp = n->getPreviousNode();
    auxn = n->getNextNode();
    auxp->setNextNode(auxn);
    auxn->setPreviousNode(auxp);
}

bool Graph::searchNode(int id)
{
    Node *n= this->first_node;
    while(n!=nullptr)
    {
        if(n->getId()==id)
        return true;
        else
        n=n->getNextNode();
    }
    return false;
}

Node *Graph::getNode(int id)
{
    Node *n= this->first_node;
    while(n!=nullptr)
    {
        if(n->getId()==id)
        return n;
        else
        n=n->getNextNode();
    }
    return nullptr;
    
}


//Function that verifies if there is a path between two nodes
bool Graph::depthFirstSearch(int initialId, int targetId)
{
    return false;
}


void Graph::breadthFirstSearch(ofstream &output_file)
{
    
}


Graph *Graph::getComplement()
{
    return nullptr;
}

    

//A function that returns a subjacent of a directed graph, which is a graph which the arcs have opposite directions to the original graph
Graph* Graph::getSubjacent(){
    
}

bool Graph::connectedGraph(){
    return false;
}



bool Graph::hasCircuit(){
    return false;
}



float** Graph::floydMarshall(){
    
}

   

float* Graph::dijkstra(int id){
    
}

#pragma once

#include <iostream>
#include <vector>	
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using std::vector;
using std::ifstream;
using std::cout;
using std::pair;
using std::queue;
using std::stack;
using std::multimap;
using std::map;
using std::endl;
using std::cin;


typedef pair<int, vector<int>> vertex;
typedef vector<vertex> graph;

// The main menu for the program, returns the operation the user would like
int getChoice();

// Returns an iterator for a user chosen node in the graph
graph::iterator getVertexChoice(graph& adjList);

// Imports the user data from github-graph_V1.0.txt into the graph  
void importGraph(graph &adjList);

// returns an iterator to a node v in the graph
graph::iterator getVertex(graph& adjList, int v);

// Adds a pair of followers/following to the graph
void addEdge(graph &adjList, int u, int v);

// Prints out the current structure of the graph
void printGraph(graph &adjList);

// Prints out the path stack that returns from the shortest path function
void printPath(stack<int> path);

// Returns a multimap of users so that they are sorted by followers
multimap<int, int> topUsers(graph& adjList);

// Gets the top 10 followed users in the graph using topUsers and prints them out
void topTen(graph& adjList);

// Gets the in degree of a user
int inDegree(graph &adjList, int user);

// Gets the out degree of a user
int outDegree(graph &adjList, int user);

// Returns the median followers in the graph
double medianConnections(graph& adjList);

// Returns the average followers in the graph
double averageConnections(graph& adjList);

// Returns the path length and a stack of the path taken from user1 to user2
pair<int, stack<int>> shortestPath(graph& adjList, int user1, int user2);

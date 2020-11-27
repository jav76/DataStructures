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


typedef pair<int, vector<int>> vertex;
typedef vector<vertex> graph;


void importGraph(graph &adjList);

graph::iterator getVertex(graph& adjList, int v);

void addEdge(graph &adjList, int u, int v);

void printGraph(graph &adjList);

//multimap<int, int> topUsers(graph& adjList);

//void topTen(graph& adjList);

int inDegree(graph &adjList, int user);

int outDegree(graph &adjList, int user);

double medianConnections(graph& adjList);

double averageConnections(graph& adjList);

pair<int, stack<vertex>> shortestPath(graph& adjList, int user1, int user2);

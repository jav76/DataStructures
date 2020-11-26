#pragma once

#include <iostream>
#include <vector>	
#include <fstream>
#include <iomanip>
#include <algorithm>

using std::vector;
using std::ifstream;
using std::cout;
using std::pair;

typedef pair<int, vector<int>> vertex;
typedef vector<vertex> graph;


void importGraph(graph &adjList);

void addEdge(graph &adjList, int u, int v);

void printGraph(graph adjList);

int inDegree(graph adjList, int user);

int outDegree(graph adjList, int user);
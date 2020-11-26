#include "graph.h"


void importGraph(graph &adjList)
{
	ifstream file;
	file.open("github-graph_V1.0.txt", std::ios::in);
	if (file.is_open())
	{
		cout << "Importing data...\n";
		std::string f;
		file >> f >> f;
		int u, v;
		while (file >> u >> v)
		{
			addEdge(adjList, u, v);
		}
	}
	else
	{
		cout << "Error reading file";
	}
}

graph::iterator getVertex(graph &adjList, int v)
{
	graph::iterator it = adjList.begin();
	for (it; it != adjList.end(); ++it)
	{
		if (it->first == v)
		{
			return it;
		}
	}
	return it;
}

void addEdge(graph &adjList, int u, int v)
{
	graph::iterator it = getVertex(adjList, u);
	if (it != adjList.end())
	{
		it->second.push_back(v);
	}
	else
	{
		pair<int, vector<int>> newVertex;
		newVertex.first = u;
		newVertex.second.push_back(v);
		adjList.push_back(newVertex);
	}
}

void printGraph(graph adjList)
{
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		cout << "\nVertex " << it->first << ":\n";
		for (vector<int>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
		{
			if (vit != it->second.begin())
			{
				cout << " -> ";
			}
			cout << *vit;
		}
	}
}


int inDegree(graph adjList, int user)
{
	int count = 0;
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		for (vector<int>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
		{
			if (*vit == user)
			{
				++count;
			}
		}
	}
	return count;
}

int outDegree(graph adjList, int user)
{
	int count = 0;
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		if (it->first == user)
		{
			count = it->second.size();
		}
	}
	return count;
}

#include "graph.h"


void importGraph(graph &adjList)
{
	ifstream file;
	file.open("github-graph_V1.0 - Copy.txt", std::ios::in);
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

void printGraph(graph &adjList)
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

multimap<int, int> topUsers(graph& adjList)
{
	multimap<int, int> ranks; // Rank users by connections {connections, user}
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		int connections = inDegree(adjList, it->first) + outDegree(adjList, it->first);
		ranks.insert({ connections, it->first }); 
	}
	return ranks;
}

void top10(graph& adjList)
{
	multimap<int, int> ranks = topUsers(adjList);
	for (multimap<int, int>::reverse_iterator it = ranks.rbegin(); it != ranks.rbegin() + 10; ++it)
	{
		cout << std::endl << it->first << " " << it->second;
	}
}

int inDegree(graph &adjList, int user)
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

int outDegree(graph &adjList, int user)
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

double medianConnections(graph& adjList)
{
	vector<int> connectionsList;
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		connectionsList.push_back(inDegree(adjList, it->first) + outDegree(adjList, it->first));
	}
	std::sort(connectionsList.begin(), connectionsList.end());
	
	if (connectionsList.size() % 2 == 0)
	{
		int low = connectionsList[floor(connectionsList.size() / 2.0)];
		int high = connectionsList[ceil(connectionsList.size() / 2.0)];
		return (low + high) / 2.0;
	}
	else
	{
		return connectionsList[ceil(connectionsList.size() / 2.0)];
	}
}

double averageConnections(graph& adjList)
{
	int sum = 0;
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		sum = sum + inDegree(adjList, it->first) + outDegree(adjList, it->first);
	}
	return (sum / double(adjList.size()));
}

pair<int, stack<vertex>> shortestPath(graph& adjList, int user1, int user2)
{
	pair<int, stack<vertex>> result;
	graph::iterator v1 = getVertex(adjList, user1);
	if (v1 == adjList.end())
	{
		cout << "Node " << user1 << " does not exist in the graph.\n";
		result.first = -1;
		return result;
	}
	graph::iterator v2 = getVertex(adjList, user2);
	if (v2 == adjList.end())
	{
		cout << "Node " << user2 << " does not exist in the graph.\n";
		result.first = -1;
		return result;
	}
	
	vector<int> visitedList;
	vertex current = *v1;

	int count = 0;
	bool found = false;
	queue<vertex> q;
	stack<vertex> path;

	q.push(current);
	do
	{
		current = q.front();
		path.push(current);
		q.pop();
		cout << "\nCurrent: " << current.first;
		if (current.first == user2)
		{
			found = true;
		}
		else
		{
			++count;
			visitedList.push_back(current.first);
			for (vector<int>::iterator it = current.second.begin(); it != current.second.end(); ++it)
			{
				graph::iterator toQueue;
				toQueue = getVertex(adjList, *it);
				if (toQueue != adjList.end())
				{ 
					bool visited = false;
					for (vector<int>::iterator mit = visitedList.begin(); mit != visitedList.end(); ++mit)
					{
						if (toQueue->first == *mit)
						{
							visited = true;
						}
					}
					if (visited == false)
					{
						q.push(*toQueue);
					}
				}
			}
		}
	} while (!q.empty() && !found);
	result.first = count;
	result.second = path;
	return result;
}

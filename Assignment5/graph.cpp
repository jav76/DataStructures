#include "graph.h"

int getChoice()
{
	cout << endl;
	cout << "1) Get the top 10 most connected users in the graph\n";
	cout << "2) Get the median connections in the graph\n";
	cout << "3) Get the average connections in the graph\n";
	cout << "4) Get the shortest path between two nodes in the graph\n";
	cout << "5) Get the in-degree of a node in the graph\n";
	cout << "6) Get the out-degree of a node in the graph\n";
	cout << "7) Print the graph\n";
	cout << "8) Quit\n";
	cout << "Select your option: ";

	int choice;
	cin >> choice;
	while (cin.fail() || choice < 1 || choice > 11)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Invalid option. Please try again.\n";
		cin >> choice;
	}
	return choice;
}

graph::iterator getVertexChoice(graph& adjList)
{
	cout << endl;
	cout << "Enter your node choice: ";
	int choice;
	cin >> choice;
	graph::iterator vertex = getVertex(adjList, choice);
	while (cin.fail() || vertex == adjList.end())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Invalid option/node does not exist. Please try again.\n";
		cin >> choice;
		vertex = getVertex(adjList, choice);
	}
	return vertex;
}

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

void printGraph(graph &adjList)
{
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		cout << "\nNode " << it->first << ":\n";
		for (vector<int>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
		{
			if (vit != it->second.begin())
			{
				cout << "  ";
			}
			cout << *vit;
		}
	}
	cout << "\nNumber of users: " << adjList.size() << endl;
}

void printPath(stack<int> path)
{
	int pathSize = path.size();
	for (int i = 0; i < pathSize; ++i)
	{
		int current = path.top();
		path.pop();
		//cout << "i: " << i << " empty?: " << path.second.empty() << " size: " << path.second.size() << endl;
		if (path.empty())
		{
			cout << current << endl;
		}
		else
		{
			cout << current << " -> ";
		}
	}
}

multimap<int, int> topUsers(graph& adjList)
{
	multimap<int, int> ranks; // Rank users by connections {connections, user}
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		int connections = inDegree(adjList, it->first);
		ranks.insert({ connections, it->first }); 
	}
	return ranks;
}


void topTen(graph& adjList)
{
	multimap<int, int> ranks = topUsers(adjList);
	multimap<int, int>::reverse_iterator it = ranks.rbegin();
	for (int i = 0; i < 10; ++i)
	{
		int userID = it->second;
		int connections = it->first;
		cout << "\n#" << i + 1 << ": User " << userID << " has " << connections << " connections.";
		++it;
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
		connectionsList.push_back(inDegree(adjList, it->first));
	}
	std::sort(connectionsList.begin(), connectionsList.end());
	
	if (connectionsList.size() % 2 == 0)
	{
		double low = connectionsList[floor(connectionsList.size() / 2.0)];
		double high = connectionsList[ceil(connectionsList.size() / 2.0)];
		return (low + high) / 2.0;
	}
	else
	{
		return connectionsList[ceil(connectionsList.size() / 2.0)];
	}
}

double averageConnections(graph& adjList)
{
	double sum = 0;
	for (graph::iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		sum = sum + inDegree(adjList, it->first);
	}
	return (sum / double(adjList.size()));
}


pair<int, stack<int>> shortestPath(graph& adjList, int user1, int user2)
{
	pair<int, stack<int>> result;
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
	
	map<int, bool> visitedList;
	vertex current = *v1;

	int count = 0;
	bool found = false;
	queue<vertex> q;
	map<int, int> parents;

	q.push(current);
	do
	{
		current = q.front();
		q.pop();
		if (current.first == user2)
		{
			found = true;
		}
		else
		{
			for (vector<int>::iterator it = current.second.begin(); it != current.second.end(); ++it)
			{
				graph::iterator toQueue;
				toQueue = getVertex(adjList, *it);
				if (toQueue != adjList.end())
				{ 
					if (!visitedList[toQueue->first])
					{
						parents[toQueue->first] = current.first;
						visitedList[toQueue->first] = true;
						q.push(*toQueue);
					}
				}
			}
		}
	} while (!q.empty() && !found);

	if (!found)
	{
		result.first = -1;
		return result;
	}

	int index = user2;
	result.second.push(user2);
	while (parents[index] != user1)
	{
		result.second.push(parents[index]);
		index = parents[index];
		++count;
	}
	result.second.push(user1);
	result.first = count;
	return result;
}

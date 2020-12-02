/*
Data structures 3460:316
Assignment 5
Jaret Varn, jav76@zips.uakron.edu

This program imports data containing followed users into a graph. 
The program can then using the graph find the top 10 followed users, median number of followers, average number of followers,
the shortest path from one user to another through followers, and in/out degree of any user.

*/


#include "graph.h"

int main()
{
    graph adjList;

    importGraph(adjList);
    
    while (true)
    {
        int choice = getChoice();
        switch (choice)
        {
            case 1:
            {
                topTen(adjList);
                break;
            }

            case 2:
            {
                cout << "\nMedian connections in the graph: " << medianConnections(adjList);
                break;
            }

            case 3:
            {
                cout << "\nAverage connections in the graph: " << averageConnections(adjList);
                break;
            }

            case 4:
            {
                graph::iterator node1 = getVertexChoice(adjList);
                graph::iterator node2 = getVertexChoice(adjList);
                pair<int, stack<int>> path = shortestPath(adjList, node1->first, node2->first);
                if (path.first != -1)
                {
                    cout << "Path found from " << node1->first << " to " << node2->first << " in " << path.first << " steps\n";
                    printPath(path.second);
                }
                else
                {
                    cout << "Path from " << node1->first << " to " << node2->first << " does not exist\n";
                }
                break;
            }

            case 5:
            {
                graph::iterator node = getVertexChoice(adjList);
                cout << "In degree of " << node->first << " : " << inDegree(adjList, node->first);
                break;
            }

            case 6:
            {
                graph::iterator node = getVertexChoice(adjList);
                cout << "Out degree of " << node->first << " : " << outDegree(adjList, node->first);
                break;
            }

            case 7:
            {
                printGraph(adjList);
                break;
            }

            case 8:
            {
                return 0;
            }
        }
    }
    return 0;
}


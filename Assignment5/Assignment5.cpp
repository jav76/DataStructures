#include "graph.h"

int main()
{
    graph adjList;

    importGraph(adjList);
    printGraph(adjList);

    cout << "\nIn degree of 3: " << inDegree(adjList, 3);
    cout << "\nOut degree of 3: " << outDegree(adjList, 3);
    return 0;
}


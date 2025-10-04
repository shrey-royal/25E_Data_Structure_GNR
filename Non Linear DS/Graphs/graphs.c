#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10

int graph[MAX_NODES][MAX_NODES];
int numNodes;
int visited[MAX_NODES];

void addEdge(int from, int to, int weight) {
    graph[from][to] = weight;
    graph[to][from] = weight;   // undirected
}

void initializeGraph() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph (from to weight, -1 to stop): ");
    int from, to, weight;
    while(1) {
        scanf("%d %d %d", &from, &to, &weight);
        if (from == -1 || to == -1 || weight == -1) break;
        addEdge(from, to, weight);
    }
}

void bfs(int startNode) {
    int queue[MAX_NODES], front = 0, rear = 0;

    queue[rear++] = startNode;
    visited[startNode] = 1;

    printf("BFS Traversal: ");
    while(front < rear) {
        int currentNode = queue[front++];
        printf("%d -> ", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\b\b\b\b    \n");
}

void dfs(int currentNode) {
    visited[currentNode] = 1;
    printf("%d -> ", currentNode);

    for (int i = 0; i < numNodes; i++) {
        if(graph[currentNode][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void printGraph() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int startNode;
    initializeGraph();

    printGraph();

    // printf("Enter the starting node for BFS: ");
    // scanf("%d", &startNode);
    // for (int i = 0; i < numNodes; i++) {
    //     visited[i] = 0;
    // }
    // bfs(startNode);

    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }
    dfs(startNode);


    return 0;
}
/*
4
0 1 1
0 2 1
1 2 1
2 3 1
-1 -1 -1

  0 1 2 3
0 0 1 1 0 
1 1 0 1 0 
2 1 1 0 1 
3 0 0 1 0
*/
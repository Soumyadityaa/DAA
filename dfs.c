#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n = 5; // number of vertices
int graph[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};
int visited[MAX] = {0};

// Recursive DFS function
void DFS_Recursion(int source) {
    printf("%c ", 'A' + source);
    visited[source] = 1; // mark as visited
    for (int i = 0; i < n; i++) {
        if (graph[source][i] && !visited[i]) {
            DFS_Recursion(i);
        }
    }
}

int main() {
   
    DFS_Recursion(0);
            
    return 0;
}

#include <stdio.h>

#define MAX 100

int n = 5; // Number of vertices
int graph[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

// Queue
int queue[MAX] = {0};
int front = -1, rear = -1;

int isEmpty() {
    return front > rear || front == -1;
}

void insert(int element) {
    if (front == -1) {
        front++;
    }
    rear++;
    queue[rear] = element;
}

void removeElement() {
    front++;
}

int top() {
    return queue[front];
}

void BFS(int source) {
    int visited[MAX] = {0}; // to track the vertices
    insert(source);
    printf("%c ", 'A' + source);
    visited[source] = 1; // mark as visited
    while (!isEmpty()) {
        int currNode = top();
        removeElement();
        for (int i = 0; i < n; i++) {
            // edge is available and not visited till now
            if (graph[currNode][i] && !visited[i]) {
                insert(i);
                printf("%c ", 'A' + i);
                visited[i] = 1; // mark as visited
            }
        }
    }
}

int main() {
    BFS(0);
    return 0;
}

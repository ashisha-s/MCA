#include <stdio.h>

#define MAX 100  // maximum number of vertices

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

int pop() {
    if (top == -1)
        return -1; // stack empty
    else
        return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// DFS function using stack
void dfs(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    push(start);

    while (!isEmpty()) {
        int node = pop();

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        // Push all unvisited adjacent vertices (reverse order for consistent traversal)
        for (int j = n - 1; j >= 0; j--) {
            if (graph[node][j] == 1 && !visited[j]) {
                push(j);
            }
        }
    }
}

int main() {
    int n; // number of vertices
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d:\n", start);
    dfs(graph, visited, n, start);

    return 0;
}

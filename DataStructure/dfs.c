#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1)
        return -1;  // Stack empty
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}

// Iterative DFS function
void DFS(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    push(start);

    while (!isEmpty()) {
        int node = pop();

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;

            // Push adjacent vertices (in reverse order for consistent output)
            for (int j = n - 1; j >= 0; j--) {
                if (graph[node][j] == 1 && !visited[j]) {
                    push(j);
                }
            }
        }
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("\nDFS Traversal starting from vertex %d:\n", start);
    DFS(graph, visited, n, start);

    printf("\n");
    return 0;
}



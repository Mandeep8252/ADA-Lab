#include <stdio.h>

#define MAX 10

int main() {
    int n;
    int graph[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("\nTopological Ordering:\n");

    for (int count = 0; count < n; count++) {

        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0 && !visited[i]) {

                printf("%d ", i);
                visited[i] = 1;

                // Remove outgoing edges
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1)
                        indegree[j]--;
                }

                break;
            }
        }
    }

    printf("\n");

    return 0;
}

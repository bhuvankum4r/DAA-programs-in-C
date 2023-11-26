#include <stdio.h>
#define INF 9999 // Use a larger value for infinity
int n, c[20][20], visited[20];
void prims() {
    int a, b, min, cost = 0, i, j, count = 0;
    min = INF; // Initialize min to a large value
    printf("\n The minimal spanning tree is: \n");
    visited[1] = 1;
    while (count < (n - 1)) {
        min = INF; // Reset min for each iteration
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (visited[i] && (!visited[j]) && min > c[i][j]) {
                    min = c[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        printf("\n %d --> %d = %d ", a, b, c[a][b]);
        cost += c[a][b];
        visited[b] = 1;
        count++;
    }
    printf("\n The Total cost is : %d ", cost);
}
int main() {
    int i, j;
    printf("\n Enter the no. of vertices : ");
    scanf("%d", &n);
    printf("\n Enter the cost adjacency matrix : \n ");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
        visited[i] = 0; // Initialize visited array inside the loop
    }
    prims();
    return 0; // Return a value from main
}

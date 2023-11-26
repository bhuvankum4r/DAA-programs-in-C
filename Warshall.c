#include <stdio.h>

void main() {
    int i, j, k, n, a[10][10];
    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
    printf("\n The transitive closure is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}

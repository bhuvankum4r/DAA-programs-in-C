#include <stdio.h>
#include <stdlib.h>
int cost[10][10], a[10][10];
int min(int a, int b) {
    return (a < b) ? a : b;
}
void all_paths(int cost[10][10], int a[10][10], int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            a[i][j] = cost[i][j];
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}
int main() {
    int i, j, n;
    printf("\n Enter no. of vertices : ");
    scanf("%d", &n);
    printf("\n Enter adjacency matrix : \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    all_paths(cost, a, n);
    printf("\n\t The shortest path obtained is : \n ");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


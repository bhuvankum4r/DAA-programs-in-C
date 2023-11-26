#include <stdio.h>

void read_adjacency_matrix(int a[10][10], int n) {
    int i, j;
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void find_indegree(int a[10][10], int n, int indegree[10]) {
    int i, j, sum;
    for (j = 0; j < n; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        indegree[j] = sum;
    }
}

void topological_order(int a[10][10], int n) {
    int u, v, i, s[10], t[10], top = -1, k = 0, indegree[10];
    find_indegree(a, n, indegree);
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            s[++top] = i;
        }
    }
    while (top != -1) {
        u = s[top--];
        t[k++] = u;
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    s[++top] = v;
                }
            }
        }
    }
    printf("\n\nThe topological order is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
}

int main() {
    int a[10][10], n;
    printf("Enter the number of vertices in the matrix: ");
    scanf("%d", &n);
    read_adjacency_matrix(a, n);
    topological_order(a, n);
    return 0;
}

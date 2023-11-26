#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int x[], int low, int high) {
    int i, j, temp, pivot;
    if (low < high) {
        pivot = low;
        i = low;
        j = high;
        while (i < j) {
            while (x[i] <= x[pivot] && i < high) {
                i++;
            }
            while (x[j] > x[pivot]) {
                j--;
            }
            if (i < j) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
        temp = x[pivot];
        x[pivot] = x[j];
        x[j] = temp;
        quicksort(x, low, j - 1);
        quicksort(x, j + 1, high);
    }
}

int main() {
    clock_t start, end;
    int x[500], size, i;
    printf("\n Enter the array size : ");
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        x[i] = rand() % 200;
    }
    printf("\n The random generated array is : \n ");
    for (i = 0; i < size; i++) {
        printf("\t %d", x[i]);
    }
    start = clock();
    quicksort(x, 0, size - 1);
    end = clock();
    printf("\n The Sorted Array is : \n ");
    for (i = 0; i < size; i++) {
        printf("\t %d", x[i]);
    }
    printf("\n \n The time the program executed was : %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

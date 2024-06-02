#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main() {
    int a[6] = {12, 54, 1, 6, 2, 23};
    int count = 6;

    quicksort(a, 0, count - 1);

    printf("quicksorted array: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

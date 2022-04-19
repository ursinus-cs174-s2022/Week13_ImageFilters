#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Return true if x < y
 * 
 * @param x First number
 * @param y Second number
 */
int compareLess(double x, double y) {
    return x < y;
}

/**
 * @brief Return true if x > y
 * 
 * @param x First number
 * @param y Second number
 */
int compareGreater(double x, double y) {
    return x > y;
}

void swap(double* arr, int i, int j) {
    double temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * @brief Sort the elements of an array
 * 
 * @param arr Array to sort
 * @param N Length of array
 * @param cmp A method that compare two elements and returns true
 *            if the first one is supposed to go before the second one
 */
void sort(double* arr, int N, int(*cmp)(double, double)) {
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j >= 1 && cmp(arr[j], arr[j-1])) {
            swap(arr, j, j-1);
            j--;
        }
    }
}

void printArray(double* arr, int N) {
    for (int i = 0; i < N; i++) {
        printf("%g ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N = 20;
    double x[20] = {56, 22, 23, 34, 32, 40, 92, 69, 54, 99, 83, 17, 81, 30, 44, 48, 97, 73, 48, 99};
    int(*comparators[2])(double, double) = {&compareLess, &compareGreater};
    for (int i = 0; i < 2; i++) {
        sort(x, N, comparators[i]);
        printArray(x, N);
    }
    return 0;
}
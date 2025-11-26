#include <stdio.h>

// funktsiia pidrakhunku kilkosti elementiv kratnykh 5
int count_multiples_of_5(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

// main
int main(void) {
    // statychnyi masyv z fiksovanym rozmirom
    int arr[] = {10, 3, 25, 7, 40, 13, 5, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vyvid masyvu
    printf("Array elements:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // vyklyk funktsii
    int result = count_multiples_of_5(arr, size);
    printf("Number of elements divisible by 5: %d\n", result);

    return 0;
}

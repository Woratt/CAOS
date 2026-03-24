#include <stdio.h>

int process_data(int* arr, int size, int threshold);

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int threshold = 25;

    printf("--First arr--\n");
    for(int i = 0; i < size; ++i){
        printf("%d\n", arr[i]);
    }

    int result_sum = process_data(arr, size, threshold);

    printf("Result sum: %d\n", result_sum);

    printf("--Second arr--\n");
    for(int i = 0; i < size; ++i){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}	


    

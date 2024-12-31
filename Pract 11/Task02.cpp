#include <iostream>


int getSizeOfArray(const int* arr) {
    int counter = 0;
    while (*arr != '\0') {
        counter++;
        arr++;
    }
    return counter;
}
void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void countDigits(int *result, int *arr, int lenght){
    const int *currNumber = arr;
    int counter = 0;
    for (int i = 0; i < lenght; i++) {
        if (*arr == *currNumber) {
            counter++;
        }
        else{
            *result = counter;
            result++;
            currNumber = arr;
            std::cout << *arr << std::endl;
            std::cout << *currNumber << std::endl;
            counter = 1;
        }
        arr++;
    }
    *result = counter;
}
void removeRepeatingNumbers(int *arr, int size, int *newArr) {
    int* currNumber = arr;
    *newArr = *currNumber;
    for (int i = 1; i < size; i++) {
        if (*arr != *currNumber) {
            currNumber = arr;
            *newArr = *currNumber;
            newArr++;
        }
        arr++;
    }
    newArr++;
    *newArr = '\0';
}
int main()
{
    const int SIZE = 256;
    int result[SIZE];
    int arr1[SIZE] = { 1,3,4,5,6,3,3,5,6,7,2 , '\0' };
    int lenght = getSizeOfArray(arr1);
    sortArray(arr1, lenght);
    countDigits(result, arr1, lenght);
    int noRepeatArr[SIZE];
    removeRepeatingNumbers(arr1, lenght, noRepeatArr);
    int noRepeatLenght = getSizeOfArray(noRepeatArr);
    //print
    for (int i = 0; i < noRepeatLenght; i++) {
        std::cout << noRepeatArr[i] << 'x' << result[i] << std::endl;

    }
    
}


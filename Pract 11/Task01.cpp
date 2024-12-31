#include <iostream>

void combineArrays(const char *arr, char*& newArr) {
    while (*arr != '\0') {
        *newArr = *arr;
        arr++;
        newArr++;
    }
    *newArr = '\0';
}
int getSizeOfArray(const char* arr) {
    int counter = 0;
    while (*arr != '\0') {
        counter++;
        arr++;
    }
    return counter;
}
void sortArray(char *arr, int n){
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
int main()
{
    const int SIZE = 32;
    const int GRANDSIZE = 64;
    char combinedArray[GRANDSIZE];// a c d z e b y '\0
    char* currentPosition = combinedArray; 
    char arr1[SIZE] = { 'a', 'c', 'd', 'z' , '\0'};
    char arr2[SIZE] = { 'e', 'b', 'y' , '\0' };
    combineArrays(arr1, currentPosition);
    combineArrays(arr2, currentPosition);
    int lenght = getSizeOfArray(combinedArray);
    sortArray(combinedArray, lenght);
    std::cout << combinedArray;
}


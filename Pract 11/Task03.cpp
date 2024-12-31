#include <iostream>


int getSizeOfArray(const char* arr) {
    int counter = 0;
    while (*arr != '\0') {
        counter++;
        arr++;
    }
    return counter;
}
void sortArray(char* arr, int n) {
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
char compareElements(char ch, char *arr) {
    while (*arr != '\0') {
        if (ch == *arr) {
            *arr = '!';
            ch = '!';
            break;
        }
        arr++;
    }
    return ch;
}
void deleteElements(char *arr1, char *arr2) {
    while(*arr1 != '\0') {
        char ch = *arr1;
        ch = compareElements(ch, arr2);
        *arr1 = ch;
        arr1++;
    }
}
void combineArrays(const char* arr, char*& newArr) {
    while (*arr != '\0') {
        if (*arr != '!') {
            *newArr = *arr;
            newArr++;
        }
        arr++;
    }
}
   
int main() {

    const int SIZE = 256;
    char result[SIZE];

    char arr1[SIZE] = { 'e','d','w','a','v', '\0' };
    char arr2[SIZE] = { 'e','d','s', '\0' };
 

    int lenght1 = getSizeOfArray(arr1);
    int lenght2 = getSizeOfArray(arr2);
    sortArray(arr1, lenght1);
    sortArray(arr2, lenght2);

    deleteElements(arr1, arr2);

    char *currPosition = result;
    combineArrays(arr1, currPosition);
    combineArrays(arr2, currPosition);

    *currPosition = '\0';
    std::cout << result << std::endl;
    
}


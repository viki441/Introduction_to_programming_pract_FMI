#include <iostream>

void extractDigitsInPlace(char *arr) {
    char *write = arr; 
    //*write will point to the position after the last digit in the array each time 
    char *read = arr;  

    while (*read != '\0') {
        if (*read >= '0' && *read <= '9') {
            *write = *read; 
            write++;
        }
        read++;
    }
    *write = '\0';
}
int fromCharToInt(const char *arr) {
    int number = 0;
    while (*arr != '\0') {
        number = number * 10 + (*arr - '0');
        arr++;
    }
    return number;
}
int main() {
    const int SIZE = 64;

    char arr1[SIZE] = "2d!@1v40";//2140

    extractDigitsInPlace(arr1);

    int number =  fromCharToInt(arr1);

    std::cout << number << std::endl;
}


#include <iostream>

void extractDigitsInPlace(char* arr) {
    char* write = arr;
    //*write will point to the position after the last digit in the array each time 
    char* read = arr;

    while (*read != '\0') {
        if (*read >= '0' && *read <= '9') {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';
}

int main() {
    const int SIZE = 64;

    char arr1[SIZE] = { '2','d','!','@','1','v','4','0', '\0' };

    extractDigitsInPlace(arr1);

    std::cout << '"' << arr1 << '"' << std::endl;
}

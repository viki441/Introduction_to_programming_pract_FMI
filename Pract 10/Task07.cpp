#include <iostream>
using namespace std;

void toLowerCase(char* myArray) {
    while (*myArray != '\0') {
        if (*myArray >= 'A' && *myArray <= 'Z') {
            *myArray += 32;
        }
        myArray++;
    }
}

void toUpperCase(char* myArray) {
    while (*myArray != '\0') {
        if (*myArray >= 'a' && *myArray <= 'z') {
            *myArray -= 32;
        }
        myArray++;
    }
}

int main() {
    char myArray[] = { 'a', 'B', 'c', 'd', 'e', '\0' };
    toUpperCase(myArray);
    cout << myArray << endl;
    toLowerCase(myArray);
    cout << myArray << endl;
}

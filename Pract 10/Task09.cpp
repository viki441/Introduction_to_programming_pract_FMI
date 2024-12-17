#include <iostream>
using namespace std;

const char* findSmallestWord(const char* myArray, int* smallestLength) {
    const char* start = nullptr;
    const char* smallestStart = nullptr;
    int currentLength = 0;
    *smallestLength = INT_MAX;

    while (*myArray != '\0') {        
        if ((*myArray >= 'A' && *myArray <= 'Z') || (*myArray >= 'a' && *myArray <= 'z')) {
            if (start == nullptr) {
                start = myArray;
            }
            currentLength++;
        }
        else {
            if (start != nullptr) {
                if (currentLength > 0 && currentLength < *smallestLength) {
                    *smallestLength = currentLength;
                    smallestStart = start;
                }
                currentLength = 0;
                start = nullptr;
            }
        }
        myArray++;
    }

    if (start != nullptr && currentLength < *smallestLength) {
        *smallestLength = currentLength;
        smallestStart = start;
    }

    return smallestStart;
}

int main() {
    const int SIZE = 50;
    const char myArray[] = { 'a', 'B', 'c', '!', ' ', ',', 'd', 'e', ' ', 'd', '\0' };

    int smallestLength = 0;
    const char* smallestWordStart = findSmallestWord(myArray, &smallestLength);

    if (smallestWordStart) {
        cout << "The smallest word starts at: " << (void*)smallestWordStart << endl;
        cout << "The smallest word is: ";
        for (int i = 0; i < smallestLength; i++) {
            cout << smallestWordStart[i];
        }
        cout << "\nLength: " << smallestLength << endl;
    }
    else {
        cout << "No word found!" << endl;
    }
}

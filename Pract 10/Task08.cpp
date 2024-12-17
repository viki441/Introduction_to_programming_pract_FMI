#include <iostream>
using namespace std;

int countWords(const char* myArray) {
    int counter = 0;
    if (*myArray == '\0') {
        counter++;
    }
    while (*myArray != '\0') {
        if ( *myArray >= 'A' && *myArray <= 'Z' || *myArray >= 'a' && *myArray <= 'z'){
            myArray++;
            if (!(*myArray >= 'A' && *myArray <= 'Z' || *myArray >= 'a' && *myArray <= 'z')){
                counter++;
            }
            
        }
        else {
            myArray++;
        }
    }
    return counter;
}

int main() {
    const char myArray[] = { 'a', 'B', 'c', '!', ' ', ',', 'd', 'e', ' ', 'd', '\0'};
    int words = countWords(myArray);
    cout << words << endl;
}

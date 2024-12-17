#include <iostream>
using namespace std;

bool isContiguousMatch(const char* mainArray, const char* needle) {
    while (*needle != '\0') {
        if (*mainArray == '\0' || *mainArray != *needle) {
            return false;
        }
        mainArray++;
        needle++;
    }
    return true;
}

bool containsContiguous(const char* mainArray, const char* needle) {
    while (*mainArray != '\0') {
        if (isContiguousMatch(mainArray, needle)) {
            return true;
        }
        mainArray++;
    }
    return false;
}

int main() {
    const char mainArray[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
    const char arr1[] = { 'c', 'd', '\0' };
    const char arr2[] = { 'd', 'a', '\0' };   
    const char arr3[] = { 'b', 'c', 'd', '\0' }; 
    const char arr4[] = { 'e', 'a', '\0' };  

    cout << "Is 'cd' in 'abcde'? "
        << (containsContiguous(mainArray, arr1) ? "Yes" : "No") << endl;
    cout << "Is 'da' in 'abcde'? "
        << (containsContiguous(mainArray, arr2) ? "Yes" : "No") << endl;
    cout << "Is 'bcd' in 'abcde'? "
        << (containsContiguous(mainArray, arr3) ? "Yes" : "No") << endl;
    cout << "Is 'ea' in 'abcde'? "
        << (containsContiguous(mainArray, arr4) ? "Yes" : "No") << endl;
}

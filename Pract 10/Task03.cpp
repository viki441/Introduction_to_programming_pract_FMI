#include <iostream>
using namespace std;
//stigame do nulata na 1viqt, sled tova dobavqme 2riq arr
void appendCharArray(const char* source, char* combinedArrays) {
    // Move destination pointer to the end of the current string
    while (*combinedArrays != '\0') {
        combinedArrays++;
    }

    // Append each character from source to destination
    while (*source != '\0') {
        *combinedArrays = *source;
        source++;
        combinedArrays++;
    }
    *combinedArrays = '\0';
}

int main() {
    const int SIZE = 50;
    char myArr[] = { 'A', 'B', 'C', '\0' };
    char myArr2[] = { 'z', 'w', 's', '\0' };
    char combinedArrays[SIZE] = {'\0'};

    appendCharArray(myArr, combinedArrays);
    cout << "combined: " << combinedArrays << endl;

}

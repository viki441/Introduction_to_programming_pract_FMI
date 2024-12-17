#include <iostream>
using namespace std;
//stigame do nulata na 1viqt, sled tova dobavqme 2riq arr
void appendCharArray(const char* source, char* destination) {
    // Move destination pointer to the end of the current string
    while (*destination != '\0') {
        destination++;
    }

    // Append each character from source to destination
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
}

int main() {
    char myArr[] = { 'A', 'B', 'C', '\0' };
    char myArr2[50] = { 'z', 'w', 's', '\0' };
 
    appendCharArray(myArr, myArr2);

    cout << "myArr: " << myArr << endl;
    cout << "myArr2: " << myArr2 << endl;

}

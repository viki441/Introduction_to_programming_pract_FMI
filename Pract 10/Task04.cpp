#include <iostream>
using namespace std;
//stigame do nulata na 1viqt, sled tova dobavqme 2riq arr
int getLength(const char* arr) {
	int counter = 0;
	while (*arr != '\0') {
		counter++;
		arr++;
	}
	return counter;
}
int compareArrays(int* length1, int* length2) {
	return *length1 >= *length2 ? (*length1 == *length2 ? 0 : 1) : -1;
}

int main() {
	char myArr1[] = { 'A', 'B', 'C','s', '\0' };
	char myArr2[] = { 'z', 'w', 's', '\0' };

	int length1 = getLength(myArr1);
	int length2 = getLength(myArr2);
	
	cout << compareArrays(&length1, &length2) << endl;


}

#include <iostream>
using namespace std;

int charToInt(const char* myArr) {
	int number = 0;

	while (*myArr != '\0') {
		if (*myArr == '-') {
			myArr++;
			continue;
		}
		number = number * 10 + (*myArr - '0');
		myArr++;
	}
	return number;
}

int main() {
	char myArr1[] = { '1', '2', '4', '3', '\0' };
	int number = charToInt(myArr1);
	if (*myArr1 == '-') {
		number *= -1;
	}
	cout << number << endl;
}

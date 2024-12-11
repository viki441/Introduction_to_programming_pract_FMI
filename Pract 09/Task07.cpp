#include <iostream>
void makeMatrix(int myMatrix[][3], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int number;
			std::cout << "Enter a number for the matrix: " << std::endl;
			std::cin >> number;
			myMatrix[i][j] = number;
		}
	}
	std::cout << "End of current matrix input." << std::endl;
}

bool isTriangleMatrix(int matrix[][3], int rows, int cols) {
	int sum = 0;
	//we get the sum of the first row
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i > j && matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	const int ROWS1 = 3;
	const int COLS1 = 3;

	int myMatrix1[ROWS1][COLS1];

	//get matrix
	makeMatrix(myMatrix1, ROWS1, COLS1);

	bool isMagicalSquare = isTriangleMatrix(myMatrix1, ROWS1, COLS1);
	std::cout << std::boolalpha << isMagicalSquare;

}

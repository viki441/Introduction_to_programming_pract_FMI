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

bool compareRows(int sum, int cols, int matrix[][3], int rows) {
	for (int i = 1; i < rows; i++) {
		int currSum = 0;
		for (int j = 0; j < cols; j++) {
			currSum += matrix[i][j];
		}
		if (currSum != sum) {
			return false;
		}
	}
	return true;
}
bool compareCols(int sum, int cols, int matrix[][3], int rows) {
	for (int j = 0; j < cols; j++) {
		int currSum = 0;
		for (int i = 0; i < rows; i++) {
			currSum += matrix[i][j];
		}
		if (currSum != sum) {
			return false;
		}
	}
	return true;
}
bool compareDiagonals(int sum, int cols, int matrix[][3], int rows) {
	int currSum1 = 0;
	//normal diagonal
	for (int j = 0; j < cols; j++) {
		currSum1 += matrix[j][j];
	}
	//mirror diagonal
	int currSum2 = 0;
	int i = 0;
	for (int j = cols - 1; j >= 0; j--) {
		currSum2 += matrix[i][j];
		i++;

	}
	return currSum1 == sum && currSum2 == sum;
}
bool areMatrixSumsEqual(int matrix[][3], int rows, int cols) {
	int sum = 0;
	bool areEqualRows = true;
	bool areEqualCols = true;
	bool areEqualDiagonals = true;
	//we get the sum of the first row
	for (int j = 0; j < cols; j++) {
		sum += matrix[0][j];
	}
	//compare rows
	areEqualRows = compareRows(sum, cols, matrix, rows);

	//compare cols
	areEqualCols = compareCols(sum, cols, matrix, rows);

	//compare diagonals
	areEqualDiagonals = compareDiagonals(sum, cols, matrix, rows);

	return areEqualCols && areEqualRows && areEqualDiagonals;

}

int main()
{
	const int ROWS1 = 3;
	const int COLS1 = 3;

	int myMatrix1[ROWS1][COLS1];

	//get matrix
	makeMatrix(myMatrix1, ROWS1, COLS1);


	bool isMagicalSquare = areMatrixSumsEqual(myMatrix1, ROWS1, COLS1);
	std::cout << std::boolalpha << isMagicalSquare;

}

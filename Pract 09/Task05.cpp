#include <iostream>
bool isValidMultiplication(int cols, int rows){ 
    return cols == rows ? true : false;
}
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
void makeMatrix(int myMatrix[][2], int rows, int cols) {

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

//here change matrix[][*]
void getSumOfRow(int matrix1[][3], int matrix2[][3], int rows, int cols, int multipliedMatrix[][3], int counterX, int newRows, int newCols) {
    int j;
    int counterY = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (j = 0; j < newCols; j++) {
            int m1 = matrix1[counterX][j];
            int m2 = matrix2[j][i];
            sum += m1 * m2;
        }
        multipliedMatrix[counterX][counterY] = sum;
        counterY++;
    }
  
}
//here change matrix1 [][*]
void multiplyMatrixes(int multipliedMatrix[][3], int matrix1[][3], int matrix2[][3], int rows, int cols, int newRows, int newCols) {
    int counterX = 0; 
        for (int j = 0; j < cols; j++) {
            getSumOfRow(matrix1, matrix2, rows, cols, multipliedMatrix, counterX, newRows, newCols);
            counterX++;
        }

}
void displayMatrix(int myMatrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << myMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    const int ROWS1 = 3;
    const int COLS1 = 3;
    const int ROWS2 = 3;
    const int COLS2 = 3;
    int myMatrix1[ROWS1][COLS1];
    int myMatrix2[ROWS2][COLS2];
    //compare rows and cols 
    bool isValidCombination = isValidMultiplication(COLS1, ROWS2);

    if (isValidCombination) {
        //get matrix
        makeMatrix(myMatrix1, ROWS1, COLS1);
        makeMatrix(myMatrix2, ROWS2, COLS2);

        //multiply matrixes
        int multipliedMatrix[ROWS1][COLS2];
        multiplyMatrixes(multipliedMatrix, myMatrix1, myMatrix2, ROWS1, COLS2, ROWS2, COLS1 );

        //display
        displayMatrix(multipliedMatrix, ROWS1, COLS2);
    }
    else {
        std::cout << "Multiplication not possible!" << std::endl;
    }
   

}

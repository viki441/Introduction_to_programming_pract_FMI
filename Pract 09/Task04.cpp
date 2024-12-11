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

void transMatrix(int myMatrix[][3], int rows, int cols) {
    int temp = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) {
            temp = myMatrix[i][j];
            myMatrix[i][j] = myMatrix[j][i];
            myMatrix[j][i] = temp;
        }
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

bool compareMatrixes(int matrix1[][3], int matrix2[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //i-ti red j-ta kolona
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    const int ROWS = 3;
    const int COLS = 3;
    int myMatrix[ROWS][COLS];
    int transponeMatrix[ROWS][COLS];
    //get matrix
    makeMatrix(myMatrix, ROWS, COLS);
    makeMatrix(transponeMatrix, ROWS, COLS);
    //transpone
    transMatrix(transponeMatrix, ROWS, COLS);
    //check matrix
    bool areEqual = compareMatrixes(transponeMatrix, myMatrix, ROWS, COLS);
    std::cout << std::boolalpha << areEqual;
}

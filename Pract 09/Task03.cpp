#include <iostream>

void makeMatrix(int myMatrix[][3], int rows, int cols) {
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            myMatrix[i][j] = counter;
            counter++;
        }
    }
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
int main()
{
    const int ROWS = 3;
    const int COLS = 3;
    int myMatrix[ROWS][COLS];
    //get matrix
    makeMatrix(myMatrix, ROWS, COLS);
    //transpone
    transMatrix(myMatrix, ROWS, COLS);
    displayMatrix(myMatrix, ROWS, COLS);
    
}

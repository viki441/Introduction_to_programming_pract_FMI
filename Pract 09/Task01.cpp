#include <iostream>

void rowsMatrix(int myMatrix[][5], int rows, int cols) { 
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << counter << " ";
            counter++;
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int ROWS = 6;
    const int COLS = 5;
    int myMatrix[ROWS][COLS];
    rowsMatrix(myMatrix, ROWS, COLS);
}

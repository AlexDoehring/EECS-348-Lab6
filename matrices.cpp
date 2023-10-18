#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

int readFile(string filename, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]);
void printMatrix(int matrix[][MAX_SIZE], int size);
void addMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);
void multMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);
void subMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);


int main() {
    string filename = "matrix_input.txt";
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int size = readFile(filename, matrix1, matrix2);
    
    cout << "Matrix A:" << endl;
    printMatrix(matrix1, size);
    cout << "Matrix B:" << endl;
    printMatrix(matrix2, size);

    int ansMat[MAX_SIZE][MAX_SIZE];
    addMatrix(matrix1, matrix2, ansMat, size);
    cout << "A + B = " << endl;
    printMatrix(ansMat, size);

    multMatrix(matrix1, matrix2, ansMat, size);
    cout << "A * B = " << endl;
    printMatrix(ansMat, size);

    subMatrix(matrix1, matrix2, ansMat, size);
    cout << "A - B = " << endl;
    printMatrix(ansMat, size);
    
    return 0;
}

int readFile(string fileName, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]) {
    ifstream file(fileName);
    string line;
    getline(file, line);
    int size = stoi(line);
    
    for(int i = 0; i < size; i++) {
        getline(file, line);
        stringstream s(line);
        for(int j = 0; j < size; j++) {
            s >> matrix1[i][j];
        }
    }

    for(int i = 0; i < size; i++) {
        getline(file, line);
        stringstream s(line);
        for(int j = 0; j < size; j++) {
            s >> matrix2[i][j];
        }
    }

    file.close();
    return size;
}

void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void addMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            ansMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ansMat[i][j] = 0; // Initialize the result matrix element to zero
            for (int k = 0; k < size; k++) {
                ansMat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void subMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            ansMat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
#include <iostream>
#include <fstream> //included for file I/O
#include <sstream> //included for string input
#include <string> //included for string library

using namespace std; //using standard namespace

const int MAX_SIZE = 100; //Initializing global variable MAX_SIZE to 100

//Defining Function Prototypes
int readFile(string filename, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]);
void printMatrix(int matrix[][MAX_SIZE], int size);
void addMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);
void multMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);
void subMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size);

//Main code
int main() {
    //initializes file name and each matrix
    string filename = "matrix_input.txt";
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int size = readFile(filename, matrix1, matrix2); //initializes size and two matrices

    //prints each matrix
    cout << "Matrix A:" << endl;
    printMatrix(matrix1, size);
    cout << "Matrix B:" << endl;
    printMatrix(matrix2, size);

    //Adds the two matrices and prints the result
    int ansMat[MAX_SIZE][MAX_SIZE];
    addMatrix(matrix1, matrix2, ansMat, size);
    cout << "A + B = " << endl;
    printMatrix(ansMat, size);

    //Multiplies the two matrices and prints the result
    multMatrix(matrix1, matrix2, ansMat, size);
    cout << "A * B = " << endl;
    printMatrix(ansMat, size);

    //Subtracts the two matrices and prints the result
    subMatrix(matrix1, matrix2, ansMat, size);
    cout << "A - B = " << endl;
    printMatrix(ansMat, size);
    
    return 0;
}

//Takes a file and two matrices, reads from the file and initializes each matrix
int readFile(string fileName, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]) {
    ifstream file(fileName); //initializing input file stream
    string line; //initializes variable that will hold each line as a string
    getline(file, line); //reads in the size variable
    int size = stoi(line); //converts the size from a string to an int

    // loops through the file for the first matrix and initializes it
    for(int i = 0; i < size; i++) {
        getline(file, line);
        stringstream s(line); //initializes stringstream variable which makes splitting the string up easier
        for(int j = 0; j < size; j++) {
            s >> matrix1[i][j]; //takes each word from the stringstream and sets each matrix value to the respective int
        }
    }

    // loops through the file for the second matrix and initializes it
    for(int i = 0; i < size; i++) {
        getline(file, line);
        stringstream s(line); //initializes stringstream variable 
        for(int j = 0; j < size; j++) {
            s >> matrix2[i][j]; //takes each word from the stringstream and sets each matrix value to the respective int
        }
    }

    file.close(); //closes file
    return size; //returns the size
}

//takes a matrix and its size and prints the matrix with nice format
void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) { //loops through rows and columns
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << ' '; // prints the matrix element with a space
        }
        cout << endl; //prints new line for the rows
    }
    cout << endl; // ends with an extra new line
}

//takes 2 matrices and adds them into a 3rd matrix
void addMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) { //loops through the matrix
        for(int j = 0; j < size; j++) {
            ansMat[i][j] = mat1[i][j] + mat2[i][j]; // adds the two matrices and assigns it to the third matrix
        }
    }
}

//takes 2 matrices and multiplies them into a 3rd matrix
void multMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) { //loops through the matrix
        for (int j = 0; j < size; j++) {
            ansMat[i][j] = 0; // Initialize the result matrix element to zero
            for (int k = 0; k < size; k++) { //loops again
                ansMat[i][j] += mat1[i][k] * mat2[k][j]; //computes the product of each element of matrix one and two
            }
        }
    }
}

//takes 2 matrices and subtracts them into a 3rd matrix
void subMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int ansMat[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) { //loops through the matrix
        for(int j = 0; j < size; j++) {
            ansMat[i][j] = mat1[i][j] - mat2[i][j]; // subtracts the two matrices and assigns it two the third matrix
        }
    }
}

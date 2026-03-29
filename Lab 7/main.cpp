#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int SIZE = 4;
class Matrix {
private:
    int data[SIZE][SIZE];
public:
    void readFromStdin(string fileName);
    void display() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    int sumOfDiagonals() const;
    int sumOfSecondaryDiagonals() const;
    void swapRows(int row1, int row2);
    void resetMatrix();
};
void Matrix::readFromStdin(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw 100;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file >> data[i][j];
        }
    }
    file.close();
    return;
}
void fillMatrix(Matrix &matrix) {
    string matrixFile;
    while (true) {
        cout << "Enter file that stores the Matrix: ";
        cin >> matrixFile;
        try
        {
            matrix.readFromStdin(matrixFile);
            break;
        }
        catch(int e)
        {
            if (e == 100) {cout << "Invalid File, try again" << endl;}
        }
    }
    return;
}
void Matrix::display() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << data[i][j] << "  ";
        }
        cout << endl;
    }
}
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;
    result.resetMatrix();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}
int Matrix::sumOfDiagonals() const {
    int result = 0;
    for(int i = 0; i < SIZE; i++) {
        result += data[i][i];
    }
    return result;
}
int Matrix::sumOfSecondaryDiagonals() const {
    int result = 0;
    for(int i = 0; i < SIZE; i++) {
        result += data[(SIZE - 1) - i][i];
    }
    return result;
}
void Matrix::swapRows(int row1, int row2) {
    swap(data[row1], data[row2]);
}
void Matrix::resetMatrix() {
    for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] = 0;
        }
    }
}
int main() {
    Matrix mat1;
    fillMatrix(mat1);
    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    fillMatrix(mat2);
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    cout << "Sum of secondary diagonals of Matrix 1: " << mat1.sumOfSecondaryDiagonals() << endl;
    
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
    return 0;
}
#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    Matrix() {
        rows = 0;
        cols = 0;
        data = nullptr;
        cout << "Created empty matrix" << endl;
    }
    
    Matrix(int rowsCount,int colsCount) {
        if (rowsCount <= 0 || colsCount <= 0) {
            rows = 0;
            cols = 0;
            data = nullptr;
            cout << "Invalid input" << endl;
            return;
        }
        else {
            rows = rowsCount;
            cols = colsCount;
            data = new double*[rows];

            for(int i = 0; i < rows;i++) {
                data[i] = new double[cols];
                for(int j = 0;j < cols;j++) {
                    data[i][j] = 0;
                }
            }
            cout << "Created matrix" << rows << "x" << cols << endl;
        }
    }

    ~Matrix() {
        if (data != nullptr) {
            for(int i = 0;i < rows;i++) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
            cout << "Memory cleaned up" << endl;
        }
    }

    void input() {
        if(data == nullptr) {
            cout << "Matrix not created" << endl;
            return;
        }
        else {
            cout << "Enter elements of matrix" << rows << "x" << cols << endl;
            for (int i = 0;i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    cout << "Element [" << i << "][" << j << "]: ";
                    cin >> data[i][j]; 
                }
            }
        }
    }

    void print() {
        if (data == nullptr) {
            cout << "Matrix is empty" << endl;
            return;
        }
        else {
            cout << "Matrix" << rows << "x" << cols << ":" << endl;
            for (int i = 0;i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    cout << data[i][j] << "\t"; 
                }
                cout << endl;
            }  
        }
    }

    void multiplyByNumber(double number) {
        if (data == nullptr) {
            cout << "Matrix is empty" << endl;
            return;
        }
        else {
            for (int i = 0;i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    data[i][j] = data[i][j] * number;
                }
            }
            cout << "Matrix multiplied by " << number << endl; 
        }
    }
};

int main() {
    Matrix a;
    Matrix b(2,3);
    b.input();
    b.print();
    b.multiplyByNumber(2);
    b.print();
    Matrix c(3,1);
    cout << "lox";
}
//fkfdokfosjdgiojhsdihfuishuighuisehifasfafs
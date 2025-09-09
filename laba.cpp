#include <iostream>
#include <limits>
using namespace std;

class Matrix {
private:
  int rows;
  int cols;
  double **data;

  void clear() {
    if (data != nullptr) {
      for (int i = 0; i < rows; i++) {
        delete[] data[i];
      }
      delete[] data;
      data = nullptr;
    }
    rows = 0;
    cols = 0;
  }

  void copyFrom(const Matrix &other) {
    rows = other.rows;
    cols = other.cols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = other.data[i][j];
      }
    }
  }

public:
  Matrix() : rows(0), cols(0), data(nullptr) {}

  Matrix(int rowsCount, int colsCount) : rows(rowsCount), cols(colsCount) {
    if (rowsCount <= 0 || colsCount <= 0) {
      rows = 0;
      cols = 0;
      data = nullptr;
      cout << "Invalid input" << "\n";
      return;
    }

    data = new double *[rows];

    for (int i = 0; i < rows; i++) {
      data[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = 0;
      }
    }
    cout << "Created matrix " << rows << "x" << cols << "\n";
  }

  Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
    if (other.data == nullptr) {
      rows = 0;
      cols = 0;
      data = nullptr;
      cout << "Copied empty matrix" << "\n";
      return;
    }

    data = new double *[rows];

    for (int i = 0; i < rows; i++) {
      data[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = other.data[i][j];
      }
    }
    cout << "Matrix copied " << rows << "x" << cols << "\n";
  }

  ~Matrix() {
    if (data != nullptr) {
      for (int i = 0; i < rows; i++) {
        delete[] data[i];
      }
      delete[] data;
      data = nullptr;
      cout << "Memory cleaned up" << "\n";
    }
  }

  Matrix &operator=(const Matrix &other) {
    if (this != &other) {
      clear();
      copyFrom(other);
    }
    return *this;
  }

  void input() const {
    if (data == nullptr) {
      cout << "Matrix not created" << "\n";
      return;
    }

    cout << "Enter elements of matrix " << rows << "x" << cols << "\n";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
        while (!(cin >> data[i][j])) {
          cout << "Error try again ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    }
  }

  void print() const {
    if (data == nullptr) {
      cout << "Matrix is empty" << "\n";
      return;
    }

    cout << "Matrix " << rows << "x" << cols << ":" << "\n";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << data[i][j] << "\t";
      }
      cout << "\n";
    }
  }

  void multiplyByNumber(double number) const {
    if (data == nullptr) {
      cout << "Matrix is empty" << "\n";
      return;
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j] = data[i][j] * number;
      }
    }
    cout << "Matrix multiplied by " << number << "\n";
  }
};

int main() {
  Matrix aaa;
  Matrix bbb(2, 3);
  bbb.input();
  bbb.print();

  Matrix ccc = bbb;
  cout << "Copy of matrix:" << "\n";
  ccc.print();

  bbb.multiplyByNumber(2);
  cout << "Original matrix after multiplication:" << "\n";
  bbb.print();
  cout << "Copy matrix (should be unchanged):" << "\n";
  ccc.print();

  Matrix ddd(bbb);
  cout << "Another copy:" << "\n";
  ddd.print();

  Matrix emptyCopy = aaa;
  emptyCopy.print();

  return 0;
}
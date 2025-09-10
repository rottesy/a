#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

class Matrix
{
  private:
    int rows;
    int cols;
    int **data;

    void clear();
    void copyFrom(const Matrix &other);

  public:
    Matrix();
    Matrix(int rowsCount, int colsCount);
    Matrix(const Matrix &other);
    ~Matrix();
    Matrix &operator=(const Matrix &other);
    void input() const;
    void print() const;
    void multiplyByNumber(int number) const;
};

#endif 
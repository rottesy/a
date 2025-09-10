#include "Matrix.hpp"
#include <limits>

using namespace std;

void Matrix::clear()
{
    if (data != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    cols = 0;
}

void Matrix::copyFrom(const Matrix &other)
{
    rows = other.rows;
    cols = other.cols;

    data = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::Matrix() : rows(1), cols(1), data(new int*[1])
{
    data[0] = new int[1];
    data[0][0] = 0;
    cout << "Created default 1x1 matrix with zero" << "\n";
}

Matrix::Matrix(int rowsCount, int colsCount) : rows(rowsCount), cols(colsCount)
{
    if (rowsCount <= 0 || colsCount <= 0)
    {
        rows = 0;
        cols = 0;
        data = nullptr;
        cout << "Invalid input" << "\n";
        return;
    }

    data = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = 0;
        }
    }
    cout << "Created matrix " << rows << "x" << cols << "\n";
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
{
    if (data == nullptr)
    {
        rows = 0;
        cols = 0;
        data = nullptr;
        cout << "Copied empty matrix" << "\n";
        return;
    }

    data = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
    cout << "Matrix copied " << rows << "x" << cols << "\n";
}

Matrix::~Matrix()
{
    if (data != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
        cout << "Memory cleaned up" << "\n";
    }
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

void Matrix::input() const
{
    if (data == nullptr)
    {
        cout << "Matrix not created" << "\n";
        return;
    }

    cout << "Enter elements of matrix " << rows << "x" << cols << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            while (!(cin >> data[i][j]))
            {
                cout << "Error try again ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

void Matrix::print() const
{
    if (data == nullptr)
    {
        cout << "Matrix is empty" << "\n";
        return;
    }

    cout << "Matrix " << rows << "x" << cols << ":" << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Matrix::multiplyByNumber(int number) const
{
    if (data == nullptr)
    {
        cout << "Matrix is empty" << "\n";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = data[i][j] * number;
        }
    }
    cout << "Matrix multiplied by " << number << "\n";
}

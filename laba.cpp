#include <iostream>
#include <limits>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    double **data;

public:
    // Конструктор по умолчанию
    Matrix()
    {
        rows = 0;
        cols = 0;
        data = nullptr;
        cout << "Created empty matrix" << "\n";
    }

    // Параметрический конструктор
    Matrix(int rowsCount, int colsCount)
    {
        if (rowsCount <= 0 || colsCount <= 0)
        {
            rows = 0;
            cols = 0;
            data = nullptr;
            cout << "Invalid input" << "\n";
            return;
        }

        rows = rowsCount;
        cols = colsCount;
        data = new double *[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
        cout << "Created matrix " << rows << "x" << cols << "\n";
    }

    // КОНСТРУКТОР КОПИРОВАНИЯ (добавлен)
    Matrix(const Matrix& other)
    {
        if (other.data == nullptr)
        {
            // Если исходная матрица пустая
            rows = 0;
            cols = 0;
            data = nullptr;
            cout << "Copied empty matrix" << "\n";
            return;
        }

        // Копируем размеры
        rows = other.rows;
        cols = other.cols;
        
        // Выделяем новую память
        data = new double *[rows];
        
        // Копируем данные
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j]; // Глубокое копирование
            }
        }
        cout << "Matrix copied " << rows << "x" << cols << "\n";
    }

    // Деструктор
    ~Matrix()
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

    void input()
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

    void print()
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

    void multiplyByNumber(double number)
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
};

int main()
{
    // Демонстрация работы конструктора копирования
    Matrix aaa;
    Matrix bbb(2, 3);
    bbb.input();
    bbb.print();
    
    // Использование конструктора копирования
    Matrix ccc = bbb; // Вызывается конструктор копирования
    cout << "Copy of matrix:" << endl;
    ccc.print();
    
    // Изменяем оригинал - копия не должна измениться
    bbb.multiplyByNumber(2);
    cout << "Original matrix after multiplication:" << endl;
    bbb.print();
    cout << "Copy matrix (should be unchanged):" << endl;
    ccc.print();
    
    // Другой способ вызова конструктора копирования
    Matrix ddd(bbb);
    cout << "Another copy:" << endl;
    ddd.print();
    
    // Копирование пустой матрицы
    Matrix emptyCopy = aaa;
    emptyCopy.print();

    return 0;
}
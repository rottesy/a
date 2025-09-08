#include <iostream>
#include <limits>
#include <vector> // ← ДОБАВИТЬ ЭТО
using namespace std;

class Matrix
{
  private:
    int rows;
    int cols;
    vector<vector<double>> data; // ← ЗАМЕНИТЬ ТИП

  public:
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0) {
        cout << "Created empty matrix" << "\n";
    }

    // Параметризированный конструктор
    Matrix(int rowsCount, int colsCount) : rows(rowsCount), cols(colsCount) {
        if (rowsCount <= 0 || colsCount <= 0)
        {
            rows = 0;
            cols = 0;
            cout << "Invalid input" << "\n";
            return;
        }

        // Инициализация вектора - АВТОМАТИЧЕСКОЕ УПРАВЛЕНИЕ ПАМЯТЬЮ
        data = vector<vector<double>>(rows, vector<double>(cols, 0.0));
        cout << "Created matrix " << rows << "x" << cols << "\n";
    }

    // ДЕСТРУКТОР БОЛЬШЕ НЕ НУЖЕН! 
    // Вектор автоматически освободит память

    // Конструктор копирования и оператор присваивания 
    // теперь можно не писать - векторы копируются автоматически

    void input()
    {
        if (data.empty()) // ← Проверка на пустоту
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

    void print() const
    {
        if (data.empty()) // ← Проверка на пустоту
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
        if (data.empty()) // ← Проверка на пустоту
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
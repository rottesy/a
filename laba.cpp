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
    // Конструктор по умолчанию - ИСПРАВЛЕНО: список инициализации
    Matrix() : rows(0), cols(0), data(nullptr) {
        cout << "Created empty matrix" << "\n";
    }

    // Параметризированный конструктор - ИСПРАВЛЕНО: список инициализации
    Matrix(int rowsCount, int colsCount) : rows(rowsCount), cols(colsCount), data(nullptr) {
        if (rowsCount <= 0 || colsCount <= 0)
        {
            rows = 0;
            cols = 0;
            cout << "Invalid input" << "\n";
            return;
        }

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

    // ДЕСТРУКТОР - уже был реализован правильно
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

    // КОНСТРУКТОР КОПИРОВАНИЯ - ДОБАВЛЕНО (Правило трех)
    Matrix(const Matrix& other) : rows(0), cols(0), data(nullptr) {
        cout << "Copy constructor called for matrix " << other.rows << "x" << other.cols << "\n";
        
        // Если исходная матрица пустая, просто выходим
        if (other.data == nullptr) {
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
                data[i][j] = other.data[i][j]; // Глубокое копирование значений
            }
        }
    }

    // ОПЕРАТОР ПРИСВАИВАНИЯ КОПИРОВАНИЕМ - ДОБАВЛЕНО (Правило трех)
    Matrix& operator=(const Matrix& other) {
        cout << "Copy assignment operator called for matrix " << other.rows << "x" << other.cols << "\n";
        
        // Проверка на самоприсваивание: if (this == &other) return *this;
        if (this == &other) {
            return *this;
        }
        
        // 1. Очищаем текущие ресурсы
        if (data != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
        
        // 2. Сбрасываем размеры
        rows = 0;
        cols = 0;
        
        // 3. Если исходная матрица пустая, выходим
        if (other.data == nullptr) {
            return *this;
        }
        
        // 4. Копируем размеры
        rows = other.rows;
        cols = other.cols;
        
        // 5. Выделяем новую память и копируем данные
        data = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j]; // Глубокое копирование
            }
        }
        
        return *this;
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

    void print() const
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
    // Демонстрация работы
    Matrix aaa;
    Matrix bbb(2, 3);
    bbb.input();
    bbb.print();
    
    // Тестируем конструктор копирования
    Matrix ccc = bbb;
    cout << "Copied matrix ccc:" << endl;
    ccc.print();
    
    // Тестируем оператор присваивания
    Matrix ddd(1, 1);
    ddd = bbb;
    cout << "Assigned matrix ddd:" << endl;
    ddd.print();
    
    bbb.multiplyByNumber(2);
    cout << "Original bbb after multiplication:" << endl;
    bbb.print();
    cout << "Copy ccc (should be unchanged):" << endl;
    ccc.print();
}
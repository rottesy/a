#include <iostream>
#include <limits>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    double **data;

    // Вспомогательная функция для очистки памяти
    void cleanup()
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

    // Вспомогательная функция для глубокого копирования (БЕЗОПАСНАЯ)
    void deepCopy(const Matrix& other)
    {
        if (other.data == nullptr)
        {
            rows = 0;
            cols = 0;
            data = nullptr;
            return;
        }

        // Сначала сохраняем старые данные на случай самоприсваивания
        int old_rows = rows;
        int old_cols = cols;
        double** old_data = data;
        
        // Создаем новую память
        rows = other.rows;
        cols = other.cols;
        data = new double *[rows];
        
        for (int i = 0; i < rows; i++)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        
        // Теперь безопасно удаляем старые данные
        if (old_data != nullptr)
        {
            for (int i = 0; i < old_rows; i++)
            {
                delete[] old_data[i];
            }
            delete[] old_data;
        }
    }

public:
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0), data(nullptr)
    {
        cout << "Created empty matrix" << "\n";
    }

    // Параметрический конструктор
    Matrix(int rowsCount, int colsCount) : rows(0), cols(0), data(nullptr)
    {
        if (rowsCount <= 0 || colsCount <= 0)
        {
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

    // Конструктор копирования
    Matrix(const Matrix& other) : rows(0), cols(0), data(nullptr)
    {
        deepCopy(other);
        cout << "Matrix copied " << rows << "x" << cols << "\n";
    }

    // Оператор присваивания копированием (УЛУЧШЕННЫЙ)
    Matrix& operator=(const Matrix& other)
    {
        if (this == &other) // Явная проверка самоприсваивания
        {
            cout << "Self-assignment detected and handled safely" << "\n";
            return *this;
        }
        
        deepCopy(other); // Безопасное копирование
        cout << "Matrix assigned (copy) " << rows << "x" << cols << "\n";
        return *this;
    }

    // Деструктор
    ~Matrix()
    {
        cleanup();
        cout << "Memory cleaned up" << "\n";
    }

    // Остальные методы остаются без изменений...
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
    // Тестирование безопасного самоприсваивания
    Matrix test(2, 2);
    test.input();
    
    cout << "Before self-assignment:" << endl;
    test.print();
    
    // Прямое самоприсваивание
    test = test;
    
    cout << "After self-assignment:" << endl;
    test.print();
    
    // Непрямое самоприсваивание через ссылку
    Matrix& ref = test;
    test = ref;
    
    cout << "After self-assignment via reference:" << endl;
    test.print();

    return 0;
}
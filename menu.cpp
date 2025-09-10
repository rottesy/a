#include "menu.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <limits>

using namespace std;

void showConstructorsMenu() {
    cout << "\t\t\tCONSTRUCTORS MENU" << "\n";
    cout << "1. Use default constructor" << "\n";
    cout << "2. Use constructor with parameters" << "\n";
    cout << "Choose option: ";
}

void showTaskMenu() {
    cout << "\n\t\t\t\tMATRIX OPERATIONS MENU" << "\n";
    cout << "1. Enter matrix elements" << "\n";
    cout << "2. Display matrix" << "\n";
    cout << "3. Multiply matrix by number" << "\n";
    cout << "4. Create new matrix (constructors menu)" << "\n";
    cout << "0. Exit program" << "\n";
    cout << "Choose option: ";
}

void handleConstructorsMenu(Matrix& matrix) {
    int choice;
    while (true) {
        showConstructorsMenu();
        while (!(cin >> choice)) {
            cout << "Error! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                matrix = Matrix(); // Используем конструктор по умолчанию
                cout << "Default constructor used successfully!" << "\n";
                return;
            }
            case 2: {
                int rows;
                int cols;
                cout << "Enter number of rows: ";
                while (!(cin >> rows) || rows <= 0) {
                    cout << "Error! Enter positive integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter number of columns: ";
                while (!(cin >> cols) || cols <= 0) {
                    cout << "Error! Enter positive integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                matrix = Matrix(rows, cols);
                return;
            }
            default:
                cout << "Invalid choice! Please try again." << "\n";
        }
    }
}

void handleTaskMenu(Matrix& matrix) {
    int choice;
    while (true) {
        showTaskMenu();
        while (!(cin >> choice)) {
            cout << "Error! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                matrix.input();
                break;
            case 2:
                matrix.print();
                break;
            case 3: {
                int number;
                cout << "Enter number to multiply by: ";
                while (!(cin >> number)) {
                    cout << "Error! Please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                matrix.multiplyByNumber(number);
                break;
            }
            case 4:
                handleConstructorsMenu(matrix);
                break;
            case 0:
                cout << "Exiting program..." << "\n";
                return;
            default:
                cout << "Invalid choice! Please try again." << "\n";
        }
    }
}


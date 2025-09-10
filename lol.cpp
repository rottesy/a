#include "menu.hpp"

int main()
{
    Matrix matrix;
    std::cout << "=== MATRIX OPERATIONS PROGRAM ===" << "\n";
    
    handleConstructorsMenu(matrix);

    handleTaskMenu(matrix);
    return 0;
}
#include <iostream>
using namespace std;

// Функция последовательного поиска
int sequentialSearch(int data[], int count, int searchValue) {
    for (int position = 0; position < count; ++position) {
        if (data[position] == searchValue) {
            return position;  // Возвращаем позицию найденного элемента
        }
    }
    return -1;  // Элемент не обнаружен в массиве
}

// Главная функция для тестирования алгоритма
int main() {
    int numbers[] = {3, 5, 2, 7, 9, 1, 4};
    int elementCount = sizeof(numbers) / sizeof(numbers[0]);
    int valueToFind = 7;
    
    int foundPosition = sequentialSearch(numbers, elementCount, valueToFind);
    
    if (foundPosition != -1) {
        cout << "Элемент найден на позиции: " << foundPosition << endl;
    } else {
        cout << "Элемент не найден." << endl;
    }
    
    return 0;
}

#include <iostream>
using namespace std;

// Функция сортировки вставками
void insertionSort(int array[], int size) {
    int currentValue, previousIndex;
    
    // Обрабатываем элементы начиная со второго
    for (int currentIndex = 1; currentIndex < size; ++currentIndex) {
        currentValue = array[currentIndex];  // Запоминаем текущий элемент
        previousIndex = currentIndex - 1;    // Индекс предыдущего элемента
        
        // Сдвигаем элементы большие currentValue вправо
        while (previousIndex >= 0 && array[previousIndex] > currentValue) {
            array[previousIndex + 1] = array[previousIndex];  // Сдвиг элемента
            previousIndex--;
        }
        
        // Вставляем currentValue на правильную позицию
        array[previousIndex + 1] = currentValue;
    }
}

// Демонстрация работы алгоритма
int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int count = sizeof(data) / sizeof(data[0]);
    
    cout << "Исходный массив:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    
    insertionSort(data, count);
    
    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0;
}

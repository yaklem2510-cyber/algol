#include <iostream>
using namespace std;

// Функция разделения массива относительно опорного элемента
int partitionArray(int numbers[], int startIndex, int endIndex) {
    int pivotValue = numbers[endIndex];           // Выбираем последний элемент как опорный
    int smallerElementIndex = startIndex - 1;     // Индекс для элементов меньше опорного
    
    // Перемещаем элементы меньшие опорного влево
    for (int currentIndex = startIndex; currentIndex <= endIndex - 1; ++currentIndex) {
        if (numbers[currentIndex] < pivotValue) {
            smallerElementIndex++;
            swap(numbers[smallerElementIndex], numbers[currentIndex]);
        }
    }
    
    // Размещаем опорный элемент на правильную позицию
    swap(numbers[smallerElementIndex + 1], numbers[endIndex]);
    return smallerElementIndex + 1;
}

// Основная функция быстрой сортировки
void performQuickSort(int numbers[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        // Получаем индекс опорного элемента после разделения
        int pivotIndex = partitionArray(numbers, startIndex, endIndex);
        
        // Рекурсивно сортируем элементы до и после опорного
        performQuickSort(numbers, startIndex, pivotIndex - 1);
        performQuickSort(numbers, pivotIndex + 1, endIndex);
    }
}

// Демонстрационная функция
int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int elementCount = sizeof(data) / sizeof(data[0]);
    
    cout << "Исходный массив:\n";
    for (int i = 0; i < elementCount; ++i) {
        cout << data[i] << " ";
    }
    cout << "\n\n";
    
    performQuickSort(data, 0, elementCount - 1);
    
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < elementCount; ++i) {
        cout << data[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

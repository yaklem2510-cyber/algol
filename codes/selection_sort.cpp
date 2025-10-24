#include <iostream>
using namespace std;

// Функция сортировки выбором
void selectionSort(int array[], int size) {
    // Внешний цикл проходит по всем элементам кроме последнего
    for (int currentIndex = 0; currentIndex < size - 1; ++currentIndex) {
        int minValueIndex = currentIndex;  // Предполагаем, что текущий элемент минимальный
        
        // Поиск минимального элемента в оставшейся части массива
        for (int searchIndex = currentIndex + 1; searchIndex < size; ++searchIndex) {
            if (array[searchIndex] < array[minValueIndex]) {
                minValueIndex = searchIndex;  // Обновляем индекс минимального элемента
            }
        }
        
        // Обмен минимального элемента с текущим
        swap(array[currentIndex], array[minValueIndex]);
    }
}

// Основная функция для демонстрации работы алгоритма
int main() {
    int numbers[] = {64, 25, 12, 22, 11};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Исходный массив:\n";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";
    
    selectionSort(numbers, count);
    
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

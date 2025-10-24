public static int fibonacciSearch(int[] array, int target) {
    int fibPrev = 0;      // F(k-2)
    int fibCurrent = 1;   // F(k-1)
    int fibNext = fibPrev + fibCurrent;  // F(k)
    
    // Находим наименьшее число Фибоначчи, большее или равное длине массива
    while (fibNext < array.length) {
        fibPrev = fibCurrent;
        fibCurrent = fibNext;
        fibNext = fibPrev + fibCurrent;
    }
    
    int offset = -1;
    
    while (fibNext > 1) {
        // Вычисляем индекс для проверки
        int checkIndex = Math.min(offset + fibPrev, array.length - 1);
        
        if (array[checkIndex] < target) {
            // Сдвигаемся вправо
            fibNext = fibCurrent;
            fibCurrent = fibPrev;
            fibPrev = fibNext - fibCurrent;
            offset = checkIndex;
        } else if (array[checkIndex] > target) {
            // Сдвигаемся влево
            fibNext = fibPrev;
            fibCurrent = fibCurrent - fibPrev;
            fibPrev = fibNext - fibCurrent;
        } else {
            // Элемент найден
            return checkIndex;
        }
    }
    
    // Проверка последнего элемента
    if (fibCurrent != 0 && offset + 1 < array.length && array[offset + 1] == target) {
        return offset + 1;
    }
    
    return -1;  // Элемент не найден
}

public static void main(String[] args) {
    int[] sortedArray = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int searchValue = 85;
    int resultIndex = fibonacciSearch(sortedArray, searchValue);
    
    if (resultIndex != -1) {
        System.out.println("Элемент найден на позиции: " + resultIndex);
    } else {
        System.out.println("Элемент не найден");
    }
}

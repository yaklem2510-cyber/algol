def interpolation_search(sorted_array, low, high, target):
    # Проверяем корректность границ и наличие target в диапазоне
    if (low <= high and target >= sorted_array[low] and target <= sorted_array[high]):
        # Вычисляем предполагаемую позицию с помощью интерполяционной формулы
        position = low + ((high - low) * (target - sorted_array[low]) // (sorted_array[high] - sorted_array[low]))
        
        # Проверяем элемент в вычисленной позиции
        if sorted_array[position] == target:
            return position
        
        # Если искомый элемент больше, ищем в правой части
        elif sorted_array[position] < target:
            return interpolation_search(sorted_array, position + 1, high, target)
        
        # Если искомый элемент меньше, ищем в левой части
        else:
            return interpolation_search(sorted_array, low, position - 1, target)
    
    return -1  # Элемент не найден

# Демонстрация работы алгоритма
sorted_data = [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]
search_value = 18

result_index = interpolation_search(sorted_data, 0, len(sorted_data) - 1, search_value)

if result_index != -1:
    print(f"Элемент найден на позиции: {result_index}")
else:
    print("Элемент не найден")

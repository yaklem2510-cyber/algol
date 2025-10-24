def shell_sort(sequence):
    size = len(sequence)
    interval = size // 2  # Начальный интервал
    
    # Пока интервал больше нуля
    while interval > 0:
        # Сортировка вставками с заданным интервалом
        for current_index in range(interval, size):
            current_value = sequence[current_index]
            position = current_index
            
            # Сдвигаем элементы, пока не найдем правильную позицию
            while position >= interval and sequence[position - interval] > current_value:
                sequence[position] = sequence[position - interval]
                position -= interval
            
            # Вставляем текущее значение на правильную позицию
            sequence[position] = current_value
        
        interval //= 2  # Уменьшаем интервал

# Тестирование алгоритма
sample_data = [12, 34, 54, 2, 3]
print("Исходный массив:", sample_data)
shell_sort(sample_data)
print("Отсортированный массив:", sample_data)

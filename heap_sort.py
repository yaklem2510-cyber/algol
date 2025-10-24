def maintain_heap(sequence, heap_size, root_index):
    largest_index = root_index
    left_child = 2 * root_index + 1
    right_child = 2 * root_index + 2
    
    # Проверяем, существует ли левый потомок и больше ли он текущего корня
    if left_child < heap_size and sequence[root_index] < sequence[left_child]:
        largest_index = left_child
    
    # Проверяем, существует ли правый потомок и больше ли он текущего наибольшего элемента
    if right_child < heap_size and sequence[largest_index] < sequence[right_child]:
        largest_index = right_child
    
    # Если наибольший элемент не является корнем, производим обмен и рекурсивно поддерживаем кучу
    if largest_index != root_index:
        sequence[root_index], sequence[largest_index] = sequence[largest_index], sequence[root_index]
        maintain_heap(sequence, heap_size, largest_index)

def heap_sort(sequence):
    size = len(sequence)
    
    # Построение максимальной кучи (перегруппировка массива)
    for i in range(size // 2 - 1, -1, -1):
        maintain_heap(sequence, size, i)
    
    # Последовательное извлечение элементов из кучи
    for i in range(size - 1, 0, -1):
        # Перемещаем текущий корень (максимальный элемент) в конец
        sequence[i], sequence[0] = sequence[0], sequence[i]
        # Вызываем maintain_heap для уменьшенной кучи
        maintain_heap(sequence, i, 0)

# Тестирование алгоритма
sample_data = [12, 11, 13, 5, 6, 7]
print("Исходный массив:", sample_data)
heap_sort(sample_data)
print("Отсортированный массив:", sample_data)

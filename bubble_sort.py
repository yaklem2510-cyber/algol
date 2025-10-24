def bubble_sort(sequence):
    length = len(sequence)
    for pass_num in range(length):
        has_swapped = False
        for position in range(0, length - pass_num - 1):
            if sequence[position] > sequence[position + 1]:
                sequence[position], sequence[position + 1] = sequence[position + 1], sequence[position]
                has_swapped = True
        if not has_swapped:
            return

data = [64, 34, 25, 12, 22, 11, 90]
print("Исходный массив:", data)
bubble_sort(data)
print("Отсортированный массив:", data)

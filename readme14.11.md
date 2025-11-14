(Клементьев Ярослав, УИБО-10-24) Вариант 16

1. Стратегия First Fit (FF)

python
# Временная сложность: O(n²)
# Причина: Для каждого элемента (n) мы в худшем случае перебираем все существующие контейнеры (n)
    def first_fit(items, capacity):
        bins = []
        for item in items:
            placed = False
            for i in range(len(bins)):
                if bins[i] + item <= capacity:
                    bins[i] += item
                    placed = True
                    break
            if not placed:
                bins.append(item)
        return bins
    
    # Ввод данных
    capacity = int(input("Введите вместимость контейнера: "))
    items = list(map(int, input("Введите размеры предметов через пробел: ").split()))
    
    result = first_fit(items, capacity)
    print(f"Количество контейнеров: {len(result)}")
    print(f"Содержимое контейнеров: {result}")
2. Стратегия First Fit Decreasing (FFD)

python
# Временная сложность: O(n²)
# Причина: Сортировка O(n log n) + First Fit O(n²)
    def first_fit_decreasing(items, capacity):
        sorted_items = sorted(items, reverse=True)
        return first_fit(sorted_items, capacity)
    
    # Используем те же данные что и в первом примере
    result = first_fit_decreasing(items, capacity)
    print(f"Количество контейнеров (FFD): {len(result)}")
    print(f"Содержимое контейнеров: {result}")
3. Стратегия Best Fit

python
# Временная сложность: O(n²)
# Причина: Для каждого элемента (n) мы ищем лучший контейнер среди всех (n)
    def best_fit(items, capacity):
        bins = []
        for item in items:
            best_idx = -1
            min_space = capacity + 1
            for i in range(len(bins)):
                space_left = capacity - (bins[i] + item)
                if space_left >= 0 and space_left < min_space:
                    min_space = space_left
                    best_idx = i
            if best_idx != -1:
                bins[best_idx] += item
            else:
                bins.append(item)
        return bins
    
    # Используем те же данные
    result = best_fit(items, capacity)
    print(f"Количество контейнеров (Best Fit): {len(result)}")
    print(f"Содержимое контейнеров: {result}")

Все алгоритмы имеют квадратичную сложность, но на практике:

FFD часто дает лучшее решение благодаря предварительной сортировке

FF самый быстрый на практике (хотя сложность такая же)

BF старается минимизировать пустое пространство в контейнерах



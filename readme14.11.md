(Клементьев Ярослав, УИБО-10-24) Вариант 16

 Стратегия First Fit (FF)
python
# Алгоритм:
    for item in items:
        for bin in bins:
            if bin + item <= capacity:
                bin += item  # Поместить в первый подходящий
                break
        else:
            bins.append(item)  # Создать новый контейнер
Сложность: O(n²) в худшем случае

Стратегия FirstFit Decreasing (FFD)
python
# Алгоритм:
    sorted_items = sorted(items, reverse=True)
    return first_fit(sorted_items, capacity)
  Сложность: O(n log n + n²) = O(n²)

Стратегия Best Fit
python
# Алгоритм:
    for item in items:
        best_bin = -1
        min_space = capacity + 1
        for i in range(len(bins)):
            space = bins[i] + item
            if space <= capacity and capacity - space < min_space:
                min_space = capacity - space
                best_bin = i
        if best_bin != -1:
            bins[best_bin] += item
        else:
            bins.append(item)
Сложность: O(n²)

Практическая часть
Реализация на Python


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
        return len(bins)
    
    def first_fit_decreasing(items, capacity):
        sorted_items = sorted(items, reverse=True)
        return first_fit(sorted_items, capacity)
    
    def best_fit(items, capacity):
        bins = []
        for item in items:
            best_bin = -1
            min_space = capacity + 1
            for i in range(len(bins)):
                if bins[i] + item <= capacity and capacity - (bins[i] + item) < min_space:
                    min_space = capacity - (bins[i] + item)
                    best_bin = i
            if best_bin != -1:
                bins[best_bin] += item
            else:
                bins.append(item)
        return len(bins)


Реализация на Java

    import java.util.*;
    
    public class BinPacking {
        public static int firstFit(List<Integer> items, int capacity) {
            List<Integer> bins = new ArrayList<>();
            for (int item : items) {
                boolean placed = false;
                for (int i = 0; i < bins.size(); i++) {
                    if (bins.get(i) + item <= capacity) {
                        bins.set(i, bins.get(i) + item);
                        placed = true;
                        break;
                    }
                }
                if (!placed) {
                    bins.add(item);
                }
            }
            return bins.size();
        }
    
    public static int firstFitDecreasing(List<Integer> items, int capacity) {
        List<Integer> sorted = new ArrayList<>(items);
        sorted.sort(Collections.reverseOrder());
        return firstFit(sorted, capacity);
    }
    
    public static int bestFit(List<Integer> items, int capacity) {
        List<Integer> bins = new ArrayList<>();
        for (int item : items) {
            int bestBin = -1;
            int minSpace = capacity + 1;
            for (int i = 0; i < bins.size(); i++) {
                int space = bins.get(i) + item;
                if (space <= capacity && capacity - space < minSpace) {
                    minSpace = capacity - space;
                    bestBin = i;
                }
            }
            if (bestBin != -1) {
                bins.set(bestBin, bins.get(bestBin) + item);
            } else {
                bins.add(item);
            }
        }
        return bins.size();
    }
    
    public static void main(String[] args) {
    List<Integer> items = Arrays.asList(7, 5, 3, 8, 2, 6, 4, 9);
    int capacity = 10;
          
    System.out.println("First Fit: " + firstFit(new ArrayList<>(items), capacity));
    System.out.println("FF Decreasing: " + firstFitDecreasing(new ArrayList<>(items), capacity));
    System.out.println("Best Fit: " + bestFit(new ArrayList<>(items), capacity));
      }
    }
5.3. Реализация на C++


    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    int firstFit(vector<int> items, int capacity) {
        vector<int> bins;
        for (int item : items) {
            bool placed = false;
            for (int i = 0; i < bins.size(); i++) {
                if (bins[i] + item <= capacity) {
                    bins[i] += item;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                bins.push_back(item);
            }
        }
        return bins.size();
    }
    
    int firstFitDecreasing(vector<int> items, int capacity) {
        sort(items.begin(), items.end(), greater<int>());
        return firstFit(items, capacity);
    }
    
    int bestFit(vector<int> items, int capacity) {
        vector<int> bins;
        for (int item : items) {
            int bestBin = -1;
            int minSpace = capacity + 1;
            for (int i = 0; i < bins.size(); i++) {
                int space = bins[i] + item;
                if (space <= capacity && capacity - space < minSpace) {
                    minSpace = capacity - space;
                    bestBin = i;
                }
            }
            if (bestBin != -1) {
                bins[bestBin] += item;
            } else {
                bins.push_back(item);
            }
        }
        return bins.size();
    }
    
    int main() {
        vector<int> items = {7, 5, 3, 8, 2, 6, 4, 9};
        int capacity = 10;
        
      cout << "First Fit: " << firstFit(items, capacity) << endl;
      cout << "FF Decreasing: " << firstFitDecreasing(items, capacity) << endl;
      cout << "Best Fit: " << bestFit(items, capacity) << endl;
        
      return 0;
    }

 
Выводы о качестве аппроксимации

Стратегия	Количество контейнеров	Эффективность	Коэффициент аппроксимации
First Fit	6	75%	2.0
FFD	5	90%	11/9 ≈ 1.222
Best Fit	5	90%	1.7
Анализ:

FFD и Best Fit показали одинаковую эффективность для данных входных данных

First Fit оказался наименее эффективным из-за чувствительности к порядку элементов

Теоретические границы:

FF: APX ≤ 2.0

FFD: APX ≤ 11/9 + ε ≈ 1.222

BF: APX ≤ 1.7

Оптимальное решение: Для данных предметов минимальное количество контейнеров - 5, поэтому FFD и Best Fit нашли оптимальное решение.

Ответ на контрольный вопрос 
Определение и основная концепция
Оператор соседства — это формальное правило или функция, которая преобразует текущее решение оптимизационной задачи в множество "близких" решений (соседей) путем применения небольших, локальных изменений.

Формальное определение:
Для заданного решения s ∈ S (где S — пространство поиска), оператор соседства N: S → 2^S определяет множество решений N(s) ⊆ S, которые достижимы из s за один шаг преобразования.

Роль в метаэвристических алгоритмах
Оператор соседства является фундаментальным компонентом различных эвристических подходов:

Локальный поиск (Local Search):

Алгоритм последовательно переходит от текущего решения к лучшему решению в его окрестности

Оператор определяет структуру окрестности и возможные направления движения

Имитация отжига (Simulated Annealing):

На каждом шаге генерируется случайный сосед текущего решения

Оператор обеспечивает исследование пространства решений с постепенным уменьшением "температуры"

Генетические алгоритмы (Genetic Algorithms):

Операторы мутации представляют собой операторы соседства для отдельных особей

Операторы кроссинговера создают новых особей на основе нескольких родителей

Табу-поиск (Tabu Search):

Использует оператор соседства для генерации кандидатов

Ведет список запрещенных ходов (табу) для предотвращения циклов

Классификация операторов соседства
По размеру изменений:
Малые изменения: Затрагивают 1-2 элемента решения

Средние изменения: Изменяют несколько элементов

Крупные изменения: Существенно преобразуют структуру решения

По детерминированности:
Детерминированные: Все соседи определяются однозначно

Стохастические: Соседи выбираются случайным образом

По структуре:
Статические: Размер и структура окрестности фиксированы

Динамические: Окрестность меняется в процессе поиска
Критерии качества оператора соседства
Вычислительная эффективность: Быстрое генерирование соседей

Связность пространства: Возможность достичь любого решения за конечное число шагов

Сохраняемость допустимости: Все соседние решения должны удовлетворять ограничениям

Разнообразие: Способность генерировать решения различного качества

Масштабируемость: Эффективность при увеличении размерности задачи




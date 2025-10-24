import java.util.Arrays;

public class MergeSortExample {
    
    public static void performMergeSort(int[] array) {
        if (array.length > 1) {
            int middleIndex = array.length / 2;
            
            // Разделение массива на левую и правую части
            int[] leftPart = Arrays.copyOfRange(array, 0, middleIndex);
            int[] rightPart = Arrays.copyOfRange(array, middleIndex, array.length);
            
            // Рекурсивная сортировка обеих половин
            performMergeSort(leftPart);
            performMergeSort(rightPart);
            
            // Слияние отсортированных частей
            mergeArrays(array, leftPart, rightPart);
        }
    }
    
    private static void mergeArrays(int[] resultArray, int[] leftArray, int[] rightArray) {
        int leftIndex = 0, rightIndex = 0, resultIndex = 0;
        
        // Слияние элементов пока есть элементы в обоих массивах
        while (leftIndex < leftArray.length && rightIndex < rightArray.length) {
            if (leftArray[leftIndex] <= rightArray[rightIndex]) {
                resultArray[resultIndex++] = leftArray[leftIndex++];
            } else {
                resultArray[resultIndex++] = rightArray[rightIndex++];
            }
        }
        
        // Добавление оставшихся элементов из левого массива
        while (leftIndex < leftArray.length) {
            resultArray[resultIndex++] = leftArray[leftIndex++];
        }
        
        // Добавление оставшихся элементов из правого массива
        while (rightIndex < rightArray.length) {
            resultArray[resultIndex++] = rightArray[rightIndex++];
        }
    }
    
    public static void main(String[] args) {
        int[] data = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Исходный массив:");
        System.out.println(Arrays.toString(data));
        
        performMergeSort(data);
        
        System.out.println("\nОтсортированный массив:");
        System.out.println(Arrays.toString(data));
    }
}

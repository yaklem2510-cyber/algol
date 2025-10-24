public class BinarySearch {
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (array[mid] == target) {
                return mid;  // Найден элемент
            }
            
            if (target < array[mid]) {
                right = mid - 1;  // Поиск в левой половине
            } else {
                left = mid + 1;   // Поиск в правой половине
            }
        }
        return -1;  // Элемент не найден
    }
    
    public static void main(String[] args) {
        int[] sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int target = 7;
        
        int result = binarySearch(sortedArray, target);
        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}


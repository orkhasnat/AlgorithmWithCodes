public class InsertionSort {
    public static void sort(int arr[]) {
        for(int i = 1; i < arr.length; i++) {
            int key = arr[i], j = i-1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}

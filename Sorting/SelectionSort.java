import java.util.*;

public class SelectionSort {

    public static void sort(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            int mn = i;
            for(int j = i+1; j < arr.length; j++) {
                if(arr[i] > arr[j]) {
                    mn = j;
                }
            }

            if(mn != i) {
                int temp = arr[i];
                arr[i] = arr[mn];
                arr[mn] = temp;
            }

        }
    }
}

// 4 3 2 1

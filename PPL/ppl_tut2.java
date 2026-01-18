/*
    Vishwesh Bhilare
    B24CE1003
    PPL Assignment 2
*/
import java.util.*;

class numOperations {

    private int arr[] = {4, 5, 1, 5, 2, 6, 7, 0, 9, 4};
    private int max, min;

    /*
    Scanner sc = new Scanner(System.in);

    public void setArray() {
        for (int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }
    }
    */

    public void getArray() {
        for (int i = 0; i < 10; i++) {
            System.out.println(arr[i]);
        }
    }

    public void sortArray() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (i != j && arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        max = arr[9];
        min = arr[0];
    }

    public void getMissing() {
        boolean flag = false;
        // int i = 0;

        for (int i = 1; i < 10; i++) {
            if (arr[i] == arr[i - 1] || (arr[i] == arr[i - 1] + 1)) {
                continue;
            } else {
                System.out.println("Missing no. found: " + (arr[i] - 1));
                flag = true;
            }
        }
    }

    public void MinMax() {
        System.out.println("Min.: " + min + " | Max.: " + max);
    }

    public void getSumPair(int target) {
        boolean found = false;

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) { // avoids duplicate pairs
                if (arr[i] + arr[j] == target) {
                    System.out.println(
                        "Sum pair found: (" + arr[i] + ", " + arr[j] + ")"
                    );
                    found = true;
                }
            }
        }

        if (!found) {
            System.out.println("No pair found with sum = " + target);
        }
    }
}

class Main {

    public static void main(String[] args) {

        numOperations obj = new numOperations();

        // obj.setArray();
        obj.getArray();

        obj.sortArray();

        System.out.println();
        System.out.println("Sorted array: ");
        obj.getArray();

        System.out.println();
        obj.getMissing();

        System.out.println();
        obj.MinMax();

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter target sum: ");
        int target = sc.nextInt();

        obj.getSumPair(target);
    }
}

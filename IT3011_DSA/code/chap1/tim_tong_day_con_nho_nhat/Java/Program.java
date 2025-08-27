import java.util.Scanner;


public class Program {
    public static int bruteForce(int[] arr, int n){
        int maxSum = arr[0];
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += arr[j];
                if (sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }

    public static int maxLeft(int[] arr, int low, int high){
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;
        for (int k=high; k>=low; k--){
            currentSum += arr[k];
            maxSum = Math.max(currentSum, maxSum);
        }
        return maxSum;
    }
    public static int maxRight(int[] arr, int low, int high){
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;
        for (int k=low; k<=high; k++){
            currentSum += arr[k];
            maxSum = Math.max(currentSum, maxSum);
        }
        return maxSum;
    }

    public static int divideAndConquer(int[] arr, int low, int high){
        if (low == high) return arr[low];
        else {
            int mid = (low+high)/2;
            int wL = divideAndConquer(arr, low, mid);
            int wR = divideAndConquer(arr, mid + 1, high);
            int wM = maxLeft(arr, low, mid) + maxRight(arr, mid + 1, high);
            return Math.max(wL, Math.max(wR, wM));
        }
    }

    public static int dynamicProgramming(int[] arr, int n){
        int smax = arr[0];
        int ei = arr[0];
        for (int i=1; i<n; i++){
            ei = Math.max(arr[i], ei + arr[i]);
            smax = Math.max(smax, ei);
        }
        return smax;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        // System.out.println(bruteForce(arr, n));
        // System.out.println(divideAndConquer(arr, 0, n-1));
        System.out.println(dynamicProgramming(arr, n));
        sc.close();
    }
}

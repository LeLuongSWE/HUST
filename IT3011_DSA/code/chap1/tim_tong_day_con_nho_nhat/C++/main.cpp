#include <iostream>
#include <climits>
#include <chrono>

using namespace std;

void brute_force(int arr[], int n)
{

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << maxSum << endl;
}

void improved_brute_force(int arr[], int n)
{
    int maxSum = arr[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << maxSum << endl;
}

int max_left(int arr[], int low, int high){
    int max_sum = INT_MIN;
    int sum = 0;
    for (int k=high; k>=low; k--){
        sum += arr[k];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}


int max_right(int arr[], int low, int high){
    int max_sum = INT_MIN;
    int sum = 0;
    for (int k=low; k<=high; k++){
        sum += arr[k];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int divide_and_conquer(int arr[], int low, int high){
    if (low == high) return arr[low];
    else {
        int mid = (low + high) / 2;
        int wL = divide_and_conquer(arr, low, mid);
        int wR = divide_and_conquer(arr, mid + 1, high);
        int wM = max_left(arr, low, mid) + max_right(arr, mid+1, high);
        return max(max(wL, wR), wM);
    }
}

int dynamic_programming(int arr[], int n){
    int smax = arr[0];
    int ei = arr[0];
    for (int i=1; i<n;i++){
        // int u = ei + arr[i];
        // int v = arr[i];
        // if (u > v) ei = u;
        // else ei = v;
        // if (ei >smax) {
        //     smax = ei;
        //     imax = i;
        // }
        ei = max(arr[i], ei + arr[i]);
        smax = max(smax, ei);
    }
    return smax;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }
    // cout << caculate_execution_time(brute_force, arr, n);
    // brute_force(arr, n);
    // improved_brute_force(arr, n);
    // cout << divide_and_conquer(arr, 0, n-1);
    cout << dynamic_programming(arr, n);
    return 0;
}
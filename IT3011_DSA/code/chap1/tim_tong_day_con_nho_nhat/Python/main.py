import sys


def brute_force(arr, n):
    max_sum = - sys.maxsize - 1
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += arr[j]
            if (current_sum > max_sum):
                max_sum = current_sum

    return max_sum

def max_left(arr, low, high):
    max_sum = - sys.maxsize - 1
    current_sum = 0
    for k in range(high, low - 1, -1):
        current_sum += arr[k]
        max_sum = max(max_sum, current_sum)
    return max_sum

def max_right(arr, low, high):
    max_sum = - sys.maxsize - 1
    current_sum = 0
    for k in range(low, high + 1):
        current_sum += arr[k]
        max_sum = max(max_sum, current_sum)
    return max_sum

def divide_and_conquer(arr, low, high):
    if (low == high):
        return arr[low]
    else:
        mid = (low + high) // 2
        wl = divide_and_conquer(arr, low, mid)
        wR = divide_and_conquer(arr, mid + 1, high)
        wM = max_left(arr, low, mid) + max_right(arr, mid + 1, high)
        return max(wl, wR, wM)

def dynamic_programming(arr, n):
    smax = arr[0]
    ei = arr[0]
    for i in range(1, n):
        ei = max(arr[i], ei + arr[i])
        smax = max(smax, ei)
    return smax

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().split()))
    # print(brute_force(arr, n))
    # print(divide_and_conquer(arr, 0, n-1))
    print(dynamic_programming(arr, n))

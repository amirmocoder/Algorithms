def find_min_max(arr, low, high):
    # Base case: if array contains only one element
    if low == high:
        return arr[low], arr[low]

    # Base case: if array contains only two elements
    if high == low + 1:
        return (arr[low], arr[high]) if arr[low] < arr[high] else (arr[high], arr[low])

    # Divide the array into two halves and recursively find min and max in each half
    mid = (low + high) // 2
    min1, max1 = find_min_max(arr, low, mid)
    min2, max2 = find_min_max(arr, mid + 1, high)

    # Combine results of two halves
    return min(min1, min2), max(max1, max2)

# Example usage
arr = [3, 5, 2, 7, 9, 8]
n = len(arr)
min_val, max_val = find_min_max(arr, 0, n - 1)
print("Minimum element is:", min_val)
print("Maximum element is:", max_val)
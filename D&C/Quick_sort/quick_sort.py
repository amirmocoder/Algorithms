def quick_sort(sequence: list):
    length = len(sequence)
    if length <= 1:
        return sequence
    else:
        pivot = sequence.pop()
         
    items_greator = []
    items_lower = []
    
    for item in sequence:
        if item > pivot:
            items_greator.append(item)
        else:
            items_lower.append(item)
    
    return quick_sort(items_lower) + [pivot] + quick_sort(items_greator)

print(quick_sort([3,3,1,2,7,5]))
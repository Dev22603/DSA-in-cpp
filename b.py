def calculate_total_distance(good_string, name):
    # ASCII range is from 32 to 126
    ASCII_MIN = 32
    ASCII_MAX = 126

    # Initialize a list to store the nearest good letter for each ASCII value
    closest_good = [-1] * (ASCII_MAX + 1)

    # Create a sorted list of ASCII values for the characters in the good string
    good_chars = sorted(ord(ch) for ch in good_string)

    # Precompute the closest good character for each possible ASCII value
    for i in range(ASCII_MIN, ASCII_MAX + 1):
        # Binary search to find the closest good character
        pos = binary_search_closest(good_chars, i)
        closest_good[i] = good_chars[pos]

    total_distance = 0
    prev_good_char = ord(good_string[0])  # Start with the first character of the good string

    # Now, calculate the total distance for the name
    for ch in name:
        if ord(ch) >= ASCII_MIN and ord(ch) <= ASCII_MAX:
            current_char = ord(ch)
            if current_char in good_chars:
                # If the current character is already a good character, no need to change it
                continue
            else:
                # Get the nearest good character from the precomputed list
                nearest_good_char = closest_good[current_char]
                total_distance += abs(prev_good_char - nearest_good_char)
                prev_good_char = nearest_good_char

    return total_distance


def binary_search_closest(arr, target):
    """
    Perform binary search to find the closest element to the target in the sorted array arr.
    """
    low, high = 0, len(arr) - 1
    if target <= arr[low]:
        return low
    if target >= arr[high]:
        return high
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    # Check which of arr[low] or arr[high] is closer to the target
    if abs(arr[low] - target) < abs(arr[high] - target):
        return low
    else:
        return high


# Example Usage
good_string = input().strip()
name = input().strip()
result = calculate_total_distance(good_string, name)
print(result)

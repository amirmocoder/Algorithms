import numpy as np

def optimal_bst(keys, freq):
    n = len(keys)
    dp = np.zeros((n+1, n+1))
    root = np.zeros((n+1, n+1), dtype=int)

    for i in range(n):
        dp[i][i+1] = freq[i]
        root[i][i+1] = i + 1
        
    for length in range(2, n+1): 
        for i in range(n-length+1):
            j = i + length
            dp[i][j] = float('inf')
            total_freq = sum(freq[i:j])
            for r in range(i, j):
                cost = dp[i][r-1] + dp[r][j] + total_freq
                if cost < dp[i][j] :
                    dp[i][j] = cost
                    root[i][j] = r

    return dp, root

# Example usage:
keys = [4,6,9]
freq = [0.7,0.2,0.1]
cost, root = optimal_bst(keys, freq)

print("Cost matrix:")
print(cost)

print("\nRoot matrix:")
print(root)
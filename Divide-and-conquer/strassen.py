import numpy as np

def strassen(m1, m2):
    size = len(m1)

    if size == 1:
        return m1 * m2

    h_size = size // 2

    A11 = m1[:h_size, :h_size]
    A12 = m1[:h_size, h_size:]
    A21 = m1[h_size:, :h_size]
    A22 = m1[h_size:, h_size:]

    B11 = m2[:h_size, :h_size]
    B12 = m2[:h_size, h_size:]
    B21 = m2[h_size:, :h_size]
    B22 = m2[h_size:, h_size:]

    P1 = strassen(A11 + A22, B11 + B22)
    P2 = strassen(A21 + A22, B11)
    P3 = strassen(A11, B12 - B22)
    P4 = strassen(A22, B21 - B11)
    P5 = strassen(A11 + A12, B22)
    P6 = strassen(A21 - A11, B11 + B12)
    P7 = strassen(A12 - A22, B21 + B22)

    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7
    
    result = np.vstack((np.hstack((C11,C12)),np.hstack((C21, C22)))) 
    
    return result
import numpy

# divide and conquer form
def f(n,k):
    if (k ==0) or (k==n):
        return 1
    else:
        return f(n-1,k) + f(n-1,k-1)

# dynamic form
def bin(n,k):
    b = numpy.zeros((n,k))
    for i in range(n):
        for j in range(0,min(i,k)):
            if (j==0) or (i==j):
                b[i,j] = 1
            else:
                b[i,j] = b[i-1,j] + b[i-1,j-1]
    return b
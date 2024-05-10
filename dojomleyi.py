from datetime import datetime
import numpy
# محاسبه دوجمله ای با تقسیم و غلبه
def f(n,k):
    if (k ==0) or (k==n):
        return 1
    else:
        return f(n-1,k) + f(n-1,k-1)
# محاسبه دوجمله ای با برنامه نویسی پویا
def bin(n,k):
    b = numpy.zeros((n,k))
    for i in range(n):
        for j in range(0,min(i,k)):
            if (j==0) or (i==j):
                b[i,j] = 1
            else:
                b[i,j] = b[i-1,j] + b[i-1,j-1]
     return b
                 
t0 = datetime.now()

# use first function

t1 = datetime.now()

# use second function

t2 = datetime.now()

print(f'runing time first function: {t1-t0}')
print(f'runing time second function: {t2-t1}')
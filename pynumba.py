import random as rnd
from datetime import datetime
from numba import jit

@jit
def monte():
    sum = 0
    n = 10**9
    for i  in range(0, n):
        if ((rnd.random()-1)**2 + (rnd.random()-1)**2) <= 1:
            sum += 1
    return 4 * sum / n   

start = datetime.now()
pi = monte()
stop = datetime.now()
print(pi, 'Time:', stop - start)     
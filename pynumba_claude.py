# https://claude.ai/chat/64b59ff7-a1e8-42d7-b3ae-19e083381022
import numpy as np
from datetime import datetime
from numba import jit, prange

@jit(nopython=True, parallel=True, nogil=True)
def monte():
    sum = 0
    n = 10**11
    # Используем np.random вместо rnd.random, так как Numba его оптимизирует
    for i in prange(n):  # prange вместо range для параллельного выполнения
        x = np.random.random()
        y = np.random.random()
        if ((x-1)**2 + (y-1)**2) <= 1:  
            sum += 1
    return 4 * sum / n

start = datetime.now()
pi = monte()
stop = datetime.now()
print(pi, 'Time:', stop - start)

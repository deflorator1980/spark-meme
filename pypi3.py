import random as rnd
from datetime import datetime
sum = 0
n = 10**9
start = datetime.now()
for i  in range(0, n):
    if ((rnd.random()-1)**2 + (rnd.random()-1)**2) <= 1:
        sum += 1
pi = 4 * sum / n   
stop = datetime.now()
print(pi, 'Time:', stop - start)     
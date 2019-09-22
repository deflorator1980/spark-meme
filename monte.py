from numpy import random,sqrt,pi
from datetime import datetime

n = 10**9

start = datetime.now()
p = random.rand(n,2)
idx = sqrt(p[:,0]**2 + p[:,1]**2) < 1
pi = sum(idx).astype('double')/n * 4
stop = datetime.now()
print(pi, 'Time:', stop - start)


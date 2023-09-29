import numpy as np
from datetime import datetime

n = 10**9

start = datetime.now()
p = np.random.rand(n, 2)
idx = np.sqrt(p[:, 0]**2 + p[:, 1]**2) < 1
pi = np.sum(idx).astype('double') / n * 4
stop = datetime.now()
print(pi, 'Time:', stop - start)

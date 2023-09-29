import numpy as np
from datetime import datetime

n: int = 10**9

start: datetime = datetime.now()
p: np.ndarray[np.float64] = np.random.rand(n, 2)
idx: np.ndarray[bool] = np.sqrt(p[:, 0]**2 + p[:, 1]**2) < 1
pi: float = float(np.sum(idx).astype('double')) / n * 4
stop: datetime = datetime.now()
print(pi, 'Time:', stop - start)

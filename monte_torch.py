import torch
from datetime import datetime

print(torch.cuda.is_available())

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
# device = torch.device('cpu')

print(device)

n = 10**9

start = datetime.now()

# Create a tensor of random numbers with shape (n, 2)
p = torch.rand(n, 2).to(device)

# Calculate the distance to the origin
idx = torch.norm(p, dim=1).to(device) < 1.0

# Calculate the estimate of pi
pi = torch.sum(idx, dtype=torch.float64).to(device) / n * 4.0

stop = datetime.now()

# Print the estimate of pi and the time taken to calculate it
print(pi.item(), 'Time:', stop - start)


# In[ ]:





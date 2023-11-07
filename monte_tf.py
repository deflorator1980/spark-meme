import tensorflow as tf
from datetime import datetime

# import os
# os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

print(tf.config.list_physical_devices('GPU'))
print(tf.sysconfig.get_build_info())

n = 10**9

start = datetime.now()

# Create a tensor of random numbers with shape (n, 2)
p = tf.random.uniform([n, 2])

# Calculate the distance to the origin
idx = tf.norm(p, axis=1) < 1

# Calculate the estimate of pi
pi = tf.reduce_sum(tf.cast(idx, tf.float64)) / n * 4.0

stop = datetime.now()

# Print the estimate of pi and the time taken to calculate it
print(pi, 'Time:', stop - start)

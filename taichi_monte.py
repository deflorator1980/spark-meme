import taichi as ti
from datetime import datetime

# Инициализация Taichi (выберите ti.cpu для CPU или ti.gpu для GPU)
ti.init(arch=ti.gpu)  # Используем GPU, если доступно

# Параметры
n = 10**9
sum_inside = ti.field(dtype=ti.i64, shape=())  # Для хранения суммы

@ti.kernel
def monte_taichi(n: ti.i64):
    sum_local = 0
    for i in range(n):
        x = ti.random()
        y = ti.random()
        if (x - 1.0)**2 + (y - 1.0)**2 <= 1.0:
            sum_local += 1
    sum_inside[None] = sum_local

start = datetime.now()
sum_inside[None] = 0  # Инициализация
monte_taichi(n)
pi = 4 * sum_inside[None] / n
stop = datetime.now()

print(pi, 'Time:', stop - start)

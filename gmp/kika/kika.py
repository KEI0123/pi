import math
a = p = 1
b = 1 / math.sqrt(2)
t = 0.25
for n in range(5):
    pi = (a + b) ** 2 / (4 * t)
    print(f"n = {n}: π = {pi}")
    next_a = (a + b) / 2
    b = math.sqrt(a * b)
    t -= p * (a - next_a)**2
    p *= 2
    a = next_a


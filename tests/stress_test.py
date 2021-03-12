import string
import random

with open("test_stress.txt", "w") as f:
    for _ in range(104857600):
        f.write(random.choice(string.ascii_letters + string.digits))

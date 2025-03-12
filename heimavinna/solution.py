import time

count = 0

for portion in input().split(";"):
    if "-" in portion:
        lr = portion.split("-")
        left = int(lr[0])
        right = int(lr[1])
        count += right-left+1
    else:
        count += 1

print(count)
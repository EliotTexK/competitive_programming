N, B, R = [int(x) for x in input().split()]

blue = []
red = []

for _ in B:
    x, y = [int(x) for x in input().split()]
    blue.append((x,y))

for _ in R:
    x, y = [int(x) for x in input().split()]
    red.append((x,y))


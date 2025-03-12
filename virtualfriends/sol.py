cases = int(input())

for _ in cases:
    sizes = set()
    graph = dict()

    F = int(input())
    for __ in F:
        lst = [x for x in input().split()]
        while True:

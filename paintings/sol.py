T = int(input())

for _ in range(T):
    N=input()
    adj_list = dict()
    color_order = dict()
    c_list = []
    for i,color in enumerate(input().split()):
        adj_list[color] = []
        c_list.append(color)
        color_order[color] = i
    M = int(input())
    banned = set()
    for _ in range(M):
        banned.add(tuple(input().split()))
    for i,c1 in enumerate(c_list):
        for c2 in c_list[i:]:
            if (c1,c2) in banned or (c2,c1) in banned or c1==c2:
                pass
            else:
                adj_list[c1].append(c2)
                adj_list[c2].append(c1)

    for c in color_list:
        stack = [()]
        while len(stack) > 0:
            c, traversed = 
            for nbr in adj_list[c]:
            
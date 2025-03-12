N = int(input())

x = int(input())

y = int(input())

L = [int(i) for i in input().split()]

L.sort()

sum = 0
ret = 0

for l in L:
    sum += x*l
    if sum/(ret+1) > y:
        break
    ret += 1
    

print(ret)
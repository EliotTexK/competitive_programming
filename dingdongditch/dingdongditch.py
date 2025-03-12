idontcare,A,B = input(), sorted(list(map(int, input().split()))), list(map(int, input().split()))

s = 0
for a in range(len(A)):
    s += A[a]
    A[a] = s

for j in B:
    print(A[j-1])
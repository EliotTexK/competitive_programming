N, T = map(int, input().split())
A, B, C, t_0 = map(int, input().split())

problems = []

time = t_0
for n in range(N):
    time = (((A * time) + B) % C) + 1
    problems.append(time)

problems.sort()

sum_t = 0
for i, p in enumerate(problems):
    if sum_t + p > T:
        print(i, sum_t % 1000000007)
    else:
        sum_t += p

print(N, sum_t % 1000000007)
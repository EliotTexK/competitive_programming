import heapq

class Coworker(object):
    def __init__(self, a, d):
        self.a = a
        self.d = d
    def __lt__(self, other):
        return self.a+self.d < other.a+other.d

h, c = map(int, input().split())

coworkers = []

for x in range(c):
    a,d = map(int, input().split())
    coworkers.append(Coworker(a,d))

heapq.heapify(coworkers)

while h > 0:
    chump = heapq.heappop(coworkers)
    chump.a += chump.d
    heapq.heappush(coworkers,chump)
    h -= 1

largest = 0
for cw in coworkers:
    largest = max(largest,cw.a)

print(largest)